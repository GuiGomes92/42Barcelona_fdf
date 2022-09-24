#ifndef UTILS_H
#define UTILS_H
#include "../inc/defines.h"

void draw(char *buffer, int color, int endian, int line_bytes);
void draw_line(void *mlx, void *win, int x0, int x1, int y0, int y1, int color);

#endif