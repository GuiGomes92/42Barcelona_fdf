#include "../inc/defines.h"
#include "../minilibx_macos/mlx.h"
#include <stdlib.h>

int close(int keycode, t_vars *vars)
{
    if (keycode == 53)
    {
        mlx_destroy_window(vars->mlx_ptr, vars->win_ptr);
    }
    return (0);
}