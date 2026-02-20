add_executable(Game
    src/Game.cpp
)

target_link_libraries(Game PRIVATE GameEngineLib)

target_include_directories(Game
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)
