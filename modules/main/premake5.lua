main_project_name = "Main"

function declare_main_project()
	project(main_project_name)
		kind "ConsoleApp"
		language "C"
		location (modules_folder .. "main")
		files { modules_folder .. "main/src/**.c" }
		glfw3_module_exports()
		vulkan_module_exports()
		std_project_exports()
		gfxhal_project_exports()
end

