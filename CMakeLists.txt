cmake_minimum_required(VERSION 3.22)

project(GameDevelopment LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG main
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_subdirectory(GameEngineLib)
add_subdirectory(GameCore)
add_subdirectory(Game)
add_subdirectory(GameEngineTests)
add_subdirectory(GameProjectTests)
