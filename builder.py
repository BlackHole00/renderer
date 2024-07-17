#!/usr/bin/python3
import sys
import os
import logging
import configparser
import platform
import pathlib
import subprocess
import hashlib
import asyncio

CONFIG_TARGET = 'project.ini'
OPERATION = ''
OPT_LEVEL = ''
CWD = os.getcwd()
VERSION = '1.0.0'

logging.basicConfig(format='[%(levelname)s] : %(message)s')

logger = logging.getLogger('Builder')
logger.setLevel(logging.DEBUG)

################################################################################
# SANITY_CHECKS
################################################################################
arguments_count = len(sys.argv)
if arguments_count > 3:
    logger.critical('Invalid argument count. Expected at most two arguments'); sys.exit(-1)

OPERATION = sys.argv[1] if arguments_count >= 2 else 'build'
if not OPERATION in [ 'build', 'run', 'clean', 'priv_resolve_dependency' ]:
    logger.critical('Invalid operation specified. Expected "build", "run" or "clean". Found "%s"' % OPERATION); sys.exit(-1)

OPT_LEVEL = sys.argv[2] if arguments_count >= 3 else 'debug'
if not OPT_LEVEL in [ 'debug', 'release' ]:
    logger.critical('Invalid target type specified. Expected "debug" or "release". Found "%s"' % OPT_LEVEL); sys.exit(-1)
    
if not os.path.isfile(CONFIG_TARGET):
    logger.critical('Could not find the project in this directory. Please insert a "%s" file' % CONFIG_TARGET); sys.exit(-1)

architecture = platform.machine().lower()
if architecture == 'x86_64': architecture = 'amd64'

################################################################################
# BANNER
################################################################################
# TODO(Vicix): Implement a better private mode
if not OPERATION in ['priv_resolve_dependency', 'clean' ]:
    logger.info('Welcome to builder!')
    logger.info('\tUsing version: 1.0.0')
    logger.info('\tRunning on OS: %s' % platform.system().lower())
    logger.info('\tRunning on architecture: %s' % architecture)
    logger.info('\tRunning task: %s %s' % (OPERATION, OPT_LEVEL))
    logger.info('\tCompiling for: %s-%s-%s' % (platform.system().lower(), architecture, OPT_LEVEL))

################################################################################
# CONFIGURATION READING
################################################################################
logger.info('Reading configuration of project from "%s/%s":' % (CWD, CONFIG_TARGET))

config = configparser.ConfigParser()
config.read(CONFIG_TARGET)

# TODO(Vicix): Make a better system to mix and match sections
sections_to_check = [ 
    'project',
    platform.system().lower(),
    architecture,
    '%s-%s' % (platform.system().lower(), architecture),
]

if OPT_LEVEL == 'release':
    sections_to_check.append('release')
    sections_to_check.append(platform.system().lower() + '-release'),
    sections_to_check.append(architecture + '-release'),
    sections_to_check.append('%s-%s-release' % (platform.system().lower(), architecture))
else:
    sections_to_check.append('debug')
    sections_to_check.append(platform.system().lower() + '-debug'),
    sections_to_check.append(architecture + '-debug'),
    sections_to_check.append('%s-%s-debug' % (platform.system().lower(), architecture))

if not config.has_section(sections_to_check[0]):
    logger.critical('The configuration does not have the default "%s" section' % sections_to_check[0]); sys.exit(-1)

CC                  = ""
LINK                = ""
AR                  = ""
PP                  = ""
OUTPUT_FILE         = ""
TYPE                = config.get(sections_to_check[0], 'type', fallback="")
BUILD_FOLDER        = ""
SOURCE_FOLDER       = ""
INCLUDE_FOLDERS     = ""
LIBRARY_FOLDERS     = ""
DEPENDENCIES        = ""
LIBRARIES           = ""
EXTRA_BUILD_ARGS    = ""
EXTRA_LINK_ARGS     = ""
EXTRA_SETUP_COMMAND = ""
EXTRA_CLEAN_COMMAND = ""
EXTRA_BUILD_COMMAND = ""
EXTRA_POST_BUILD_COMMAND = ""

