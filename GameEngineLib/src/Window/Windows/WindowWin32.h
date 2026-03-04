#pragma once
#include <windows.h>

#include "Window/IWindow.h"

class WindowWin32 : public IWindow {
public:
    WindowWin32(HINSTANCE hInstance, const WindowConfig &config);

    ~WindowWin32() override;

    WindowWin32(const WindowWin32&) = delete;
    WindowWin32(WindowWin32&&) = delete;
    WindowWin32& operator=(const WindowWin32&) = delete;
    WindowWin32& operator=(WindowWin32&&) = delete;

    void show(int nShowCmd) override;
    void resizeWindow(int width, int height) const;
    bool processMessages() override;

    [[nodiscard]]
    HWND getHandle() const;

private:
    HWND hwnd;
    HINSTANCE instance;
    const LPCSTR className = "StartWindow";

    void registerWindowClass() const;
    static LRESULT CALLBACK windowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
};
