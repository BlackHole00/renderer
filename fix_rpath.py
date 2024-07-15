#!/usr/bin/python3
import os
import sys
import logging
import pathlib

logging.basicConfig(format='[%(levelname)s] : %(message)s')
logger = logging.getLogger('Builder')
logger.setLevel(logging.INFO)

vulkan_skd_path = os.getenv('VULKAN_SDK')
if vulkan_skd_path == None:
    logger.critical('Could not locate the Vulkan SDK. Please set the "VULKAN_SDK" environment variable or build in release mode')
    sys.exit(-1)

libvulkan_path = ('%s/macOS/lib/libvulkan.dylib' % vulkan_skd_path).replace('~', str(pathlib.Path.home().absolute()))

while os.path.islink(libvulkan_path):
    libvulkan_path = os.path.realpath(libvulkan_path)

command = 'install_name_tool build/renderer.out -change \'@rpath/libvulkan.1.dylib\' \'%s\'' % libvulkan_path
if os.system(command) != 0:
    logger.critical('Could not fix the execuitable to run the proper dynamic vulkan library')
    sys.exit(-1)

