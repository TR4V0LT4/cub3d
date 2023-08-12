/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlahyani <wlahyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 20:09:56 by wlahyani          #+#    #+#             */
/*   Updated: 2023/04/20 02:55:43 by wlahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"    

unsigned int	ea_texture(t_data *img, double x, double y)
{
	char	*dst;

	img->ea.addr = mlx_get_data_addr(img->ea.img, &img->ea.bits_per_pixel,
			&img->ea.line_length, &img->ea.endian);
			
	dst = img->ea.addr + (int)x * img->ea.line_length
		+ (int)y * (img->ea.bits_per_pixel / 8);

	return (*(unsigned int *)dst);
}

unsigned int	no_texture(t_data *img, double x, double y )
{
	char	*dst;

	img->no.addr = mlx_get_data_addr(img->no.img,
			&img->no.bits_per_pixel, &img->no.line_length, &img->no.endian);
	dst = img->no.addr + (int)x * img->no.line_length
		+ (int)y * (img->no.bits_per_pixel / 8);
	return (*(unsigned int *)dst);
}

unsigned int	we_texture(t_data *img, double x, double y)
{
	char	*dst;

	img->we.addr = mlx_get_data_addr(img->we.img, &img->we.bits_per_pixel,
			&img->we.line_length, &img->we.endian);
	dst = img->we.addr + (int)x * img->we.line_length
		+ (int)y * (img->we.bits_per_pixel / 8);
	return (*(unsigned int *)dst);
}

unsigned int	so_texture(t_data *img, double x, double y)
{
	char	*dst;

	img->so.addr = mlx_get_data_addr(img->so.img, &img->so.bits_per_pixel,
			&img->so.line_length, &img->so.endian);
	dst = img->so.addr + (int)x * img->so.line_length
		+ (int)y * (img->so.bits_per_pixel / 8);
	return (*(unsigned int *)dst);
}
