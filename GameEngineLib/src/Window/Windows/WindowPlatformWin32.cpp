#include <memory>
#include <windows.h>

#include "Window/IWindow.h"
#include "WindowWin32.h"

std::unique_ptr<IWindow> CreateWindowPlatform(const WindowConfig& config, int showCmd) {
    HINSTANCE hInstance = GetModuleHandle(nullptr);
    auto win = std::make_unique<WindowWin32>(hInstance, config);
    win->show(showCmd);
    return win;
}