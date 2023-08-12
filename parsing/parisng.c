/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parisng.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlahyani <wlahyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 13:56:12 by yjaadoun          #+#    #+#             */
/*   Updated: 2023/04/20 08:18:16 by wlahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	initialisation(t_map *map)
{
	map->line = NULL;
	map->map = NULL;
	map->so_path = NULL;
	map->we_path = NULL;
	map->ea_path = NULL;
	map->no_path = NULL;
	map->c_color = 0;
	map->f_color = 0;
	map->long_line = 0;
	map->len = 0;
}

void	fill_back(char **map, int len)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		if (ft_strlen(map[i]) < (size_t)len)
		{
			while ((size_t)j < ft_strlen(map[i]) - (size_t)len)
			{
				tmp = map[i];
				map[i] = ft_strjoin(map[i], "1");
				free(tmp);
				j++;
			}
		}
		i++;
	}
}

void	replace_space(char **map, int len)
{
	int	i;
	int	j;

	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == ' ')
				map[i][j] = '1';
			j++;
		}
		i++;
	}
	fill_back(map, len);
}

t_map	*parsing(char *av)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	initialisation(map);
	map->line = get_map(av);
	map_elements(map);
	replace_space(map->map, map->long_line);
	return (map);
}
