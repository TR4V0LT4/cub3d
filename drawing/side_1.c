
#include "../cub.h"

void	iteration1(t_data *img, t_ray *ray1, float view)
{
	ray1->ry += 1;
	ray1->rx = fabs(fabs(ray1->ry) / tan(view));
	ray1->next_x = floor(img->map->x + ray1->rx);
	ray1->next_y = floor(img->map->y - ray1->ry);
	ray1->ray = sqrt((pow(ray1->ry, 2) + pow(ray1->rx, 2)));
}

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