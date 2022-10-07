/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbraga-g <gbraga-g@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 19:45:34 by gbraga-g          #+#    #+#             */
/*   Updated: 2022/10/03 19:45:36 by gbraga-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
#define UTILS_H
#include "../inc/defines.h"

void draw(char *buffer, int color, int endian, int line_bytes);
void draw_line(void *mlx, void *win, t_point point);

#endif
