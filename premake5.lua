require "premake5common"

workspace "Renderer"
	configurations { "Debug", "Release" }
	platforms { 
		"Windows_i386",
		"Windows_amd64",
		"Windows_arm64",
		"Darwin_amd64",
		"Darwin_arm64",
		"Linux_i386",
		"Linux_amd64",
		"Linux_arm64",
	}
	
	filter "configurations:Debug"
		defines { "BUILD_DEBUG" }
		targetdir  "bin/debug" 
		symbols "On"
	filter "configurations:Release"
		defines { "BUILD_RELEASE" }
		targetdir  "bin/release" 
		optimize "On"

	filter "platforms:Windows_i386"
		defines { "BUILD_OS_WINDOWS", "BUILD_ARCHITECTURE_I386", "BUILD_BITS=32" }
		architecture "x86"
		system "windows"
	filter "platforms:Windows_amd64"
		defines { "BUILD_OS_WINDOWS", "BUILD_ARCHITECTURE_AMD64", "BUILD_BITS=64" }
		architecture "x86_64"
		system "windows"
	filter "platforms:Windows_arm64"
		defines { "BUILD_OS_WINDOWS", "BUILD_ARCHITECTURE_ARM64", "BUILD_BITS=64" }
		architecture "arm64"
		system "windows"
	filter "platforms:Darwin_i386"
		defines { "BUILD_OS_DARWIN", "BUILD_ARCHITECTURE_I386", "BUILD_BITS=32" }
		architecture "x86"
		system "macosx"
	filter "platforms:Darwin_amd64"
		defines { "BUILD_OS_DARWIN", "BUILD_ARCHITECTURE_AMD64", "BUILD_BITS=64" }
		architecture "x86_64"
		system "macosx"
	filter "platforms:Darwin_arm64"
		defines { "BUILD_OS_DARWIN", "BUILD_ARCHITECTURE_ARM64", "BUILD_BITS=64" }
		architecture "arm64"
		system "macosx"
	filter "platforms:Linux_i386"
		defines { "BUILD_OS_LINUX", "BUILD_ARCHITECTURE_I386", "BUILD_BITS=32" }
		architecture "x86"
		system "linux"
	filter "platforms:Linux_amd64"
		defines { "BUILD_OS_LINUX", "BUILD_ARCHITECTURE_AMD64", "BUILD_BITS=64" }
		architecture "x86_64"
		system "linux"
	filter "platforms:Linux_arm64"
		defines { "BUILD_OS_LINUX", "BUILD_ARCHITECTURE_ARM64", "BUILD_BITS=64" }
		architecture "arm64"
		system "linux"

project "*"
	buildoptions "--std=c23"
	toolset "clang"
	toolsversion "18"

include (modules_folder .. "std/premake5")
include (modules_folder .. "gfx-hal/premake5")
include (modules_folder .. "main/premake5")

-- project "Vulkan"
-- 	kind "Utility"
-- 	libdirs { "modules/vulkan/lib/darwin" }
-- 	links { "MoltenVK" }

-- project "Glfw"
-- 	kind "Utility"
-- 	libdirs { "modules/glfw/lib/darwin-arm64" }
-- 	links { "glfw" }

declare_std_project()
declare_gfxhal_project()
declare_main_project()
