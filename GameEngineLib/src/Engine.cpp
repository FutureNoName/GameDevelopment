#include "Engine.h"
#include "Window.h"

int Engine::Start(const HINSTANCE hInstance, const HINSTANCE hPrevInstance, const LPWSTR lpCmdLine, const int nShowCmd) {
    constexpr int width = 1920, height = 1080;
    const auto title = L"My Game Window";

    const Window window(hInstance, width, height, title);
    window.Show(nShowCmd);
    
    MSG msg = {};
    while (GetMessage(&msg, nullptr, 0, 0) > 0) {
        if (msg.message == WM_QUIT) {
            break;
        }
        
        TranslateMessage(&msg);
        DispatchMessage(&msg);

        Update();
    }

    return static_cast<int>(msg.wParam);
}

void Engine::Update() {
    
}