for section in sections_to_check:
    if not config.has_section(section):
        continue

    CC                  = temp if (temp := config.get(section, 'cc'           , fallback="")) != "" else CC
    LINK                = temp if (temp := config.get(section, 'link'         , fallback="")) != "" else LINK
    AR                  = temp if (temp := config.get(section, 'ar'           , fallback="")) != "" else AR
    PP                  = temp if (temp := config.get(section, 'pp'           , fallback="")) != "" else PP
    OUTPUT_FILE         = temp if (temp := config.get(section, 'output_file'  , fallback="")) != "" else OUTPUT_FILE
    SOURCE_FOLDER       = temp if (temp := config.get(section, 'source_folder', fallback="")) != "" else SOURCE_FOLDER
    BUILD_FOLDER        = temp if (temp := config.get(section, 'build_folder', fallback="")) != "" else BUILD_FOLDER
    INCLUDE_FOLDERS     += ((', ' if INCLUDE_FOLDERS  != '' else '') + temp) if (temp :=config.get(section, 'include_folders'    , fallback="")) != "" else ''
    LIBRARY_FOLDERS     += ((', ' if LIBRARY_FOLDERS  != '' else '') + temp) if (temp :=config.get(section, 'library_folders'    , fallback="")) != "" else ''
    DEPENDENCIES        += ((', ' if DEPENDENCIES     != '' else '') + temp) if (temp :=config.get(section, 'dependencies'       , fallback="")) != "" else ''
    LIBRARIES           += ((', ' if LIBRARIES        != '' else '') + temp) if (temp :=config.get(section, 'libraries'          , fallback="")) != "" else ''
    EXTRA_BUILD_ARGS    += ((' '  if EXTRA_BUILD_ARGS != '' else '') + temp) if (temp :=config.get(section, 'extra_build_args'   , fallback="")) != "" else ''
    EXTRA_LINK_ARGS     += ((' '  if EXTRA_LINK_ARGS  != '' else '') + temp) if (temp :=config.get(section, 'extra_link_args'    , fallback="")) != "" else ''
    EXTRA_SETUP_COMMAND = temp if (temp := config.get(section, 'extra_setup_command', fallback="")) != "" else EXTRA_SETUP_COMMAND
    EXTRA_CLEAN_COMMAND = temp if (temp := config.get(section, 'extra_clean_command', fallback="")) != "" else EXTRA_CLEAN_COMMAND
    EXTRA_BUILD_COMMAND = temp if (temp := config.get(section, 'extra_build_command', fallback="")) != "" else EXTRA_BUILD_COMMAND
    EXTRA_POST_BUILD_COMMAND = temp if (temp := config.get(section, 'extra_post_build_command', fallback="")) != "" else EXTRA_POST_BUILD_COMMAND

if PP == '':
    PP = CC

if CC != '':
    logger.info('\tCC:               %s' % CC)
if LINK != '':
    logger.info('\tLINK:             %s' % LINK)
if AR != '':
    logger.info('\tAR:               %s' % AR)
if PP != '':
    logger.info('\tPP:               %s' % PP)
if OUTPUT_FILE != '':
    logger.info('\tOUTPUT_FILE:      %s' % OUTPUT_FILE)
if TYPE != '':
    logger.info('\tTYPE:             %s' % TYPE)
if BUILD_FOLDER != '':
    logger.info('\tBUILD_FOLDER:     %s' % BUILD_FOLDER)
if SOURCE_FOLDER != '':
    logger.info('\tSOURCE_FOLDER:    %s' % SOURCE_FOLDER)
if INCLUDE_FOLDERS != '':
    logger.info('\tINCLUDE_FOLDERS:  %s' % INCLUDE_FOLDERS)
if LIBRARY_FOLDERS != '':
    logger.info('\tLIBRARY_FOLDERS:  %s' % LIBRARY_FOLDERS)
if DEPENDENCIES != '':
    logger.info('\tDEPENDENCIES:     %s' % DEPENDENCIES)
if LIBRARIES != '':
    logger.info('\tLIBRARIES:        %s' % LIBRARIES)
if EXTRA_BUILD_ARGS != '':
    logger.info('\tEXTRA_BUILD_ARGS: %s' % EXTRA_BUILD_ARGS)
if EXTRA_LINK_ARGS != '':
    logger.info('\tEXTRA_LINK_ARGS:  %s' % EXTRA_LINK_ARGS)
if EXTRA_SETUP_COMMAND != '':
    logger.info('\tEXTRA_SETUP_COMMAND: %s' % EXTRA_SETUP_COMMAND)
