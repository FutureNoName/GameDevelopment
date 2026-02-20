add_library(GameEngineLib SHARED)

target_sources(GameEngineLib
    PRIVATE
        src/Engine.cpp
        src/Renderer.cpp
        src/Window.cpp
)

target_include_directories(GameEngineLib
    PUBLIC 
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)