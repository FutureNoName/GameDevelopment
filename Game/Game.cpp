#include "Window.h"
#include <windows.h>

#include "Renderer.h"

int WINAPI wWinMain(
    const HINSTANCE hInstance,
    const HINSTANCE hPrevInstance,
    const LPWSTR lpCmdLine,
    const int nShowCmd
) {
    constexpr int width = 1920, height = 1080;
    const auto title = L"My Game Window";

    const Window window(hInstance, width, height, title);
    window.Show(nShowCmd);
    
    while (Window::ProcessMessages()) {
        
    }

    return 0;
}
