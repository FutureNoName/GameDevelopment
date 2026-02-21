add_executable(Game
    src/main.cpp
)
target_link_libraries(Game
    PRIVATE
        GameCore
        GameEngineLib
)

target_include_directories(Game
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

add_custom_command(TARGET Game POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:GameCore>
        $<TARGET_FILE_DIR:Game>
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:GameEngineLib>
        $<TARGET_FILE_DIR:Game>
)

if (WIN32)
    target_link_options(Game PRIVATE "-municode")
endif ()