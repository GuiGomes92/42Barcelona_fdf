#ifndef DEFINES_H
#define DEFINES_H

#define WINX 1600
#define WINY 800

typedef struct s_pointY
{
    int x1;
    int x2
} t_pointY;

typedef struct s_pointX
{
    int x1;
    int x2
} t_pointX;


typedef struct s_vars
{
    void *mlx_ptr;
    void *win_ptr;
} t_vars;

#endif