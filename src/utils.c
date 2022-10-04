/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbraga-g <gbraga-g@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 19:44:53 by gbraga-g          #+#    #+#             */
/*   Updated: 2022/10/03 19:44:55 by gbraga-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/defines.h"
#include "../minilibx_macos/mlx.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

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

void draw_line(void *mlx, void *win, t_pointX x_struct, t_pointY y_struct)
{
    int x = 0;
    int y = 0;
    int dx = 0;
    int dy = 0;
    int dx1 = 0;
    int dy1 = 0;
    int px = 0;
    int py = 0;
    int xe = 0;
    int ye = 0;
    int i = 0;
    // Calculate "deltas" of the line (difference between two ending points)
    // Calculate line deltas
    dx = x_struct.x2 - x_struct.x1;
    dy = y_struct.y2 - y_struct.y1;
    // Create a positive copy of deltas (makes iterating easier)
    dx1 = abs(dx);
    dy1 = abs(dy);
    // Calculate error intervals for both axis
    px = (2 * dy1) - dx1;
    py = (2 * dx1) - dy1;
    // The line is X-axis dominant
    if (dy1 <= dx1)
    {
        // Line is drawn left to right
        if (dx >= 0)
        {
            x = x_struct.x1;
            y = y_struct.y1;
            xe = x_struct.x2;
        }
        else
        { // Line is drawn right to left (swap ends)
            x = x_struct.x2;
            y = y_struct.y2;
            xe = x_struct.x1;
        }
        mlx_pixel_put(mlx, win, x, y, x_struct.color); // Draw first pixel
        // Rasterize the line
        i = 0;
        while (x < xe)
        {
            x = x + 1;
            // Deal with octants...
            if (px < 0)
            {
                px = px + 2 * dy1;
            }
            else
            {
                if ((dx < 0 && dy < 0) || (dx > 0 && dy > 0))
                {
                    y = y + 1;
                }
                else
                {
                    y = y - 1;
                }
                px = px + 2 * (dy1 - dx1);
            }
            // Draw pixel from line span at
            // currently rasterized position
            mlx_pixel_put(mlx, win, x, y, x_struct.color);
            i++;
        }
    }
    else
    { // The line is Y-axis dominant
        // Line is drawn bottom to top
        if (dy >= 0)
        {
            x = x_struct.x1;
            y = y_struct.y1;
            ye = y_struct.y2;
        }
        else
        { // Line is drawn top to bottom
            x = x_struct.x2;
            y = y_struct.y2;
            ye = y_struct.y1;
        }
        mlx_pixel_put(mlx, win, x, y, x_struct.color); // Draw first pixel
        // Rasterize the line
        i = 0;
        while (y < ye)
        {
            y = y + 1;
            // Deal with octants...
            if (py <= 0)
            {
                py = py + 2 * dx1;
            }
            else
            {
                if ((dx < 0 && dy < 0) || (dx > 0 && dy > 0))
                {
                    x = x + 1;
                }
                else
                {
                    x = x - 1;
                }
                py = py + 2 * (dx1 - dy1);
            }
            // Draw pixel from line span at
            // currently rasterized position
            mlx_pixel_put(mlx, win, x, y, x_struct.color);
            i++;
        }
    }
}
