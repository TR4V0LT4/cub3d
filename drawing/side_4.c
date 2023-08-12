
#include "../cub.h"

void	iteration4(t_data *img, t_ray *ray, float view)
{
	ray->ry += 1;
	ray->rx = fabs((fabs(ray->ry) / tan(M_PI - view)));
	ray->next_x = floor(img->map->x - ray->rx);
	ray->next_y = floor(img->map->y - ray->ry);
	ray->ray = sqrt(pow(ray->ry, 2) + pow(ray->rx, 2));
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