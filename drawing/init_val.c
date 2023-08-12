/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_val.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlahyani <wlahyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 06:38:49 by wlahyani          #+#    #+#             */
/*   Updated: 2023/04/20 07:44:32 by wlahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	init_val1(t_data *img, t_ray *ray1, float view)
{
	ray1->line = floor(img->map->y);

	ray1->ry = img->map->y - ray1->line;

	ray1->rx = (ray1->ry / tan(view));
	
	ray1->ray = (sqrt(pow(ray1->ry, 2) + pow(ray1->rx, 2)));
	
	ray1->next_y = floor(img->map->y - ray1->ry);
	ray1->next_x = floor(img->map->x + ray1->rx);
	if ((ray1->next_y < (img->height / 50) && ray1->next_y > 0)
		&& (ray1->next_x < (img->width / 50) && ray1->next_x >= 0))
		if (img->map->map[ray1->next_y - 1][ray1->next_x] == '1')
			return (1);
	return (0);
}

int	init_val2(t_data *img, t_ray *ray, float view)
{
	ray->rx = ceil(img->map->x) - img->map->x;
	ray->ry = ray->rx * tan(view);
	ray->ray = (sqrt(pow(ray->ry, 2) + pow(ray->rx, 2)));
	
	ray->next_y = floor(img->map->y - ray->ry);
	ray->next_x = floor(img->map->x + ray->rx);
	if ((ray->next_y < (img->height / 50) && ray->next_y > 0)
		&& (ray->next_x < (img->width / 50) && ray->next_x >= 0))
		if (img->map->map[ray->next_y][ray->next_x] == '1')
			return (1);
	return (0);
}

int	init_val3(t_data *img, t_ray *ray, float view)
{
	ray->rx = img->map->x - floor(img->map->x);
	ray->ry = ray->rx * tan(M_PI - view);
	ray->ray = (sqrt(pow(ray->ry, 2) + pow(ray->rx, 2)));
	
	ray->next_y = floor(img->map->y - ray->ry);
	ray->next_x = floor(img->map->x - ray->rx);
	if ((ray->next_y < ((img->height / 50)) && ray->next_y > 0)
		&& (ray->next_x < (img->width / 50) && ray->next_x >= 0))
		if (img->map->map[ray->next_y][ray->next_x - 1] == '1')
			return (1);
	return (0);
}

int	init_val4(t_data *img, t_ray *ray, float view)
{
	ray->line = floor(img->map->y);
	ray->ry = img->map->y - (float)ray->line;
	ray->rx = (ray->ry / tan(M_PI - view));
	ray->ray = (sqrt(pow(ray->ry, 2) + pow(ray->rx, 2)));
	
	ray->next_y = floor(img->map->y - ray->ry);
	ray->next_x = floor(img->map->x - ray->rx);
	if ((ray->next_y < ((img->height / 50)) && ray->next_y > 0)
		&& (ray->next_x < (img->width / 50) && ray->next_x >= 0))
		if (img->map->map[ray->next_y - 1][ray->next_x] == '1')
			return (1);
	return (0);
}

int	init_val5(t_data *img, t_ray *ray, float view)
{
	ray->line = ceil(img->map->y);
	ray->ry = (float)ray->line - img->map->y;
	ray->rx = (ray->ry / tan(view - M_PI));
	ray->ray = (sqrt(pow(ray->ry, 2) + pow(ray->rx, 2)));

	ray->next_y = floor(img->map->y + ray->ry);
	ray->next_x = floor(img->map->x - ray->rx);
	if ((ray->next_y < ((img->height / 50)) && ray->next_y > 0)
		&& (ray->next_x < (img->width / 50) && ray->next_x >= 0))
		if (img->map->map[ray->next_y][ray->next_x] == '1')
			return (1);
	return (0);
}
