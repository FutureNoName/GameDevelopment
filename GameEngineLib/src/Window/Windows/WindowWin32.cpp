#include "WindowWin32.h"
#include <stdexcept>

#include "../../Renderer.h"

/**
 * Window constructor
 * @param hInstance Handle to the application instance; identifies the running app for the OS and provided by it.
 * @param config Includes window width, height and title
 */
WindowWin32::WindowWin32(
    HINSTANCE hInstance,
    const WindowConfig &config
) : instance(hInstance) {
    registerWindowClass();
    hwnd = CreateWindowEx(
        0, // Optional window styles.
        className, // Window class
        config.title, // Window text
        WS_OVERLAPPEDWINDOW, // Window style

        // Size and position
        CW_USEDEFAULT, CW_USEDEFAULT, config.width, config.height,

        nullptr, // Parent window
        nullptr, // Menu
        instance, // Instance handle
        nullptr // Additional application data
    );

    if (hwnd == nullptr) {
        throw std::runtime_error("Failed to create window!");
    }
}

WindowWin32::~WindowWin32() {
    DestroyWindow(hwnd);
}

/* ***************************** PUBLIC ***************************** */

/**
 * Displays the window
 * @param nShowCmd show command (e.g., SW_SHOW, SW_HIDE)
 */
void WindowWin32::show(const int nShowCmd) {
    ShowWindow(hwnd, nShowCmd);
}

/**
 * Resize window
 * @param width window width (x)
 * @param height window height (y)
 */
void WindowWin32::resizeWindow(const int width, const int height) const {
    RECT rect;
    GetWindowRect(hwnd, &rect);
    SetWindowPos(
        hwnd,
        nullptr,
        rect.left,
        rect.top,
        width,
        height,
        SWP_NOZORDER | SWP_NOACTIVATE
        );
}

/**
 * Runs the message loop and processes all incoming Windows messages
 * @return false when a WM_QUIT message is received, indicating the application should exit
 */
bool WindowWin32::processMessages() {
    MSG msg = {};
    while (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE)) {
        if (msg.message == WM_QUIT) {
            return false;
        }

        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return true;
}

/**
 * Handle getter
 * @return handle to the window 
 */
HWND WindowWin32::getHandle() const {
    return hwnd;
}

/**
 * Handles different window messages that get send by Windows
 * @param hwnd window handle
 * @param uMsg Windows message
 * @param wParam first param 
 * @param lParam second param
 * @return 
 */
LRESULT CALLBACK WindowWin32::windowProc(HWND hwnd, const UINT uMsg, const WPARAM wParam, const LPARAM lParam) {
    switch (uMsg) {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;

    case WM_PAINT: {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);

        FillRect(hdc, &ps.rcPaint, GetSysColorBrush(COLOR_WINDOW));
        HBRUSH brush = CreateSolidBrush(000);
        RECT clientRect;
        GetClientRect(hwnd, &clientRect);
        RECT rectToDraw;
        const int rectWidth = (clientRect.right - clientRect.left) / 2;
        const int rectHeight = (clientRect.bottom - clientRect.top) / 2;
        
        rectToDraw.left = (clientRect.right - clientRect.left - rectWidth) / 2;
        rectToDraw.right = rectToDraw.left + rectWidth;
        rectToDraw.top = (clientRect.bottom - clientRect.top - rectHeight) / 2;
        rectToDraw.bottom = rectToDraw.top + rectHeight;
        FillRect(hdc, &rectToDraw, brush);
        
        Renderer renderer;
        renderer.DrawLine({0, 0}, {100, 50}, RGB(0, 0, 0));
        constexpr Point p1 = {.x = 100, .y = 75}, p2 = {.x = 200, .y = 100}, p3 = {.x = 150, .y = 200};
        renderer.DrawTriangle(p1, p2, p3, RGB(0, 0, 0), RGB(0, 0, 0));
        renderer.RenderAll(hdc);

        EndPaint(hwnd, &ps);
    }
        return 0;

    case WM_SIZE:
        InvalidateRect(hwnd, nullptr, true);
        return 0;       
    default:
        return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
}

/* ***************************** PRIVATE ***************************** */

void WindowWin32::registerWindowClass() const {
    WNDCLASS wc = {};

    wc.lpfnWndProc = windowProc;
    wc.hInstance = instance;
    wc.lpszClassName = className;

    RegisterClass(&wc);
}