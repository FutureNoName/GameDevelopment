#include <windows.h>

#include "Game.h"

int WINAPI wWinMain(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPWSTR lpCmdLine,
    int nShowCmd
) {
    (void)hInstance;
    (void)hPrevInstance;
    (void)lpCmdLine;
    return Game::start(nShowCmd);
}
