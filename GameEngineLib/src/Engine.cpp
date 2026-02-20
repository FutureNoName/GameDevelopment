#include "Engine.h"

Engine::Engine(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPWSTR lpCmdLine,
    int nShowCmd,
    const WindowConfig &config
    ) : window(hInstance, config.width, config.height, config.title) {
    window.Show(nShowCmd);
}