if EXTRA_CLEAN_COMMAND != '':
    logger.info('\tEXTRA_CLEAN_COMMAND: %s' % EXTRA_CLEAN_COMMAND)
if EXTRA_BUILD_COMMAND != '':
    logger.info('\tEXTRA_BUILD_COMMAND: %s' % EXTRA_BUILD_COMMAND)
if EXTRA_POST_BUILD_COMMAND != '':
    logger.info('\EXTRA_POST_BUILD_COMMAND_COMMAND: %s' % EXTRA_POST_BUILD_COMMAND)

################################################################################
# CONFIGURATION CHECKS
################################################################################
if TYPE == '':
    logger.critical('The configuration does not include a TYPE'); sys.exit(-1)

if not TYPE in [ 'executable', 'static', 'dynamic', 'script' ]:
    logger.critical('Invalid project type specified. Expected "exectable", "static", "dynamic" or "script". Found "%s"' % TYPE)

if TYPE in [ 'executable', 'static', 'dynamic' ]:
    if OUTPUT_FILE == '':
        logger.critical('The configuration does not include an OUTPUT_FILE')  ; sys.exit(-1)
    if SOURCE_FOLDER == '':
        logger.critical('The configuration does not include a SOURCE_FOLDER') ; sys.exit(-1)
    if CC == '':
        logger.critical('The configuration does not include a CC')            ; sys.exit(-1)
    if PP == '':
        logger.critical('The configuration does not include a PP')            ; sys.exit(-1)
    if LINK == '':
        logger.critical('The configuration does not include a LINK')          ; sys.exit(-1)
    if BUILD_FOLDER == '':
        logger.critical('The configuration does not include a BUILD_FOLDER')  ; sys.exit(-1)

if TYPE == 'static':
    if LIBRARY_FOLDERS != "":
        logger.critical('The configuration cannot declare LIBRARY_FOLDERS if TYPE is "static"') ; sys.exit(-1)
    if LIBRARIES != "":
        logger.critical('The configuration cannot declare LIBRARIES if TYPE is "static"')       ; sys.exit(-1)
    if EXTRA_LINK_ARGS != "":
        logger.critical('The configuration cannot declare EXTRA_LINK_ARGS if TYPE is "static"') ; sys.exit(-1)
    if AR == '':
        logger.critical('The configuration does not include a AR'); sys.exit(-1)

if TYPE == 'script':
    if CC != "":
        logger.critical('The configuration cannot declare CC if TYPE is "script"')              ; sys.exit(-1)
    if LINK != "":
        logger.critical('The configuration cannot declare LINK if TYPE is "script"')            ; sys.exit(-1)
    if AR != "":
        logger.critical('The configuration cannot declare AR if TYPE is "script"')              ; sys.exit(-1)
    if PP != "":
        logger.critical('The configuration cannot declare PP if TYPE is "script"')              ; sys.exit(-1)
    if OUTPUT_FILE != "":
        logger.critical('The configuration cannot declare OUTPUT_FILE if TYPE is "script"')     ; sys.exit(-1)
    if SOURCE_FOLDER != "":
        logger.critical('The configuration cannot declare SOURCE_FOLDER if TYPE is "script"')   ; sys.exit(-1)
    if INCLUDE_FOLDERS != "":
        logger.critical('The configuration cannot declare INCLUDE_FOLDERS if TYPE is "script"') ; sys.exit(-1)
    if LIBRARY_FOLDERS != "":
        logger.critical('The configuration cannot declare LIBRARY_FOLDERS if TYPE is "script"') ; sys.exit(-1)
    if LIBRARIES != "":
        logger.critical('The configuration cannot declare LIBRARIES if TYPE is "script"')       ; sys.exit(-1)
    if EXTRA_BUILD_ARGS != "":
        logger.critical('The configuration cannot declare EXTRA_BUILD_ARGS if TYPE is "script"'); sys.exit(-1)
    if EXTRA_LINK_ARGS != "":
        logger.critical('The configuration cannot declare EXTRA_LINK_ARGS if TYPE is "script"') ; sys.exit(-1)

if OPERATION == 'priv_resolve_dependency':
    if DEPENDENCIES != "":
        logger.critical("Dependencies cannot declare dependencies"); sys.exit(-1)

################################################################################
# FOLDER CHECKS
################################################################################
if BUILD_FOLDER == '':
    BUILD_FOLDER = 'build'
