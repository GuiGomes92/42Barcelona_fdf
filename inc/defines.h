/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbraga-g <gbraga-g@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 19:45:45 by gbraga-g          #+#    #+#             */
/*   Updated: 2022/10/03 19:45:48 by gbraga-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
#define DEFINES_H

#define WINX 1600
#define WINY 800

#define bg_color 0xffffff
#define line_color 0x000000

typedef struct s_pointY
{
    int y1;
    int y2;
    int color;

} t_pointY;

typedef struct s_pointX
{
    int x1;
    int x2;
    int color;

} t_pointX;

typedef struct s_vars
{
    void *mlx_ptr;
    void *win_ptr;
} t_vars;

#endif
