#include "../inc/defines.h"

int close(int keycode, t_vars *vars)
{
    if (keycode == 53)
        mlx_destroy_window(vars->mlx_ptr, vars->win_ptr);
    printf("Keypress: %d\n", keycode);
    return (0);
}