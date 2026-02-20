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
    
    while (Window::ProcessMessages()) {
        
    }

    return 0;
}
