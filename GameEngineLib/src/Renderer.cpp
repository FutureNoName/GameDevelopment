#include "Renderer.h"

#include "Window.h"

void Renderer::DrawLine(Point p1, Point p2, COLORREF color) {
    linesToDraw.push_back({p1, p2, color});
}

void Renderer::DrawTriangle(Point p1, Point p2, Point p3, COLORREF borderColor, COLORREF filligColor) {
    linesToDraw.push_back({p1, p2, borderColor});
    linesToDraw.push_back({p2, p3, borderColor});
    linesToDraw.push_back({p3, p1, borderColor});
    
}


void Renderer::RenderAll(HDC hdc) const {
    for ( auto [p1, p2, color] : linesToDraw) {
        HPEN pen = CreatePen(PS_SOLID, 1, color);
        auto oldPen = static_cast<HPEN>(SelectObject(hdc, pen));
        MoveToEx(hdc, p1.x, p1.y, nullptr);
        LineTo(hdc, p2.x, p2.y);
        SelectObject(hdc, oldPen);
        DeleteObject(pen);
    }
}