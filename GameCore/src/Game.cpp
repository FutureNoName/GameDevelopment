#include "Game.h"
#include "Engine.h"

int Game::start(int showCmd) {
    WindowConfig windowConfig{.width = 1920, .height = 1080, .title = "My Game Window"};
    Engine engine(windowConfig, showCmd);

    while (engine.processMessages()) {
        engine.update();
        engine.render();
    }

    return 0;
}
