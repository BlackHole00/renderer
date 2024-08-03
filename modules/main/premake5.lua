main_module = {
	name = "Main",
	location = modules_folder .. "main",
	includedirs = concat(
		gfxhal_module.includedirs
	),
}

function declare_main_project()
	project "Main"
		kind "ConsoleApp"
		language "C"
		location (modules_folder .. "main")
		includedirs(gfxhal_module.includedirs)
		links {
			"Std", "Gfx-Hal", "glfw3",
		}
		files { modules_folder .. "main/src/**.c" }
		std_project_exports()

		filter "system:macosx"
			libdirs { 
				"modules/vulkan/lib/darwin",
				"modules/glfw/lib/darwin-arm64"
			}
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
end

