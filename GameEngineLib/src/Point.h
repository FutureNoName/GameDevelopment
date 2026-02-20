#pragma once
#include <windef.h>

struct Point {
    int x, y;
};


struct Line {
    Point p1, p2;
    COLORREF color;
};