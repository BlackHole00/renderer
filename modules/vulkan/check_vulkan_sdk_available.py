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
link_target = 'lib/darwin/libvulkan.dylib'

while os.path.islink(libvulkan_path):
    libvulkan_path = os.path.realpath(libvulkan_path)

if os.path.islink(link_target):
    os.unlink(link_target)
os.symlink(libvulkan_path, link_target)

