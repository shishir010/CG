#include <windows.h>
#include <thread>
#include <cmath>
#include <cstring>
#include "graphics.h"

static HWND g_hwnd = NULL;
static HPEN g_pen = NULL;
static COLORREF g_color = RGB(0,0,0);
static COLORREF g_background = RGB(255,255,255);

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam) {
    switch (msg) {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    default:
        return DefWindowProc(hwnd,msg,wparam,lparam);
    }
}

extern "C" {

void initgraph(int *gd, int *gm, const char *path) {
    (void)gd; (void)gm; (void)path;
    HINSTANCE hInst = GetModuleHandle(NULL);
    const char *clsName = "BGIWindowClass";
    WNDCLASSA wc = {};
    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInst;
    wc.lpszClassName = clsName;
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
    RegisterClassA(&wc);

    g_hwnd = CreateWindowA(clsName, "BGI Window", WS_OVERLAPPEDWINDOW,
        100,100,640,480, NULL, NULL, hInst, NULL);
    ShowWindow(g_hwnd, SW_SHOW);
    UpdateWindow(g_hwnd);

    std::thread([](){ MSG msg; while (GetMessageA(&msg,NULL,0,0)) { TranslateMessage(&msg); DispatchMessageA(&msg); } }).detach();
}

void closegraph() {
    if (g_hwnd) {
        PostMessageA(g_hwnd, WM_CLOSE, 0, 0);
        g_hwnd = NULL;
    }
}

void setcolor(int color) {
    switch (color) {
        case 0: g_color = RGB(0,0,0); break;
        case 1: g_color = RGB(0,0,128); break;
        case 2: g_color = RGB(0,128,0); break;
        case 3: g_color = RGB(0,128,128); break;
        case 4: g_color = RGB(128,0,0); break;
        case 5: g_color = RGB(128,0,128); break;
        case 6: g_color = RGB(128,128,0); break;
        case 7: g_color = RGB(192,192,192); break;
        default: g_color = RGB(0,0,0); break;
    }
    if (g_pen) { DeleteObject(g_pen); g_pen = NULL; }
    g_pen = CreatePen(PS_SOLID, 2, g_color);
}

static COLORREF color_to_ref(int c) {
    switch (c) {
        case 0: return RGB(255,255,255);
        case 1: return RGB(0,0,128);
        case 2: return RGB(0,128,0);
        case 3: return RGB(0,128,128);
        case 4: return RGB(128,0,0);
        case 5: return RGB(128,0,128);
        case 6: return RGB(128,128,0);
        case 7: return RGB(192,192,192);
        case 8: return RGB(128,128,128);
        case 9: return RGB(0,0,255);
        case 10: return RGB(0,255,0);
        case 11: return RGB(0,255,255);
        case 12: return RGB(255,0,0);
        case 13: return RGB(255,0,255);
        case 14: return RGB(255,255,0);
        case 15: return RGB(0,0,0);
        default: return RGB(0,0,0);
    }
}

static int ref_to_index(COLORREF c) {
    if (c == color_to_ref(0)) return 0;
    for (int i=1;i<16;i++) if (c == color_to_ref(i)) return i;
    return 0;
}

void detectgraph(int *graphdriver, int *graphmode) {
    if (graphdriver) *graphdriver = 0;
    if (graphmode) *graphmode = 0;
}

int getpixel(int x,int y) {
    if (!g_hwnd) return 0;
    HDC hdc = GetDC(g_hwnd);
    COLORREF c = GetPixel(hdc, x, y);
    ReleaseDC(g_hwnd, hdc);
    return ref_to_index(c);
}

void putpixel(int x,int y,int color) {
    if (!g_hwnd) return;
    HDC hdc = GetDC(g_hwnd);
    COLORREF cref = color_to_ref(color);
    SetPixelV(hdc, x, y, cref);
    ReleaseDC(g_hwnd, hdc);
}

void delay(int ms) {
    Sleep(ms);
}

void rectangle(int left,int top,int right,int bottom) {
    if (!g_hwnd) return;
    HDC hdc = GetDC(g_hwnd);
    HPEN old = (HPEN)SelectObject(hdc, g_pen ? g_pen : GetStockObject(BLACK_PEN));
    Rectangle(hdc, left, top, right, bottom);
    SelectObject(hdc, old);
    ReleaseDC(g_hwnd, hdc);
}

void cleardevice() {
    if (!g_hwnd) return;
    HDC hdc = GetDC(g_hwnd);
    RECT rc;
    GetClientRect(g_hwnd, &rc);
    HBRUSH brush = CreateSolidBrush(g_background);
    FillRect(hdc, &rc, brush);
    DeleteObject(brush);
    ReleaseDC(g_hwnd, hdc);
}

void line(int x1,int y1,int x2,int y2) {
    if (!g_hwnd) return;
    HDC hdc = GetDC(g_hwnd);
    HPEN old = (HPEN)SelectObject(hdc, g_pen ? g_pen : GetStockObject(BLACK_PEN));
    MoveToEx(hdc, x1, y1, NULL);
    LineTo(hdc, x2, y2);
    SelectObject(hdc, old);
    ReleaseDC(g_hwnd, hdc);
}

void ellipse(int x,int y,int st,int end,int a,int b) {
    (void)st; (void)end;
    if (!g_hwnd) return;
    HDC hdc = GetDC(g_hwnd);
    HPEN old = (HPEN)SelectObject(hdc, g_pen ? g_pen : GetStockObject(BLACK_PEN));
    Ellipse(hdc, x - a, y - b, x + a, y + b);
    SelectObject(hdc, old);
    ReleaseDC(g_hwnd, hdc);
}

void arc(int x,int y,int st,int end,int r) {
    if (!g_hwnd) return;
    double srad = st * M_PI / 180.0;
    double erad = end * M_PI / 180.0;
    int x1 = x + (int)(r * cos(srad));
    int y1 = y - (int)(r * sin(srad));
    int x2 = x + (int)(r * cos(erad));
    int y2 = y - (int)(r * sin(erad));
    HDC hdc = GetDC(g_hwnd);
    HPEN old = (HPEN)SelectObject(hdc, g_pen ? g_pen : GetStockObject(BLACK_PEN));
    Arc(hdc, x - r, y - r, x + r, y + r, x1, y1, x2, y2);
    SelectObject(hdc, old);
    ReleaseDC(g_hwnd, hdc);
}

void circle(int x,int y,int r) {
    if (!g_hwnd) return;
    HDC hdc = GetDC(g_hwnd);
    HPEN old = (HPEN)SelectObject(hdc, g_pen ? g_pen : GetStockObject(BLACK_PEN));
    Ellipse(hdc, x - r, y - r, x + r, y + r);
    SelectObject(hdc, old);
    ReleaseDC(g_hwnd, hdc);
}

void outtextxy(int x,int y, const char* text) {
    if (!g_hwnd) return;
    HDC hdc = GetDC(g_hwnd);
    SetTextColor(hdc, g_color);
    TextOutA(hdc, x, y, text, (int)strlen(text));
    ReleaseDC(g_hwnd, hdc);
}

} // extern "C"

