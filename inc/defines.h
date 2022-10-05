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

#define WINX 1920
#define WINY 1080

#define bg_color 0x000000
#define line_color 0xF72811

typedef struct s_pointY
{
    float y1;
    float y2;

} t_pointY;

typedef struct s_pointX
{
    float x1;
    float x2;
    int color;

} t_pointX;

typedef struct s_vars
{
    void *mlx_ptr;
    void *win_ptr;
} t_vars;

#endif
