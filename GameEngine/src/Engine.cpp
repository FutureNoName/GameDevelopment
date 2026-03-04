#include "Engine.h"

Engine::Engine(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPWSTR lpCmdLine,
    int nShowCmd,
    const WindowConfig &config
    ) : window(hInstance, config.width, config.height, config.title) {
    window.show(nShowCmd);
}

void Engine::update() {

}

void Engine::render() {

}
