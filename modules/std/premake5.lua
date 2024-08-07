std_projet_name = "Std"

function std_project_exports()
	filter {}
		includedirs { modules_folder .. "std/include" }
		links { std_projet_name }
end

function declare_std_project()
	project (std_projet_name)
		kind "SharedLib"
		language "c"
		location (modules_folder .. "std")
		includedirs { modules_folder .. "std/include" }
		files { modules_folder .. "std/src/**.c" }
end

