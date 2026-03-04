#include "Engine.h"

Engine::Engine(const WindowConfig &config, int showCmd) : window(CreateWindowPlatform(config, showCmd)) {
}

bool Engine::processMessages() const {
    return window->processMessages();
}

void Engine::update() {

}

void Engine::render() {

}
