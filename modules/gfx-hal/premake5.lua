gfxhal_module = {
	name = "Gfx-Hal",
	location = modules_folder .. "gfx-hal",
	includedirs = concat(
		std_module.includedirs,
		{
			modules_folder .. "gfx-hal/include",
			modules_folder .. "vulkan/include",
			modules_folder .. "glfw/include"
		}
	),
}

function declare_gfxhal_project()
	project(gfxhal_module.name)
		kind "StaticLib"
		language "c"
		location(gfxhal_module.location)
		includedirs(gfxhal_module.includedirs)
		files { modules_folder .. "gfx-hal/src/**.c" }
end
