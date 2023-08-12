#include "../cub.h"

void	iteration3(t_data *img, t_ray *ray, float view)
{
	ray->rx += 1;
	ray->ry = ray->rx * tan(M_PI - view);
	ray->ray = (sqrt(pow(ray->ry, 2) + pow(ray->rx, 2)));
	ray->next_y = floor(img->map->y - ray->ry);
	ray->next_x = floor(img->map->x - ray->rx);
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