/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlahyani <wlahyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 21:22:31 by yjaadoun          #+#    #+#             */
/*   Updated: 2023/04/20 02:04:20 by wlahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	check_empty_line(char *map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[0] == '\n' || (map[i] == '\n' && map[i + 1] == '\n')
			|| (map[i] == '\n' && map[i + 1] == '\0'))
			exit_error("empty line in the map\n");
		i++;
	}
}

t_bool	check_elements(char **map)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (!ft_strchr("01NSEW \t", map[i][j]))
				exit_error("ERROR : wrong element\n");
			else if (ft_strchr("NSEW", map[i][j]))
				count++;
			j++;
		}
		i++;
	}
	if (count != 1)
		exit_error("ERROR : wrong element\n");
	return (TRUE);
}

float	start_angle(char c)
{
	float	angle;

	angle = 0.0;
	if (c == 'S')
		angle = (3 * M_PI) / 2;
	else if (c == 'W')
		angle = M_PI;
	else if (c == 'N')
		angle = M_PI / 2;
	else if (c == 'E')
		angle = 2 * M_PI;
	return (angle);
}

void	player_position(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i] != NULL)
	{
		j = 0;
		while (map->map[i][j] != '\0')
		{
			if (ft_strchr("NSEW", map->map[i][j]))
			{
				map->x_player = j ;
				map->y_player = i ;
				map->angle = start_angle(map->map[i][j]);
				map->map[i][j] = '0';
				return ;
			}
			j++;
		}
		i++;
	}
}
