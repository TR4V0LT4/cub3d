/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlahyani <wlahyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 15:13:40 by yjaadoun          #+#    #+#             */
/*   Updated: 2023/04/20 02:20:15 by wlahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	start(t_data *img)
{
	img = init_func(img);
	ft_images(img);
	img->height = (img->map->len - 1) * 50;
	img->width = (img->map->long_line) * 50;
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	background(img);
	raycasting(img);
	destroy_window(img);
	mlx_hook(img->win, 2, 0L, move_player, img);
	mlx_loop(img->mlx);
}

void	raycasting(t_data *img)
{
	double	i;

	i = 0;
	img->map->index = 0;
	mlx_clear_window(img->mlx, img->win);
	while (i < M_PI / 3)
	{
		img->map->view = img->map->angle - i;
		if (img->map->view >= (2 * M_PI))
			img->map->view -= (2 * M_PI);
		if (img->map->view < 0)
			img->map->view += 2 * M_PI;
		if (img->map->view >= 0 && img->map->view <= (M_PI / 2))
			up_right_rays(img);
		else if (img->map->view > (M_PI / 2) && img->map->view < M_PI)
			up_left_rays(img);
		else if (img->map->view >= M_PI && img->map->view < ((3 * M_PI) / 2))
			down_left_rays(img);
		else if (img->map->view >= ((3 * M_PI) / 2)
			&& img->map->view <= M_PI * 2)
			down_right_rays(img);
		i += (M_PI / 3) / 1050;
		img->map->index += 1;
	}
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
}

void	up_right_rays(t_data *img)
{
	double	ray1;
	double	ray2;
	double	rx;
	double	ry;

	ray1 = cast_rays1(img, img->map->view, &rx);
	ray2 = cast_rays2(img, img->map->view, &ry);
	if (ray2 && ray1 > ray2)
		dala(img, ray2, EAST, ry * img->ea.w);
	else
		dala(img, ray1, NORTH, rx * img->no.w);
}

void	up_left_rays(t_data *img)
{
	double	ray3;
	double	ray4;
	double	rx;
	double	ry;

	ray4 = cast_rays4(img, img->map->view, &ry);
	ray3 = cast_rays3(img, img->map->view, &rx);
	if (ray3 && ray4 > ray3)
		dala(img, ray3, WEST, rx * img->we.w);
	else
		dala(img, ray4, NORTH, ry * img->no.w);
}

void	down_right_rays(t_data *img)
{
	double	ray2;
	double	ray6;
	double	ry;
	double	rx;

	ray6 = cast_rays6(img, img->map->view, &ry);
	ray2 = cast_rays2(img, img->map->view, &rx);
	if (ray2 && ray6 > ray2)
		dala(img, ray2, EAST, rx * img->ea.w);
	else
		dala(img, ray6, SOUTH, ry * img->so.w);
}

void	down_left_rays(t_data *img)
{
	double	ray3;
	double	ray5;
	double	rx;
	double	ry;

	ray5 = cast_rays5(img, img->map->view, &ry);
	ray3 = cast_rays3(img, img->map->view, &rx);
	if (ray3 && ray5 > ray3)
		dala(img, ray3, WEST, rx * img->we.w);
	else
		dala(img, ray5, SOUTH, ry * img->so.w);
}

