--premake5.lua
workspace "AdventOfCode2023"

    location "generated"

    language"c++"

    architecture "x86_64"

    configurations {"debug", "release"}

    files{"**.cpp", "**.hpp", "**.txt"}

    filter "configurations:debug"
        defines{"debug"}
        symbols "On"

    filter "configurations:release"
        defines{"Ndebug"}
        optimize "On"

    filter {}

    targetdir("bin/%{prj.name}/%{cfg.buildcfg}")

    objdir("obj/%{prj.name}/%{cfg.buildcfg}")

project "AdventOfCode2023"
    kind "ConsoleApp"
    files "Projects/App/**"