BUILD_OBJECTS_FOLDER = BUILD_FOLDER + '/' + '.objs'
BUILD_HASHS_FOLDER = BUILD_FOLDER + '/' + '.hashs'
BUILD_CACHE_FOLDER = BUILD_FOLDER + '/' + '.cache'

if not os.path.exists(BUILD_FOLDER):
    os.mkdir(BUILD_FOLDER)
if not os.path.exists(BUILD_OBJECTS_FOLDER):
    os.mkdir(BUILD_OBJECTS_FOLDER)
if not os.path.exists(BUILD_HASHS_FOLDER):
    os.mkdir(BUILD_HASHS_FOLDER)
if not os.path.exists(BUILD_CACHE_FOLDER):
    os.mkdir(BUILD_CACHE_FOLDER)

if DEPENDENCIES != "":
    for dependency in map(lambda x: x.strip(), DEPENDENCIES.split(',')):
        if (not os.path.isdir(dependency)) or (not os.path.isfile(dependency + '/' + CONFIG_TARGET)):
            logger.critical('Dependency "%s" is invalid' % dependency); sys.exit(-1)

################################################################################
# ASYNC STUFF
################################################################################
def background(f):
    def wrapped(*args, **kwargs):
        return asyncio.get_event_loop().run_in_executor(None, f, *args, **kwargs)

    return wrapped

################################################################################
# DEPENDENCY RESOLUTION
################################################################################
if DEPENDENCIES != "":
    for dependency in map(lambda x: x.strip(), DEPENDENCIES.split(',')):
        logger.info('Solving dependency "%s":' % dependency)
        os.chdir(CWD + '/' + dependency)
        if os.system(CWD + '/builder.py ' + ('clean' if OPERATION == 'clean' else 'priv_resolve_dependency') + ' ' + OPT_LEVEL) != 0:
            logger.critical('Depenency "%s" failed to resolve' % dependency); sys.exit(-1)
    os.chdir(CWD)

################################################################################
# CLEAN
################################################################################
if OPERATION == 'clean':
    logger.info('Cleaning...')
    try:
        os.remove(BUILD_FOLDER + '/' + OUTPUT_FILE)
    except:
        pass
    for f in pathlib.Path(BUILD_OBJECTS_FOLDER).glob('*.o'):
        os.remove(f)
    for f in pathlib.Path(BUILD_HASHS_FOLDER).glob('*.md5'):
        os.remove(f)
    for f in pathlib.Path(BUILD_CACHE_FOLDER).glob('*.cache'):
        os.remove(f)

    logger.info('Running external clean setup...')
    if EXTRA_CLEAN_COMMAND != "":
        if os.system(EXTRA_CLEAN_COMMAND):
            logger.critical('External clean command failed'); sys.exit(-1)

    logger.info('Project "%s/%s" cleaned' % (CWD, CONFIG_TARGET))
    sys.exit(0)

################################################################################
# EXTERNAL BUILD
################################################################################
if EXTRA_SETUP_COMMAND != '':
    cache_path = '%s/%s_external_setup_complete.cache' % (BUILD_CACHE_FOLDER, OPT_LEVEL)
    if not os.path.isfile(cache_path):
        logger.info('Running external setup command...')
        if os.system(EXTRA_SETUP_COMMAND) != 0:
            logger.critical('External setup command failed'); sys.exit(-1)
        open(cache_path, 'w').close()
    
if EXTRA_BUILD_COMMAND != '':
    logger.info('Running external build command...')
    if os.system(EXTRA_BUILD_COMMAND) != 0:
        logger.critical('External build command failed'); sys.exit(-1)

