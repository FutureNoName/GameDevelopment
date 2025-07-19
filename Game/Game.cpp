#include "Window.h"
#include <windows.h>

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
        // Game update, rendering, etc. goes here
    }

    return 0;
}
