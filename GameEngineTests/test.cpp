#include "gtest/gtest.h"

#include "Window.h"
#include <windows.h>

class WindowTest : public testing::Test {
protected:
    std::unique_ptr<Window> m_window;
    HINSTANCE m_hInstance;

    WindowTest(): m_hInstance(::GetModuleHandle(nullptr)) {}

    void SetUp() override {
        m_hInstance = ::GetModuleHandle(nullptr);
    }
};

TEST_F(WindowTest, Window_IsCreatedWithValidHandle) {
    m_window = std::make_unique<Window>(m_hInstance, 800, 600, L"Test Window");
    ASSERT_NE(m_window->GetHandle(), nullptr) << "Window handle should not be null after construction";
}

TEST_F(WindowTest, Window_TitleIsCorrectBeforeShow) {
    auto expectedTitle = L"My Test Window";
    m_window = std::make_unique<Window>(m_hInstance, 400, 300, expectedTitle);

    wchar_t actualTitle[256]{};
    GetWindowTextW(m_window->GetHandle(), actualTitle, 256);
    ASSERT_EQ(expectedTitle, std::wstring(actualTitle)) << "Window title should match set value before show";
}

TEST_F(WindowTest, Window_SizeIsCorrectBeforeShow) {
    constexpr int expectedWidth = 640, expectedHeight = 480;
    m_window = std::make_unique<Window>(m_hInstance, expectedWidth, expectedHeight, L"Size Test");
    m_window->Show(SW_SHOW);

    RECT rect;
    GetWindowRect(m_window->GetHandle(), &rect);
    const int width = rect.right - rect.left;
    const int height = rect.bottom - rect.top;

    ASSERT_EQ(expectedWidth, width) << "Window width should match set value before show";
    ASSERT_EQ(expectedHeight, height) << "Window height should match set value before show";
}

TEST_F(WindowTest, Window_CanBeShown) {
    m_window = std::make_unique<Window>(m_hInstance, 320, 240, L"Show Test");
    m_window->Show(SW_SHOW);
    SUCCEED();
}
