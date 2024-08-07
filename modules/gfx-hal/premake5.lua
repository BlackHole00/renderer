gfxhal_project_name = "Gfx-Hal"

function gfxhal_project_exports()
	filter {}
		includedirs (modules_folder .. "gfx-hal/include")
		links { gfxhal_project_name }

	glfw3_module_exports()
	vulkan_module_exports()
	std_project_exports()
end

function declare_gfxhal_project()
	project (gfxhal_project_name)
		kind "StaticLib"
		language "c"
		location (modules_folder .. "gfx-hal")
		files { modules_folder .. "gfx-hal/src/**.c" }
		includedirs (modules_folder .. "gfx-hal/include")
		glfw3_module_exports()
		vulkan_module_exports()
		std_project_exports()
end
