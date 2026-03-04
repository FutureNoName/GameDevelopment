#pragma once
#include <windows.h>

#include "Window/WindowConfig.h"
#include "Window/Windows/WindowWin32.h"

class Engine {
public:
    Engine(const WindowConfig &config, int showCmd);

    void update();
    void render();

    [[nodiscard]]
    bool processMessages() const;

private:
    std::unique_ptr<IWindow> window;
};
