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
#include <stdio.h>

typedef struct s_vars
{
	void *mlx_ptr;
	void *win_ptr;
} t_vars;

int close(int keycode, t_vars *vars)
{
	mlx_destroy_window(vars->mlx_ptr, vars->mlx_ptr);
	printf("%s", "Hello");
	printf("%i", keycode);
	return (0);
}

int main(void)
{
	t_vars vars;
	void *image;
	int pixel_bits;
	int line_bytes;
	int endian;
	char *buffer;
	int color = 0xFFFFFF;

	vars.mlx_ptr = mlx_init();
	vars.win_ptr = mlx_new_window(vars.mlx_ptr, 1000, 1000, "My first window");
	image = mlx_new_image(vars.mlx_ptr, 1000, 1000);
	buffer = mlx_get_data_addr(image, &pixel_bits, &line_bytes, &endian);

	if (pixel_bits != 32)
		color = mlx_get_color_value(vars.mlx_ptr, color);

	for (int y = 0; y < 1000; ++y)
		for (int x = 0; x < 1000; ++x)
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
	mlx_put_image_to_window(vars.mlx_ptr, vars.win_ptr, image, 0, 0);

	mlx_hook(vars.win_ptr, 2, 0, close, &vars);
	mlx_loop(vars.mlx_ptr);
}
