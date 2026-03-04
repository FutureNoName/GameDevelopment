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

    void show(int nShowCmd) const;
    void resizeWindow(int width, int height) const;
    static bool processMessages();

    [[nodiscard]]
    HWND getHandle() const;

private:
    HWND hwnd;
    HINSTANCE instance;
    const LPCSTR className = "StartWindow";

    void registerWindowClass() const;
    static LRESULT CALLBACK windowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
};
