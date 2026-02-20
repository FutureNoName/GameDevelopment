#include <windows.h>

#include "src/Renderer.h"
#include "src/Engine.h"
#include "src/Window.h"

int WINAPI wWinMain(
    const HINSTANCE hInstance,
    const HINSTANCE hPrevInstance,
    const LPWSTR lpCmdLine,
    const int nShowCmd
) {
    const auto engine = new Engine();
    engine->Start(hInstance, hPrevInstance, lpCmdLine, nShowCmd);
    
    constexpr int width = 1920, height = 1080;
    const auto title = L"My Game Window";

    const Window window(hInstance, width, height, title);
    window.Show(nShowCmd);
    
    while (Window::ProcessMessages()) {
        
    }

    return 0;
}
