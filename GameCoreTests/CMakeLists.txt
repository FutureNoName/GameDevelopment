add_executable(GameCoreTests
        tests/test.cpp
)

target_link_libraries(GameCoreTests
    PRIVATE
        GameCore
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(GameCoreTests)