################################################################################
# BUILD OBJECTS
################################################################################
@background
def compile_source(source):
    normalized_source_name = ''.join([x if x.isalnum() else '_' for x in str(source)]) # Trims all the non alphanumeric characters

    compilation_command = "%s -c %s -o %s/%s.o %s" % (
        CC, source, BUILD_OBJECTS_FOLDER, 
        normalized_source_name,
        EXTRA_BUILD_ARGS
    )
    compilation_command += ''.join(' -I%s' % i.strip() for i in INCLUDE_FOLDERS.split(',') if i.strip() != '')
    compilation_command += ' -D BUILDER_DEBUG=%d -D BUILDER_RELEASE=%d -D BUILDER_OS_%s=1 -D BUILDER_ARCH_%s=1 -D BUILDER_BITS=%s' % (
        1 if OPT_LEVEL == 'debug' else 0,
        1 if OPT_LEVEL == 'release' else 0,
        platform.system().upper(),
        architecture.upper(),
        platform.architecture()[0][0:2]
    )

    expand_command = '%s -E -c %s' % (
        PP, source
    )
    expand_command += ''.join(' -I%s' % i.strip() for i in INCLUDE_FOLDERS.split(',') if i.strip() != '')
    expand_command += ' -D BUILDER_DEBUG=%d -D BUILDER_RELEASE=%d -D BUILDER_OS_%s=1 -D BUILDER_ARCH_%s=1 -D BUILDER_BITS=%s' % (
        1 if OPT_LEVEL == 'debug' else 0,
        1 if OPT_LEVEL == 'release' else 0,
        platform.system().upper(),
        architecture.upper(),
        platform.architecture()[0][0:2]
    )

    error_code, result = subprocess.getstatusoutput(expand_command)
    if error_code == 0:
        hash = hashlib.md5((OPT_LEVEL + result).encode('utf-8')).hexdigest()
        hash_file = pathlib.Path(CWD + '/' + BUILD_HASHS_FOLDER + '/' + normalized_source_name + '.md5')
        if os.path.isfile(hash_file):
            f = open(hash_file, 'r')
            if f.read() == hash:
                f.close()
                logger.debug('Skipping compilation of file %s: Incremental cache matches' % source)
                return
            f.close()

        f = open(hash_file, 'w')
        f.truncate(0)
        f.write(hash)
        f.close()


    logger.info('Compiling file "%s"...' % source)
    logger.debug('Using command %s' % compilation_command)
    if os.system(compilation_command) != 0:
        logger.critical('Compilation failed for file "%s"' % source); sys.exit(-1)

if TYPE in [ 'executable', 'static', 'shared' ]:
    source_files = [ f for f in pathlib.Path(SOURCE_FOLDER).glob('**/*.c') if f.is_file() ]
    loop = asyncio.get_event_loop()
    loop.run_until_complete(asyncio.gather(*[compile_source(s) for s in source_files]))

################################################################################
# LINK OBJECTS
################################################################################
if TYPE in [ 'executable', 'dynamic' ]:
    link_command = '%s %s -o %s/%s %s' % (
        LINK, 
        '-shared' if TYPE == 'dynamic' else '',
        BUILD_FOLDER, OUTPUT_FILE, EXTRA_LINK_ARGS
    )
    link_command += ''.join([' ' + str(f) for f in pathlib.Path(BUILD_OBJECTS_FOLDER).glob('**/*.o') if f.is_file() ])
    link_command += ''.join([' -L%s' % l.strip() for l in LIBRARY_FOLDERS.split(',') if l.strip() != ''])
    link_command += ''.join([' -l%s' % l.strip() for l in LIBRARIES.split(',') if l.strip() != ''])

    logger.info('Linking "%s"...' % OUTPUT_FILE)
    logger.debug('Using command %s' % link_command)
    if os.system(link_command) != 0:
        logger.critical('Linking failed for project "%s"' % OUTPUT_FILE); sys.exit(-1)

elif TYPE == 'static':
    ar_command = '%s -r %s/%s' % (
        AR, BUILD_FOLDER, OUTPUT_FILE
    )
    ar_command += ''.join([' ' + str(f) for f in pathlib.Path(BUILD_OBJECTS_FOLDER).glob('**/*.o') if f.is_file()])

    logger.info('Archiving "%s"...' % OUTPUT_FILE)
    logger.debug('Using command %s' % ar_command)
    if os.system(ar_command) != 0:
        logger.critical('Archiving failed for project "%s"' % OUTPUT_FILE); sys.exit(-1)

################################################################################
# POST BUILD
################################################################################
if EXTRA_POST_BUILD_COMMAND != '':
    logger.info('Running external post build command...')
    if os.system(EXTRA_POST_BUILD_COMMAND) != 0:
        logger.critical('External post build command failed'); sys.exit(-1)

################################################################################
# TESTING
################################################################################
if OPERATION == 'run':
    logger.info('Running application')
    os.system(BUILD_FOLDER + '/' + OUTPUT_FILE)
