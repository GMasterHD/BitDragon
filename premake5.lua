-- Variables
outdir = "%{cfg.longname}/%{prj.name}"

include "dependencies.lua"

workspace "BitDragon"
	systemversion "latest"

	configurations {
		"Debug-x64", "Release-x64", "Dist-x64",
		"Debug-x86", "Release-x86", "Dist-x86"
	}

	filter "configurations:*64"
		architecture "x86_64"
	filter "configurations:*86 or configurations:*32"
		architecture "x86"

	filter { }

	group "Libraries"
		include "lib/yaml-cpp"
	group "Tests"
	group ""
		include "src/main/bitdragon.lua"
		include "src/main/bitdragon-launcher.lua"
