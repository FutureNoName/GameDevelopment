#pragma once
#include "Window/IWindow.h"

class WindowLinux : public IWindow{
public:
    WindowLinux(const WindowConfig & config, int showCmd);

    ~WindowLinux() override;

    WindowLinux(const WindowLinux&) = delete;
    WindowLinux(WindowLinux&&) = delete;
    WindowLinux& operator=(const WindowLinux&) = delete;
    WindowLinux& operator=(WindowLinux&&) = delete;

    void show(int showCmd) override;
    bool processMessages() override;
};
