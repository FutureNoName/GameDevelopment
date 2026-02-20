#include <windows.h>

#include "Game.h"

int WINAPI wWinMain(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPWSTR lpCmdLine,
    int nShowCmd
) {
    return Game::start(hInstance, hPrevInstance, lpCmdLine, nShowCmd);
}
