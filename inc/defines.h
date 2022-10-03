#ifndef DEFINES_H
#define DEFINES_H

#define WINX 1600
#define WINY 800

#define bg_color 0x000000
#define line_color 0xffffff

typedef struct s_pointY
{
    int y1;
    int y2;
    int color;

} t_pointY;

typedef struct s_pointX
{
    int x1;
    int x2;
    int color;

} t_pointX;


typedef struct s_vars
{
    void *mlx_ptr;
    void *win_ptr;
} t_vars;

#endif