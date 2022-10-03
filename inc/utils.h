#ifndef UTILS_H
#define UTILS_H
#include "../inc/defines.h"

void draw(char *buffer, int color, int endian, int line_bytes);
void draw_line(void *mlx, void *win, t_pointX x, t_pointY y);

#endif