add_executable(GameEngineTests
    tests/WindowTest.cpp
)

target_link_libraries(GameEngineTests
    PRIVATE
        GameEngineLib
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(GameEngineTests)