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
    for ( Line line : linesToDraw) {
        HPEN pen = CreatePen(PS_SOLID, 1, line.color);
        HPEN oldPen = static_cast<HPEN>(SelectObject(hdc, pen));
        MoveToEx(hdc, line.p1.x, line.p1.y, nullptr);
        LineTo(hdc, line.p2.x, line.p2.y);
        SelectObject(hdc, oldPen);
        DeleteObject(pen);
    }
}