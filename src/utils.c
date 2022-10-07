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

void draw_line(void *mlx, void *win, t_point point)
{
    int dx;
    int dy;
    int p;
    int x;
    int y;

    dx = point.x2 - point.x1;
    dy = point.y2 - point.y1;

    x = (int)point.x1;
    y = (int)point.y1;

    p = 2 * dy - dx;

    while (x < (int)point.x2)
    {
        if (p >= 0)
        {
            mlx_pixel_put(mlx, win, x, y, 0x00ffffff);
            y = y + 1;
            p = p + 2 * dy - 2 * dx;
        }
        else
        {
            mlx_pixel_put(mlx, win, x, y, 0xF72811);
            p = p + 2 * dy;
        }
        x = x + 1;
    }
}