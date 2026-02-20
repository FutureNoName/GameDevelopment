#pragma once
#include <windows.h>

#include "WindowConfig.h"
#include "Window.h"

class Engine {
public:
    Engine(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nShowCmd, const WindowConfig &config);
private:
    Window window;
};
