include "../tools/premake/common/"

solution "armada"

	math.randomseed(string.hash(solution().name))
  	startproject "armada"
	addCommonConfig()

-------------------------------------------------------------------------------

    defines
    {
        "STB_IMAGE_IMPLEMENTATION",
        "FONTSTASH_IMPLEMENTATION",
		"GLFONTSTASH_IMPLEMENTATION",
		"SDF_IMPLEMENTATION",
        "LOGURU_IMPLEMENTATION",
        "NOMINMAX",
    }

-------------------------------------------------------------------------------

	configuration "Debug"
		targetsuffix "-d"

-------------------------------------------------------------------------------

	local LIBS      = "../libs/"
	local SRC       = "../src/"

	local BUILD_DIR = "../build/".._OPTIONS["arch"].."/"
	local RELEASE_DIR = "../release/"

	local SDL_LIB = LIBS .. "SDL2-2.0.3/"
    local GLM     = LIBS .. "glm/"
    local STB     = LIBS .. "stb/"
    local LOGURU  = LIBS .. "loguru/"

-------------------------------------------------------------------------------

project "armada"
	targetdir(RELEASE_DIR)
	debugdir("$(TargetDir)")
	pchheader "pch.h"
	pchsource (SRC .. "pch.cpp")

	files 
	{
		SRC .. "**",
	}

	includedirs 
	{
		SRC,
		SDL_LIB .. "include",
        GLM     .. "glm",
        STB     .. "stb",
        LOGURU,
	}

	libdirs 
	{ 
		BUILD_DIR .. _OPTIONS["arch"],
		SDL_LIB.."/lib/" .. _OPTIONS["arch"],
	}

	-- Copy the needed dlls to the output dir
	postbuildcommands
	{
		"echo Copying dlls...",
		"robocopy $(SolutionDir)../../"..SDL_LIB.."bin/" .. _OPTIONS["arch"] .. "/ $(TargetDir)  /XO /NJH /NP > log.txt",
		"exit 0",
	}

	links
	{
		"SDL2",
		"SDL2main",
		"SDL2test",
	}

	configuration "Debug"
		defines { "_DEBUG" }
		buildoptions { "/MDd" }
		kind "ConsoleApp"

	configuration "Release"
		defines { "NDEBUG" }
		buildoptions { "/MD" }
		kind "WindowedApp"
		flags {"WinMain"}

---------------------------------------------------------------------------
