add_executable(Game
    src/main.cpp
)
target_link_libraries(Game
    PRIVATE
        GameCore
)

target_include_directories(Game
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)