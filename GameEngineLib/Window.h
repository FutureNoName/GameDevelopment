#pragma once
#include <windows.h>

class Window {
public:
    Window(HINSTANCE hInstance, int width, int height, const wchar_t* title);
    ~Window();

    Window(const Window&) = delete;
    Window(Window&&) = delete;
    Window& operator=(const Window&) = delete;
    Window& operator=(Window&&) = delete;

    void Show(int nShowCmd) const;
    static bool ProcessMessages();

    HWND GetHandle() const;

private:
    HWND m_hwnd;
    HINSTANCE m_instance;
    const wchar_t* m_className = L"StartWindow";

    void RegisterWindowClass() const;
    static LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
};
