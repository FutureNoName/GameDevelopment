#include "Window.h"
#include <stdexcept>

#include "Renderer.h"

/* ***************************** PUBLIC ***************************** */

/**
 * Window constructor
 * @param hInstance Handle to the application instance; identifies the running app for the OS and provided by it.
 * @param width Width of the window client area in pixels
 * @param height Height of the window client area in pixels
 * @param title Unicode string for the window title displayed in the title bar
 */
Window::Window(
    const HINSTANCE hInstance,
    const int width,
    const int height,
    const wchar_t* title
): m_instance(hInstance) {
    RegisterWindowClass();
    m_hwnd = CreateWindowEx(
        0, // Optional window styles.
        m_className, // Window class
        title, // Window text
        WS_OVERLAPPEDWINDOW, // Window style

        // Size and position
        CW_USEDEFAULT, CW_USEDEFAULT, width, height,

        nullptr, // Parent window
        nullptr, // Menu
        m_instance, // Instance handle
        nullptr // Additional application data
    );

    if (m_hwnd == nullptr) {
        throw std::runtime_error("Failed to create window!");
    }
}

Window::~Window() {
    DestroyWindow(m_hwnd);
}

/**
 * Displays the window
 * @param nShowCmd show command (e.g., SW_SHOW, SW_HIDE)
 */
void Window::Show(const int nShowCmd) const {
    ShowWindow(m_hwnd, nShowCmd);
}

/**
 * Resize window
 * @param width window width (x)
 * @param height window height (y)
 */
void Window::ResizeWindow(const int width, const int height) const {
    RECT rect;
    GetWindowRect(m_hwnd, &rect);
    SetWindowPos(
        m_hwnd,
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
bool Window::ProcessMessages() {
    MSG msg = {};
    while (GetMessage(&msg, nullptr, 0, 0) > 0) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return false;
}

/**
 * Handle getter
 * @return handle to the window 
 */
HWND Window::GetHandle() const {
    return m_hwnd;
}

/* ***************************** PRIVATE ***************************** */

void Window::RegisterWindowClass() const {
    WNDCLASS wc = {};

    wc.lpfnWndProc = WindowProc;
    wc.hInstance = m_instance;
    wc.lpszClassName = m_className;

    RegisterClass(&wc);
}

LRESULT CALLBACK Window::WindowProc(const HWND hwnd, const UINT uMsg, const WPARAM wParam, const LPARAM lParam) {
    switch (uMsg) {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;

    case WM_PAINT: {
        PAINTSTRUCT ps;
        const HDC hdc = BeginPaint(hwnd, &ps);

        FillRect(hdc, &ps.rcPaint, GetSysColorBrush(COLOR_WINDOW));

        // All painting occurs here, between BeginPaint and EndPaint.
        Renderer renderer;
        renderer.DrawLine({0, 0}, {100, 50}, RGB(0, 0, 0));
        Point p1 = {100, 75};
        Point p2 = {200, 100};
        Point p3 = {150, 200};
        renderer.DrawTriangle(p1, p2, p3, RGB(0, 0, 0), RGB(0, 0, 0));
        renderer.RenderAll(hdc);

        EndPaint(hwnd, &ps);
    }
        return 0;

    default:
        return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
}
