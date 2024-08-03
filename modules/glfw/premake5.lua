glfw3_module_name = "glfw3"

function glfw3_module_exports()
	includedirs { modules_folder .. "glfw/include" }
	links { "glfw3" }

	filter "platforms:darwin_arm64"
		libdirs { "modules/glfw/lib/darwin-arm64" }
	filter "platforms:darwin_amd64"
		libdirs { "modules/glfw/lib/darwin-amd64" }
	filter "platforms:Windows_i386"
		libdirs { "modules/glfw/lib/windows-i386" }
	filter "platforms:Windows_amd64"
		libdirs { "modules/glfw/lib/windows-amd64" }
	filter "platforms:Windows_arm64"
		libdirs { "modules/glfw/lib/windows-arm64" }
	filter "platforms:Linux_i386"
		libdirs { "modules/glfw/lib/linux-i386" }
	filter "platforms:Linux_amd64"
		libdirs { "modules/glfw/lib/linux-amd64" }
	filter "platforms:Linux_arm64"
		libdirs { "modules/glfw/lib/linux-arm64" }
end

