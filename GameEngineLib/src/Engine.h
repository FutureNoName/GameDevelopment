#pragma once
#include <windows.h>

class Engine {
public:
    int Start(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nShowCmd);
    void Update();
};
