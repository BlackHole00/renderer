################################################################################
# SANITY CHECKS
################################################################################
if [ -z ${OUTPUT_FILE+x} ];      then echo "Parameter OUTPUT_FILE is undefined";      exit -1; fi
if [ -z ${TYPE+x} ];             then echo "Parameter TYPE is undefined";             exit -1; fi
if [ -z ${BUILD_FOLDER+x} ];     then echo "Parameter BUILD_FOLDER is undefined";     exit -1; fi

if [ -z ${CC+x} ]; then echo "Parameter CC is undefined"; exit -1; fi
if [ -z ${AR+x} ]; then echo "Parameter AR is undefined"; exit -1; fi

if [[ ! $TYPE =~ ^(executable|static|shared|interface)$ ]]; then
	echo "Invalid project type"
	exit -1
fi

################################################################################
# FOLDER CHECKS
################################################################################
if [ ! -d $BUILD_FOLDER ]; then
	mkdir $BUILD_FOLDER
fi
if [ ! -d $BUILD_FOLDER/.objs ]; then
	mkdir $BUILD_FOLDER/.objs
fi
if [ ! -d $BUILD_FOLDER/.hashs ]; then
	mkdir $BUILD_FOLDER/.hashs
fi


################################################################################
# CLEANUP
################################################################################
if [ "$1" = "clean" ]; then
	echo "Removing temporary files..."

	rm -f $BUILD_FOLDER/.hashs/*
	rm -f $BUILD_FOLDER/.objs/*
	rm -f $BUILD_FOLDER/*

	echo "All clean!"
	printf "\n"
fi

################################################################################
# DEPENDENCY RESOLUTION
################################################################################
echo "Resolving dependencies..."
for dependency in "${DEPENDENCIES[@]}"; do
	for script in $(find $dependency -name 'resolve_dependency.sh'); do
		bash_command="cd ${script%/*}; ./${script##*/} $1"
		if [ -z ${BUILDER_PATH+x} ]; then
			bash_command="export BUILDER_PATH=$(pwd)/; $bash_command"
		else
			bash_command="export BUILDER_PATH=$BUILDER_PATH; $bash_command"
		fi
		bash -c "$bash_command"
		if [ $? -ne 0 ]; then
			echo "Resolution of dependency $dependency failed"
			exit -1
		fi
	done
done
if [ "$1" = "clean" ]; then
	exit 0
fi

################################################################################
# OBJECTS COMPILATION
################################################################################
printf "\n"
echo "Building..."
for source in $(find $SOURCE_FOLDER -name '*.c'); do
	hash=$(md5 $source)
	hash_file=$BUILD_FOLDER/.hashs/${source//\//_}.md5
	if [ -f $hash_file ]; then
		if [[ $(< $hash_file) = $hash ]]; then
			continue
		fi
	fi

	compile_command="$CC -c $source -o $BUILD_FOLDER/.objs/${source//\//_}.o $EXTRA_BUILD_ARGS"
	for include in "${INCLUDE_FOLDERS[@]}"; do
		compile_command="$compile_command -I$include"
	done

	echo "$compile_command"
	eval "$compile_command"
	if [ $? -ne 0 ]; then
		echo "Building failed for file $source"
		exit -1
	fi

	echo $hash > $hash_file
done

################################################################################
# LINKING
################################################################################
case $TYPE in
	executable)
		printf "\n"
		echo "Linking..."

		link_command="$CC -o $BUILD_FOLDER/$OUTPUT_FILE $(echo $(find $BUILD_FOLDER/.objs -name '*.o')) $EXTRA_LINK_ARGS"
		for folder in "${LIBRARY_FOLDERS[@]}"; do
			link_command="$link_command -L$folder"
		done
		for library in "${LIBRARIES[@]}"; do
			link_command="$link_command -l$library"
		done

		echo "$link_command"
		eval "$link_command"
		if [ $? -ne 0 ]; then
			echo "Linking failed"
			exit -1
		fi;;
	static)
		printf "\n"
		echo "Archiving..."

		ar_command="$AR -r $BUILD_FOLDER/$OUTPUT_FILE $(echo $(find $BUILD_FOLDER/.objs -name '*.o'))"

		echo "$ar_command"
		eval "$ar_command"
		if [ $? -ne 0 ]; then
			echo "Archiving failed"
			exit -1
		fi;;
	shared)
		printf "\n"
		echo "Linking..."

		link_command="$CC -shared -o $BUILD_FOLDER/$OUTPUT_FILE $(echo $(find $BUILD_FOLDER/.objs -name '*.o')) $EXTRA_LINK_ARGS"
		for folder in "${LIBRARY_FOLDERS[@]}"; do
			link_command="$link_command -L$folder"
		done
		for library in "${LIBRARIES[@]}"; do
			link_command="$link_command -l$library"
		done

		echo "$link_command"
		eval "\"$link_command\""
		if [ $? -ne 0 ]; then
			echo "Linking failed"
			exit -1
		fi;;
	interface);;
esac

printf "\n"
echo "Compilation Successfull!"

################################################################################
# TESTING
################################################################################
if [ "$TYPE" == "executable" -a "$1" == "run" ]; then
	printf "\n"
	echo "Running Execuitable..."
	$BUILD_FOLDER/$OUTPUT_FILE
fi
