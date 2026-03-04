#pragma once
#include <memory>

#include "Window/WindowConfig.h"

class IWindow {
public:
    IWindow& operator=(const IWindow&) = delete;
    IWindow& operator=(IWindow&&) = delete;
    virtual ~IWindow() = default;

    virtual void show(int cmdShow) = 0;
    virtual bool processMessages() = 0;
};

std::unique_ptr<IWindow> CreateWindowPlatform(const WindowConfig& config, int showCmd = 0);