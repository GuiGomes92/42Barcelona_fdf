/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbraga-g <gbraga-g@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 20:09:46 by gbraga-g          #+#    #+#             */
/*   Updated: 2022/10/03 19:45:05 by gbraga-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx_macos/mlx.h"
#include "../inc/utils.h"
#include "../inc/hooks.h"
#include "../inc/defines.h"
#include <math.h>
#include <stdio.h>

int main(void)
{
	t_vars vars;
	t_pointX x;
	t_pointY y;
	void *image;
	int pixel_bits;
	int line_bytes;
	int endian;
	char *buffer;

	vars.mlx_ptr = mlx_init();
	vars.win_ptr = mlx_new_window(vars.mlx_ptr, WINX, WINY, "FDF - Gui Gomes");
	image = mlx_new_image(vars.mlx_ptr, WINX, WINY);
	buffer = mlx_get_data_addr(image, &pixel_bits, &line_bytes, &endian);
	x.x1 = 200;
	x.x2 = 400;
	y.y1 = 500;
	y.y2 = 500;
	x.color = line_color;
	// x.color = mlx_get_color_value(vars.mlx_ptr, line_color);
	// if (pixel_bits != 32)
	// 	x.color = mlx_get_color_value(vars.mlx_ptr, line_color);
	draw(buffer, bg_color, endian, line_bytes);
	draw_line(vars.mlx_ptr, vars.win_ptr, x, y);
	mlx_put_image_to_window(vars.mlx_ptr, vars.win_ptr, image, 0, 0);
	mlx_hook(vars.win_ptr, 2, 0, &close, &vars);
	mlx_loop(vars.mlx_ptr);
}