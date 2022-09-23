/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbraga-g <gbraga-g@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 20:09:46 by gbraga-g          #+#    #+#             */
/*   Updated: 2022/09/13 20:42:21 by gbraga-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx_macos/mlx.h"
#include "../inc/utils.h"
#include "../inc/hooks.h"
#include "../inc/defines.h"
#include <math.h>
#include <stdio.h>

// int draw_line(void *mlx, void *win, int beginX, int beginY, int endX, int endY, int color)
// {
// 	double deltaX;
// 	double deltaY;
// 	int pixels;
// 	double pixelX;
// 	double pixelY;

// 	deltaX = endX - beginX;
// 	deltaY = endY - beginY;
// 	pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY));

// 	deltaX /= pixels;
// 	deltaY /= pixels;

// 	pixelX = beginX;
// 	pixelY = beginY;

// 	while (pixels)
// 	{
// 		mlx_pixel_put(mlx, win, pixelX, pixelY, color);
// 		pixelX += deltaX;
// 		pixelY += deltaY;
// 		--pixels;
// 	}
// 	return (0);
// }

void draw_line(void *mlx, void *win, int x0, int x1, int y0, int y1, int color)
{
	// Calculate "deltas" of the line (difference between two ending points)
	int dx = x1 - x0;
	int dy = y1 - y0;
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

int main(void)
{
	t_vars vars;
	void *image;
	int pixel_bits;
	int line_bytes;
	int endian;
	char *buffer;
	int color = 0x000000;
	int quarterX = WINX / 4;
	int quarterY = WINY / 4;

	vars.mlx_ptr = mlx_init();
	vars.win_ptr = mlx_new_window(vars.mlx_ptr, WINX, WINY, "My first window");
	image = mlx_new_image(vars.mlx_ptr, WINX, WINY);
	buffer = mlx_get_data_addr(image, &pixel_bits, &line_bytes, &endian);

	if (pixel_bits != 32)
		color = mlx_get_color_value(vars.mlx_ptr, color);
	draw(buffer, color, endian, line_bytes);
	mlx_put_image_to_window(vars.mlx_ptr, vars.win_ptr, image, 0, 0);
	draw_line(vars.mlx_ptr, vars.win_ptr, quarterX, quarterX * 2, quarterY * 2, quarterY * 2, 0xFFFFFF);
	mlx_hook(vars.win_ptr, 2, 0, &close, &vars);
	mlx_loop(vars.mlx_ptr);
}
