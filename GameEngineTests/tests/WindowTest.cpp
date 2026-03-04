#include "gtest/gtest.h"
#include <windows.h>

#include "../../GameEngineLib/src/Window/Windows/WindowWin32.h"

class WindowTest : public testing::Test {
protected:
    std::unique_ptr<WindowWin32> window;
    HINSTANCE hInstance = ::GetModuleHandle(nullptr);

    static WindowConfig getConfig(int width, int height, const char* title) {
        return WindowConfig(width, height, title);
    }
};

TEST_F(WindowTest, Window_IsCreatedWithValidHandle) {
    auto config = getConfig(600, 400, "Valid handle test");
    window = std::make_unique<WindowWin32>(hInstance, config);
    ASSERT_NE(window->getHandle(), nullptr) << "Window handle should not be null after construction";
}

TEST_F(WindowTest, Window_TitleIsCorrectBeforeShow) {
    auto config = getConfig(320, 240, "Title Test");
    window = std::make_unique<WindowWin32>(hInstance, config);

    char actualTitle[256]{};
    GetWindowTextA(window->getHandle(), actualTitle, 256);
    ASSERT_STREQ(config.title, actualTitle) << "Window title should match set value before show";
}

TEST_F(WindowTest, Window_SizeIsCorrectBeforeShow) {
    auto config = getConfig(399, 222, "Size Test");
    window = std::make_unique<WindowWin32>(hInstance, config);
    window->show(SW_SHOW);

    RECT rect;
    GetWindowRect(window->getHandle(), &rect);
    const int width = rect.right - rect.left;
    const int height = rect.bottom - rect.top;

    ASSERT_EQ(config.width, width) << "Window width should match set value before show";
    ASSERT_EQ(config.height, height) << "Window height should match set value before show";
}

TEST_F(WindowTest, Window_CanBeShown) {
    auto config = getConfig(320, 240, "Show Test");
    window = std::make_unique<WindowWin32>(hInstance, config);
    window->show(SW_SHOW);
    SUCCEED();
}


