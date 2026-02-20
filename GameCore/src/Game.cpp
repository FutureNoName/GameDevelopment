#include "Game.h"
#include "Engine.h"

int Game::start(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nShowCmd) {
    WindowConfig windowConfig{.width = 1920, .height = 1080, .title = "My Game Window"};
    const auto engine = new Engine(hInstance, hPrevInstance, lpCmdLine, nShowCmd, windowConfig);

    while (Window::ProcessMessages()) {

    }

    return 0;
}