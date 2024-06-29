#!/bin/sh

################################################################################
# BUILD PARAMETERS
################################################################################
OUTPUT_FILE=project
TYPE=executable
BUILD_FOLDER=build
SOURCE_FOLDER=modules/main/src
INCLUDE_FOLDERS=(modules/std/include modules/gfx-hal/include modules/glfw/include modules/vulkan/include)
LIBRARY_FOLDERS=(modules/std/lib modules/gfx-hal/lib modules/glfw/lib/darwin-arm64 modules/vulkan/lib/darwin)
DEPENDENCIES=(modules/std modules/gfx-hal)
LIBRARIES=(c++ std gfxhal glfw3 MoltenVK)
EXTRA_BUILD_ARGS="-std=c23 -Wall -Wextra -Wpedantic"
EXTRA_LINK_ARGS="-framework Cocoa \
	-framework IOKit \
	-framework CoreVideo \
	-framework Metal \
	-framework QuartzCore \
	-framework CoreGraphics \
	-framework AppKit \
	-framework Foundation \
	-framework IOSurface \
"

CC=clang
AR=ar

################################################################################
# BUILD
################################################################################
source ${BUILDER_PATH}builder.sh

