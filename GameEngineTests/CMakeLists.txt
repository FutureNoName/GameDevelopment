add_executable(GameEngineTests
    tests/WindowTest.cpp
)

target_link_libraries(GameEngineTests
    PRIVATE
        GameEngineLib
        GTest::gtest_main
)

add_custom_command(TARGET GameEngineTests POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:GameEngineLib>
        $<TARGET_FILE_DIR:GameEngineTests>
)

include(GoogleTest)
gtest_discover_tests(GameEngineTests)