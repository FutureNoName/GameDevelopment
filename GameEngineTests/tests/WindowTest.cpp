#include "gtest/gtest.h"
#include <windows.h>

#include "Window.h"

class WindowTest : public testing::Test {
protected:
    std::unique_ptr<Window> window;
    HINSTANCE hInstance;

    WindowTest(): hInstance(::GetModuleHandle(nullptr)) {}

    void SetUp() override {
        hInstance = ::GetModuleHandle(nullptr);
    }
};

TEST_F(WindowTest, Window_IsCreatedWithValidHandle) {
    window = std::make_unique<Window>(hInstance, 800, 600, "Test Window");
    ASSERT_NE(window->GetHandle(), nullptr) << "Window handle should not be null after construction";
}

TEST_F(WindowTest, Window_TitleIsCorrectBeforeShow) {
    auto expectedTitle = "My Test Window";
    window = std::make_unique<Window>(hInstance, 400, 300, expectedTitle);

    char actualTitle[256]{};
    GetWindowTextA(window->GetHandle(), actualTitle, 256);
    ASSERT_STREQ(expectedTitle, actualTitle) << "Window title should match set value before show";
}

TEST_F(WindowTest, Window_SizeIsCorrectBeforeShow) {
    constexpr int expectedWidth = 640, expectedHeight = 480;
    window = std::make_unique<Window>(hInstance, expectedWidth, expectedHeight, "Size Test");
    window->Show(SW_SHOW);

    RECT rect;
    GetWindowRect(window->GetHandle(), &rect);
    const int width = rect.right - rect.left;
    const int height = rect.bottom - rect.top;

    ASSERT_EQ(expectedWidth, width) << "Window width should match set value before show";
    ASSERT_EQ(expectedHeight, height) << "Window height should match set value before show";
}

TEST_F(WindowTest, Window_CanBeShown) {
    window = std::make_unique<Window>(hInstance, 320, 240, "Show Test");
    window->Show(SW_SHOW);
    SUCCEED();
}
