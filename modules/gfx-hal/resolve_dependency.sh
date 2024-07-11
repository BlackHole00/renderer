#!/bin/sh

################################################################################
# BUILD PARAMETERS
################################################################################
OUTPUT_FILE=libgfxhal.a
TYPE=static
BUILD_FOLDER=lib
SOURCE_FOLDER=src
INCLUDE_FOLDERS=(include ../std/include ../vulkan/include ../glfw/include)
LIBRARY_FOLDERS=()
DEPENDENCIES=()
LIBRARIES=()
EXTRA_BUILD_ARGS="-fblocks -std=c23 -Wall -Wextra -Wpedantic"
EXTRA_LINK_ARGS="-fblocks"

CC=clang
LINK=clang
AR=ar

################################################################################
# BUILD
################################################################################
source ${BUILDER_PATH}builder.sh
