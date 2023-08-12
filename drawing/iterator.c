/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlahyani <wlahyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 06:38:51 by wlahyani          #+#    #+#             */
/*   Updated: 2023/04/20 07:36:37 by wlahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	iteration1(t_data *img, t_ray *ray1, float view)
{
	ray1->ry += 1;
	ray1->rx = fabs(fabs(ray1->ry) / tan(view));
	ray1->next_x = floor(img->map->x + ray1->rx);
	ray1->next_y = floor(img->map->y - ray1->ry);
	ray1->ray = sqrt((pow(ray1->ry, 2) + pow(ray1->rx, 2)));
}

void	iteration2(t_data *img, t_ray *ray, float view)
{
	ray->rx += 1;
	ray->ry = ray->rx * tan(view);
	ray->ray = (sqrt(pow(ray->ry, 2) + pow(ray->rx, 2)));
	ray->next_y = floor(img->map->y - ray->ry);
	ray->next_x = floor(img->map->x + ray->rx);
}

void	iteration3(t_data *img, t_ray *ray, float view)
{
	ray->rx += 1;
	ray->ry = ray->rx * tan(M_PI - view);
	ray->ray = (sqrt(pow(ray->ry, 2) + pow(ray->rx, 2)));
	ray->next_y = floor(img->map->y - ray->ry);
	ray->next_x = floor(img->map->x - ray->rx);
}

void	iteration4(t_data *img, t_ray *ray, float view)
{
	ray->ry += 1;
	ray->rx = fabs((fabs(ray->ry) / tan(M_PI - view)));
	ray->next_x = floor(img->map->x - ray->rx);
	ray->next_y = floor(img->map->y - ray->ry);
	ray->ray = sqrt(pow(ray->ry, 2) + pow(ray->rx, 2));
}

void	iteration5(t_data *img, t_ray *ray, float view)
{
	ray->ry += 1;
	ray->rx = fabs((fabs(ray->ry) / tan(M_PI - view)));
	ray->next_x = floor(img->map->x - ray->rx);
	ray->next_y = floor(img->map->y + ray->ry);
	ray->ray = sqrt((pow(ray->ry, 2) + pow(ray->rx, 2)));
}
