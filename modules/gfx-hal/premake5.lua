gfxhal_project_name = "Gfx-Hal"

gfxhal_module = {
	name = "Gfx-Hal",
	location = modules_folder .. "gfx-hal",
	includedirs = concat(
		{
			modules_folder .. "gfx-hal/include",
			modules_folder .. "vulkan/include",
			modules_folder .. "glfw/include"
		}
	),
}

function gfxhal_project_exports()
	includedirs (modules_folder .. "gfx-hal/include")
	vulkan_module_exports()

function declare_gfxhal_project()
	project (gfxhal_project_name)
		kind "StaticLib"
		language "c"
		location (modules_folder .. "gfx-hal")
		includedirs (gfxhal_module.includedirs)
		files { modules_folder .. "gfx-hal/src/**.c" }
end
