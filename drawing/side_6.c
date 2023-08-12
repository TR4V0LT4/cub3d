/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays_utiles1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlahyani <wlahyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 07:13:20 by wlahyani          #+#    #+#             */
/*   Updated: 2023/04/20 08:09:26 by wlahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	init_val6(t_data *img, t_ray *ray, float view)
{
	ray->line = ceil(img->map->y);
	ray->ry = (float)ray->line - img->map->y;
	ray->rx = ray->ry * tan(((3 * M_PI) / 2) - view);
	ray->ray = (sqrt(pow(ray->ry, 2) + pow(ray->rx, 2)));
	ray->next_y = floor(img->map->y + ray->ry);
	ray->next_x = floor(img->map->x - ray->rx);
	if ((ray->next_y < (img->height / 50) && ray->next_y > 0)
		&& (ray->next_x < (img->width / 50) && ray->next_x >= 0))
		if (img->map->map[ray->next_y][ray->next_x] == '1')
			return (1);
	return (0);
}

void	iteration6(t_data *img, t_ray *ray, float view)
{
	ray->ry += 1;
	ray->rx = (ray->ry * tan(((3 * M_PI) / 2) - view));
	ray->next_x = floor(img->map->x - ray->rx);
	ray->next_y = floor(img->map->y + ray->ry);
	ray->ray = sqrt(pow(ray->ry, 2) + pow(ray->rx, 2));
}

double	cast_rays6(t_data *img, float view, double *r)
{
	t_ray	ray;

	if (init_val6(img, &ray, view))
	{
		*r = ((img->map->x - ray.rx) - (int)(img->map->x - ray.rx));
		return (ray.ray);
	}
	while (TRUE)
	{	
		iteration6(img, &ray, view);
		if ((ray.next_y < ((img->height / 50)) && ray.next_y > 0)
			&& (ray.next_x < (img->width / 50) && ray.next_x >= 0))
		{
			if (img->map->map[ray.next_y][ray.next_x] == '1')
			{
				*r = ((img->map->x - ray.rx) - (int)(img->map->x - ray.rx));
				break ;
			}
		}
		else
			break ;
	}
	return (ray.ray);
}
