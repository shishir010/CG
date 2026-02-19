#ifndef GRAPHICS_H
#define GRAPHICS_H

#define DETECT 0

#ifdef __cplusplus
extern "C" {
#endif

void initgraph(int *gd, int *gm, const char *path);
void closegraph();
void setcolor(int color);
void line(int x1,int y1,int x2,int y2);
void ellipse(int x,int y,int st,int end,int a,int b);
void arc(int x,int y,int st,int end,int r);
void circle(int x,int y,int r);
void outtextxy(int x,int y, const char* text);
void detectgraph(int *graphdriver, int *graphmode);
int getpixel(int x,int y);
void putpixel(int x,int y,int color);
void delay(int ms);
void rectangle(int left,int top,int right,int bottom);
void cleardevice();

#ifdef __cplusplus
}
#endif

#endif
