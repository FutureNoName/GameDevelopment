add_executable(GameProjectTests
        tests/test.cpp
)

target_link_libraries(GameProjectTests
    PRIVATE
        GameCore
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(GameProjectTests)