/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlahyani <wlahyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 14:54:41 by yjaadoun          #+#    #+#             */
/*   Updated: 2023/04/20 07:19:45 by wlahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	move_player(int keycode, t_data *img)
{
	if (keycode == W_KEY)
		move_player_w(img);
	if (keycode == A_KEY)
		move_player_a(img);
	if (keycode == D_KEY)
		move_player_d(img);
	if (keycode == S_KEY)
		move_player_s(img);
	if (keycode == ESC_KEY)
		close_window(img);
	if (keycode == 124)
		turn_right(img);
	if (keycode == 123)
		turn_left(img);
	draw_world(img);
	cast_rays(img);
	return (0);
}

void	move_player_w(t_data *img)
{
	float	x;
	float	y;

	y = img->map->y;
	x = img->map->x;
	img->map->y -= sin(img->map->angle - (M_PI / 6)) / 5 ;
	img->map->x += cos(img->map->angle - (M_PI / 6)) / 5;
	if (img->map->map[(int)(img->map->y)][(int)img->map->x] == '1')
	{
		img->map->y = y ;
		img->map->x = x ;
	}
}

void	move_player_s(t_data *img)
{
	float	x;
	float	y;

	y = img->map->y;
	x = img->map->x;
	img->map->y += sin(img->map->angle - (M_PI / 6));
	img->map->x -= cos(img->map->angle - (M_PI / 6));
	if (img->map->map[(int)(img->map->y)][(int)img->map->x] == '1')
	{
		img->map->y = y;
		img->map->x = x;
	}
}

void	move_player_a(t_data *img)
{
	float	x;
	float	y;

	y = img->map->y;
	x = img->map->x;
	img->map->y += sin(img->map->angle - ((M_PI / 2) + (M_PI / 6))) / 10 ;
	img->map->x -= cos(img->map->angle - ((M_PI / 2) + (M_PI / 6))) / 10;
	if (img->map->map[(int)img->map->y][(int)img->map->x] == '1' )
	{
		img->map->y = y ;
		img->map->x = x ;
	}
}

void	move_player_d(t_data *img)
{
	float	x;
	float	y;

	y = img->map->y;
	x = img->map->x;
	img->map->y -= sin(img->map->angle - ((M_PI / 2) + (M_PI / 6))) / 10;
	img->map->x += cos(img->map->angle - ((M_PI / 2) + (M_PI / 6))) / 10;
	if (img->map->map[(int)img->map->y][(int)img->map->x] == '1')
	{
		img->map->y = y;
		img->map->x = x;
	}
}
