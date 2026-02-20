#include "gtest/gtest.h"
#include <windows.h>

#include "src/Window.h"

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
    window = std::make_unique<Window>(hInstance, 800, 600, L"Test Window");
    ASSERT_NE(window->GetHandle(), nullptr) << "Window handle should not be null after construction";
}

TEST_F(WindowTest, Window_TitleIsCorrectBeforeShow) {
    auto expectedTitle = L"My Test Window";
    window = std::make_unique<Window>(hInstance, 400, 300, expectedTitle);

    wchar_t actualTitle[256]{};
    GetWindowTextW(window->GetHandle(), actualTitle, 256);
    ASSERT_EQ(expectedTitle, std::wstring(actualTitle)) << "Window title should match set value before show";
}

TEST_F(WindowTest, Window_SizeIsCorrectBeforeShow) {
    constexpr int expectedWidth = 640, expectedHeight = 480;
    window = std::make_unique<Window>(hInstance, expectedWidth, expectedHeight, L"Size Test");
    window->Show(SW_SHOW);

    RECT rect;
    GetWindowRect(window->GetHandle(), &rect);
    const int width = rect.right - rect.left;
    const int height = rect.bottom - rect.top;

    ASSERT_EQ(expectedWidth, width) << "Window width should match set value before show";
    ASSERT_EQ(expectedHeight, height) << "Window height should match set value before show";
}

TEST_F(WindowTest, Window_CanBeShown) {
    window = std::make_unique<Window>(hInstance, 320, 240, L"Show Test");
    window->Show(SW_SHOW);
    SUCCEED();
}
