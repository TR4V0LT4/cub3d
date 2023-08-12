/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlahyani <wlahyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 07:11:50 by wlahyani          #+#    #+#             */
/*   Updated: 2023/04/20 08:01:38 by wlahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

double	cast_rays1(t_data *img, float view, double *r)
{
	t_ray	ray1;

	if (init_val1(img, &ray1, view))
	{
		*r = ((img->map->x + ray1.rx) - (int)(img->map->x + ray1.rx));
		return (ray1.ray);
	}
	while (TRUE)
	{
		iteration1(img, &ray1, view);
		if ((ray1.next_y < (img->height / 50) && ray1.next_y > 0)
			&& (ray1.next_x < (img->width / 50) && ray1.next_x >= 0))
		{	
			if (img->map->map[ray1.next_y - 1][ray1.next_x] == '1')
			{
				*r = (img->map->x + ray1.rx) - (int)(img->map->x + ray1.rx);
				return (ray1.ray);
			}
		}
		else
			break ;
	}
	return (ray1.ray);
}


double	cast_rays2(t_data *img, float view, double *r)
{
	t_ray	ray;

	if (init_val2(img, &ray, view))
	{
		*r = ((img->map->y - ray.ry) - (int)(img->map->y - ray.ry));
		return (ray.ray);
	}
	while (TRUE)
	{
		iteration2(img, &ray, view);
		if ((ray.next_y < ((img->height / 50)) && ray.next_y > 0)
			&& (ray.next_x < (img->width / 50) && ray.next_x >= 0))
		{
			if (img->map->map[ray.next_y][ray.next_x] == '1')
			{
				*r = ((img->map->y - ray.ry) - (int)(img->map->y - ray.ry));
				break ;
			}
		}
		else
			break ;
	}
	return (ray.ray);
}

double	cast_rays3(t_data *img, float view, double *r)
{
	t_ray	ray;

	if (init_val3(img, &ray, view))
	{
		*r = ((img->map->y - ray.ry) - (int)(img->map->y - ray.ry));
		return (ray.ray);
	}
	while (TRUE)
	{	
		iteration3(img, &ray, view);
		if ((ray.next_y < ((img->height / 50)) && ray.next_y > 0)
			&& (ray.next_x < (img->width / 50) && ray.next_x >= 0))
		{
			if (img->map->map[ray.next_y][ray.next_x - 1] == '1')
			{
				*r = ((img->map->y - ray.ry) - (int)(img->map->y - ray.ry));
				break ;
			}
		}
		else
			break ;
	}
	return (ray.ray);
}

double	cast_rays4(t_data *img, float view, double *r)
{	
	t_ray	ray;

	if (init_val4(img, &ray, view))
	{
		*r = (img->map->x - ray.rx) - (int)(img->map->x - ray.rx);
		return (ray.ray);
	}
	while (TRUE)
	{
		iteration4(img, &ray, view);
		if ((ray.next_y < ((img->height / 50)) && ray.next_y > 0)
			&& (ray.next_x < (img->width / 50) && ray.next_x >= 0))
		{
			if (img->map->map[ray.next_y - 1][ray.next_x] == '1')
			{
				*r = (img->map->x - ray.rx) - (int)(img->map->x - ray.rx);
				break ;
			}
		}
		else
			break ;
	}
	return (ray.ray);
}

double	cast_rays5(t_data *img, float view, double *r)
{
	t_ray	ray;

	if (init_val5(img, &ray, view))
	{
		*r = ((img->map->x - ray.rx) - (int)(img->map->x - ray.rx));
		return (ray.ray);
	}
	while (TRUE)
	{				
		iteration5(img, &ray, view);
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
