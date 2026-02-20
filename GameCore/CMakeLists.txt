add_library(GameCore SHARED
        src/Game.h)

target_sources(GameCore
    PRIVATE
        src/Game.cpp
)

target_include_directories(GameCore
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(GameCore
    PRIVATE
        GameEngineLib
)