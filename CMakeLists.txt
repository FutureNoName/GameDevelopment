cmake_minimum_required(VERSION 3.22)

project(GameDevelopment)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(GameEngineLib)
add_subdirectory(Game)
add_subdirectory(GameEngineTests)
add_subdirectory(GameProjectTests)