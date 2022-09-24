#include "../inc/defines.h"
#include "../minilibx_macos/mlx.h"

void draw(char *buffer, int color, int endian, int line_bytes)
{
    for (int y = 0; y < WINY; ++y)
        for (int x = 0; x < WINX; ++x)
        {
            int pixel = (y * line_bytes) + (x * 4);

            if (endian == 1) // Most significant (Alpha) byte first
            {
                buffer[pixel + 0] = (color >> 24);
                buffer[pixel + 1] = (color >> 16) & 0xFF;
                buffer[pixel + 2] = (color >> 8) & 0xFF;
                buffer[pixel + 3] = (color)&0xFF;
            }
            else if (endian == 0) // Least significant (Blue) byte first
            {
                buffer[pixel + 0] = (color)&0xFF;
                buffer[pixel + 1] = (color >> 8) & 0xFF;
                buffer[pixel + 2] = (color >> 16) & 0xFF;
                buffer[pixel + 3] = (color >> 24);
            }
        }
}

void draw_line(void *mlx, void *win, int x0, int x1, int y0, int y1, int color)
{
    int x;
    int y;
    int dx;
    int dy;
    int dx1;
    int dy1;
    int px;
    int py;
    int xe;
    int ye;
    int i;
    // Calculate "deltas" of the line (difference between two ending points)
    dx = x1 - x0;
    dy = y1 - y0;

    if (dx < 0)
        dx = dx * -1 if (dy < 0)
                      dy = dx *-1
            // Calculate the line equation based on deltas
            int D = (2 * dy) - dx;
    int y = y0;
    // Draw the line based on arguments provided
    int x;
    x = x0;
    while (x < x1)
    {
        // Place pixel on the raster display
        mlx_pixel_put(mlx, win, x, y, color);
        if (D >= 0)
        {
            y = y + 1;
            D = D - 2 * dx;
        }
        D = D + 2 * dy;
        x++;
    }
};