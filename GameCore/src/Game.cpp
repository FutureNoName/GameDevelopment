//
// Created by j-kon on 20.02.2026.
//

#include "Engine.h"
#include "Window.h"

class Game {
public:
    static int Start(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nShowCmd) {
        const auto engine = new Engine();
        engine->Start(hInstance, hPrevInstance, lpCmdLine, nShowCmd);

        while (Window::ProcessMessages()) {

        }

        return 0;
    }
};
