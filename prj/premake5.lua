include "../tools/premake/common/"

solution "armada"

	math.randomseed(string.hash(solution().name))
  	startproject "armada"
	addCommonConfig()

-------------------------------------------------------------------------------

    defines
    {
        "STB_IMAGE_IMPLEMENTATION",
		"GLEW_STATIC",
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

	local BUILD_DIR   = "../build/" .. _OPTIONS["arch"] .. "/"
	local RELEASE_DIR = "../release/"

	local SDL_LIB = LIBS .. "SDL2-2.0.3/"
    local GLM     = LIBS .. "glm/"
    local STB     = LIBS .. "stb/"
    local LOGURU  = LIBS .. "loguru/"
	local PUG     = LIBS .. "pug/"
	local GLEW    = LIBS .. "glew-1.10.0/"

-------------------------------------------------------------------------------

project "pug"
	targetdir(BUILD_DIR)
	kind "StaticLib"
		
	files
	{
		PUG .. "include/**",
		PUG .. "src/**",
	}
	
	includedirs
	{
		PUG     .. "include",
		SDL_LIB .. "include",
        GLM     .. "glm",
        STB     .. "stb",
		GLEW    .. "include",
        LOGURU,
	}

	libdirs 
	{ 
		BUILD_DIR .. _OPTIONS["arch"],
		GLEW.."/lib/" .. _OPTIONS["arch"],
		SDL_LIB.."/lib/" .. _OPTIONS["arch"],
	}

	links
	{
		"glew32s",
		"opengl32",
		"SDL2",
		"SDL2main",
		"SDL2test",
	}

	configuration "Debug"
		defines { "_DEBUG" }
		buildoptions { "/MDd" }

	configuration "Release"
		defines { "NDEBUG" }
		buildoptions { "/MD" }

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
		PUG     .. "include",
		GLEW    .. "include",		
	}

	libdirs 
	{ 
		BUILD_DIR .. _OPTIONS["arch"],
		GLEW.."/lib/" .. _OPTIONS["arch"],
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
		"glew32s",
		"opengl32",			
		"SDL2",
		"SDL2main",
		"SDL2test",
		"pug",
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
