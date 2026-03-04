#pragma once
#include <vector>
#include <windows.h>

#include "Point.h"

class Renderer {
public:
    void drawLine(Point p1, Point p2, COLORREF color);
    void renderAll(HDC hdc) const;
    void drawTriangle(Point p1, Point p2, Point p3, COLORREF borderColor, COLORREF filligColor);

private:
    std::vector<Line> linesToDraw;
};
