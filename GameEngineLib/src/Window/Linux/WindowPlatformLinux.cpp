#include <memory>

#include "WindowLinux.h"
#include "Window/IWindow.h"

std::unique_ptr<IWindow> CreateWindowPlatform(const WindowConfig& config, int showCmd) {
    auto window = std::make_unique<WindowLinux>(config, showCmd);
    window->show(showCmd);
    return window;
}
