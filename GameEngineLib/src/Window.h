#pragma once
#include <windows.h>

class Window {
public:
    Window(HINSTANCE hInstance, int width, int height, LPCSTR title);
    ~Window();

    Window(const Window&) = delete;
    Window(Window&&) = delete;
    Window& operator=(const Window&) = delete;
    Window& operator=(Window&&) = delete;

    void Show(int nShowCmd) const;
    void ResizeWindow(int width, int height) const;
    static bool ProcessMessages();

    [[nodiscard]]
    HWND GetHandle() const;

private:
    HWND hwnd;
    HINSTANCE instance;
    const LPCSTR className = "StartWindow";

    void RegisterWindowClass() const;
    static LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
};
