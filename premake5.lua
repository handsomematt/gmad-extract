solution "gmaextract"
	configurations { "Debug", "Release" }
	platforms { "x32", "x64" }

	language		"C++"
	characterset	"MBCS"
	location		"project"
	targetdir		"bin"

	filter "platforms:x32"
		architecture "x32"

	filter "platforms:x64"
		architecture "x64"

	project "gmaextract"
		kind	"ConsoleApp"
		targetname "gmaextract"
		flags { "Symbols", "NoEditAndContinue", "NoPCH", "StaticRuntime", "EnableSSE" }
		links "bootil_static"
		includedirs "Bootil/include"

        if os.is( "linux" ) then
                buildoptions { "-fPIC", "-pthread" }
                linkoptions { "-pthread" }
        end

		files {
			"src/main.cpp",
			"src/AddonReader.h",
			"src/AddonFormat.h"
		}

	include "Bootil/projects/bootil_premake5.lua"