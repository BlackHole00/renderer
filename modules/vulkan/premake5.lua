vulkan_module_name = "vulkan"

function vulkan_module_setup()
	if os.target() ~= "macosx" then
		return
	end

	if os.isfile("modules/vulkan/lib/darwin/libvulkan.dylib") or os.islink("modules/vulkan/lib/darwin/libvulkan.dylib") then
		os.execute("rm modules/vulkan/lib/darwin/libvulkan.dylib")
	end
	if os.isfile("bin/debug/libvulkan.1.dylib") or os.islink("bin/debug/libvulkan.1.dylib") then
		os.execute("rm bin/debug/libvulkan.1.dylib")
	end
	if os.isfile("bin/release/libvulkan.1.dylib") or os.islink("bin/release/libvulkan.1.dylib") then
		os.execute("rm bin/release/libvulkan.1.dylib")
	end

	vulkan_sdk_path = os.getenv("VULKAN_SDK")
	if vulkan_sdk_path == nil or vulkan_sdk_path == "" then
		printf("[Warning] The vulkan SDK is not installed. Debug builds will use the pre-bundles MoltenVK library. Validation layers won't be supported")
		os.execute("ln -s modules/vulkan/lib/darwin/libMoltenVK.a modules/vulkan/lib/darwin/libVulkan.a")
		return
	end

	libvulkan_path = vulkan_sdk_path .. "/macOS/lib/libvulkan.dylib"
	while true do -- os.islink() seems broken?
		linked_file, error_code = os.outputof("readlink -f " .. libvulkan_path)
		if error_code ~= 0 then
			break
		end

		if libvulkan_path == linked_file then
			break
		end
		libvulkan_path = linked_file
	end

	os.executef("ln -s %s modules/vulkan/lib/darwin/libvulkan.dylib", libvulkan_path)

	--- TODO(Vicix): Find a better way to fix the rpath
	os.executef("ln -s %s bin/release/libvulkan.1.dylib", libvulkan_path)
	os.executef("ln -s %s bin/debug/libvulkan.1.dylib", libvulkan_path)
end

function vulkan_module_exports()
	filter {}
		includedirs { modules_folder .. "vulkan/include" }

	filter "platforms:not darwin* or configurations:Debug"
		links { "vulkan" }
	filter { "platforms:darwin*", "configurations:Release" }
		links { "MoltenVK" }

	filter "platforms:darwin*"
		libdirs { "modules/vulkan/lib/darwin" }
		links {
			"MoltenVK",
			"c++",
			"Cocoa.framework",
			"IOKit.framework",
			"CoreVideo.framework",
			"Metal.framework",
			"QuartzCore.framework",
			"CoreGraphics.framework",
			"AppKit.framework",
			"Foundation.framework",
			"IOSurface.framework"
		}
	filter "platforms:Windows_i386"
		libdirs { "modules/vulkan/lib/windows-i386" }
	filter "platforms:Windows_amd64"
		libdirs { "modules/vulkan/lib/windows-amd64" }
	filter "platforms:Windows_arm64"
		libdirs { "modules/vulkan/lib/windows-arm64" }
	filter "platforms:Linux_i386"
		libdirs { "modules/vulkan/lib/linux-i386" }
	filter "platforms:Linux_amd64"
		libdirs { "modules/vulkan/lib/linux-amd64" }
	filter "platforms:Linux_arm64"
		libdirs { "modules/vulkan/lib/linux-arm64" }
end


