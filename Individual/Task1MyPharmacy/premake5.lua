workspace "Task1MyPharmacy"
    architecture "x64"
    startproject "AdminPharmacy"
    configurations
    {
        "Debug",
        "Release",
    }
    
    filter { "configurations:Debug" }
        symbols "On"
    
	filter { "configurations:Release" }
        optimize "On"
    
    filter { }
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}" 

project "Task1MyPharmacy"
    location "Task1MyPharmacy"
    kind "StaticLib"
    language "C++"
    staticruntime "off"
    
    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
        "%{prj.name}/tablefiles/**.txt"
    }
    
    includedirs
    {
        "%{prj.name}/src",
    }
    
    links 
    { 

    }
    
    filter "system:windows"
        cppdialect "C++17"
        systemversion "latest"

project "AdminPharmacy"
    location "AdminPharmacy"
    kind "ConsoleApp"
    language "C++"
    staticruntime "off"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
     
    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
    }
    
    includedirs
    {
        "Task1MyPharmacy/src",
    }

    links
    {
        "Task1MyPharmacy"
    }

project "UserPharmacy"
    location "UserPharmacy"
    kind "ConsoleApp"
    language "C++"
    staticruntime "off"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
     
    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
    }
    
    includedirs
    {
        "Task1MyPharmacy/src",
    }

    links
    {
        "Task1MyPharmacy"
    }