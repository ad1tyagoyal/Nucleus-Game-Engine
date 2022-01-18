workspace "Nucleus"
	architecture "x64"

	configurations {
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"


IncludeDir = {}
IncludeDir["GLFW"] = "Nucleus/vendor/GLFW/include"
IncludeDir["Glad"] = "Nucleus/vendor/Glad/include"
IncludeDir["ImGui"] = "Nucleus/vendor/ImGui"
IncludeDir["glm"] = "Nucleus/vendor/glm"


group "Dependencies"
	include "Nucleus/vendor/GLFW"
	include "Nucleus/vendor/Glad"
	include "Nucleus/vendor/ImGui"

group ""

project "Nucleus"
	location "Nucleus"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "")
	objdir ("bin-int/" .. outputdir .. "")

	pchheader "NclPch.h"
	pchsource "Nucleus/src/NclPch.cpp"

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl"
	}

	includedirs {
		"%{prj.name}/vendor/spdlog/include",
		"%{prj.name}/src",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}"
	}

	links {
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib",
		"msvcrtd.lib"
	}

	filter "system:windows"
		systemversion "latest"

		defines {
			"NCL_PLATFORM_WINDOWS",
			"NCL_BUILD_DLL",
			"_WINDLL",
			"GLFW_INCLUDE_NONE"
		}


	filter "configurations:Debug"
		defines "NCL_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "NCL_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "NCL_DIST"
		runtime "Release"
		optimize "on"




project "SandBox Application"
	location "SandBox Application"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "")
	objdir ("bin-int/" .. outputdir .. "")

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs {
		"Nucleus/vendor/spdlog/include",
		"%{IncludeDir.glm}",
		"Nucleus/src"
	}

	links {
		"Nucleus"
	}

	filter "system:windows"
		systemversion "latest"

		defines {
			"NCL_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "NCL_DEBUG"
		symbols "on"

	filter "configurations:Release"
		defines "NCL_RELEASE"
		optimize "on"

	filter "configurations:Dist"
		defines "NCL_DIST"
		optimize "on"
