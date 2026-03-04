add_library(GameEngineLib SHARED
        src/Window/WindowConfig.h
        src/Window/IWindow.h)

# Platform-specific sources
if (WIN32)
    target_sources(GameEngineLib PRIVATE
            src/Window/Windows/WindowPlatformWin32.cpp
            src/Window/Windows/WindowWin32.cpp
    )
elseif (APPLE)
    target_sources(GameEngineLib PRIVATE
            src/Window/Mac/WindowPlatformMac.cpp
            src/Window/Mac/WindowMac.cpp
    )
elseif (UNIX)
    target_sources(GameEngineLib PRIVATE
            src/Window/Linux/WindowPlatformLinux.cpp
    )
endif()

target_sources(GameEngineLib
    PRIVATE
        src/Engine.cpp
        src/Renderer.cpp
        src/Window/Windows/WindowWin32.cpp
)

target_include_directories(GameEngineLib
    PUBLIC 
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)