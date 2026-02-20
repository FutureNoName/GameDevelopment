#pragma once
#include <vector>
#include <windows.h>

#include "Point.h"

class Renderer {
public:
    void DrawLine(Point p1, Point p2, COLORREF color);
    void RenderAll(HDC hdc) const;
    void DrawTriangle(Point p1, Point p2, Point p3, COLORREF borderColor, COLORREF filligColor);

private:
    std::vector<Line> linesToDraw;
};
