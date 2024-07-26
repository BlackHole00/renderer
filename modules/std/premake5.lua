std_module = {
	name = "Std",
	location = modules_folder .. "std",
	includedirs = { modules_folder .. "std/include" },
}

function declare_std_project()
	project(std_module.name)
		kind "StaticLib"
		language "c"
		location(std_module.location)
		includedirs(std_module.includedirs)
		files { modules_folder .. "std/src/**.c" }
end

