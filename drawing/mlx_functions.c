/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlahyani <wlahyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 00:39:06 by yjaadoun          #+#    #+#             */
/*   Updated: 2023/04/20 08:29:05 by wlahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

t_data	*init_func(t_data *img)
{
	img->height = (img->map->len - 1) * 50;
	img->width = (img->map->long_line) * 50;
	img->map->y = img->map->y_player + 0.5;
	img->map->x = img->map->x_player + 0.5;
	img->mlx = mlx_init();
	img->win = mlx_new_window(img->mlx, 1050, 1050, "CUB3D");
	img->img = mlx_new_image(img->mlx, 1050, 1050);
	return (img);
}

void	ft_images(t_data *img)
{
	img->no.img = mlx_xpm_file_to_image(img->mlx, img->map->no_path,
			&img->no.w, &img->no.h);
	img->ea.img = mlx_xpm_file_to_image(img->mlx, img->map->ea_path,
			&img->ea.w, &img->ea.h);
	img->we.img = mlx_xpm_file_to_image(img->mlx, img->map->we_path,
			&img->we.w, &img->we.h);
	img->so.img = mlx_xpm_file_to_image(img->mlx, img->map->so_path,
			&img->so.w, &img->so.h);
	if (!img->no.img || !img->ea.img || !img->we.img || !img->so.img)
		exit_error("ERROR : MLX");
}

void	raycasting(t_data *img)
{
	img = init_func(img);
	ft_images(img);
	img->height = (img->map->len - 1) * 50;
	img->width = (img->map->long_line) * 50;
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	draw_world(img);
	cast_rays(img);
	destroy_window(img);
	mlx_hook(img->win, 2, 0L, move_player, img);
	mlx_loop(img->mlx);
}
