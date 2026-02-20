#include <windows.h>

#include "Game.h"

int WINAPI wWinMain(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPWSTR lpCmdLine,
    int nShowCmd
) {
    const auto game = new Game();
    return game->Start(hInstance, hPrevInstance, lpCmdLine, nShowCmd);
}
