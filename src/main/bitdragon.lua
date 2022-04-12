project "BitDragon"
	language "C++"
	cppdialect "C++20"
	kind "StaticLib"
	systemversion "latest"
	location "%{wks.location}/src/main/BitDragon/"

	debugdir("%{wks.location}/bin/main/"..outdir)

	targetdir("%{wks.location}/bin/main/"..outdir)
	objdir("%{wks.location}/bin-int/main/"..outdir)

	files {
		"%{prj.location}/**.c",
		"%{prj.location}/**.h",
		"%{prj.location}/**.cpp",
		"%{prj.location}/**.hpp"
	}

	includedirs {
		"%{prj.location}/../",
		includeDir["Main"],
		includeDir["YAML"]
	}

	defines {
		"_CRT_NO_SECURE_WARNINGS",
		"YAML_CPP_STATIC_DEFINE"
	}

	links {
	}

	filter "configurations:*86 or configurations:*32"
		libdirs {
		}
	filter "configurations:*64"
		libdirs {
		}
	
	filter "system:windows"
		links {
		}
	
	filter "configurations:Debug*"
		defines {
			"BD_Debug"
		}
		symbols "On"
		optimize "Off"

	filter "configurations:Release*"
		defines {
			"BD_Release"
		}
		symbols "On"
		optimize "Debug"

	filter "configurations:Dist*"
		defines {
			"BD_Dist"
		}
		symbols "Off"
		optimize "Speed"

	filter "system:windows"
		defines {
			"BD_Windows"
		}

	filter "system:macosx"
		defines {
			"BD_Unix",
			"BD_MacOSX"
		}
	filter "system:linux"
		defines {
			"BD_Unix",
			"BD_Linux"
		}
