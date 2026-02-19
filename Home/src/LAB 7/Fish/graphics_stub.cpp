#include <iostream>
#include "graphics.h"

void initgraph(int *gd, int *gm, const char *path) {
    std::cout << "[graphics] initgraph called (fish)\n";
}

void closegraph() { std::cout << "[graphics] closegraph (fish)\n"; }

void setcolor(int color) { (void)color; }

void line(int x1,int y1,int x2,int y2) {
    std::cout << "[graphics] line " << x1 << "," << y1 << " to " << x2 << "," << y2 << "\n";
}

void ellipse(int x,int y,int st,int end,int a,int b) {
    std::cout << "[graphics] ellipse at " << x << "," << y << "\n";
}

void arc(int x,int y,int st,int end,int r) {
    std::cout << "[graphics] arc at " << x << "," << y << " radius " << r << "\n";
}

void circle(int x,int y,int r) {
    std::cout << "[graphics] circle at " << x << "," << y << " r=" << r << "\n";
}

void outtextxy(int x,int y, const char* text) {
    std::cout << "[graphics] text(" << x << "," << y << "): " << text << "\n";
}
