/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_elements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlahyani <wlahyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 21:01:36 by yjaadoun          #+#    #+#             */
/*   Updated: 2023/04/20 08:17:09 by wlahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	skip_spaces_begin(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != SPACE && str[i] != TAB)
			return (i);
		else
			i++;
	}
	return (i);
}

void	check_null(t_map *map)
{
	if (!map->we_path || !map->no_path || !map->so_path
		|| !map->ea_path || !map->f_color || !map->c_color)
		exit_error("ERROR : wrong map element ");
}

void	filling_color_textures(t_map *map)
{
	int	j;
	int	i;

	i = 0;
	j = 0;
	while (i < 6)
	{
		j = skip_spaces_begin(map->line[i]);
		if (!ft_strncmp((map->line[i] + j), "WE ", 3))
			map->we_path = check_textures(map->line[i] + j);
		else if (!ft_strncmp((map->line[i] + j), "NO ", 3))
			map->no_path = check_textures(map->line[i] + j);
		else if (!ft_strncmp((map->line[i] + j), "SO ", 3))
			map->so_path = check_textures(map->line[i] + j);
		else if (!ft_strncmp((map->line[i] + j), "EA ", 3))
			map->ea_path = check_textures(map->line[i] + j);
		else if (!ft_strncmp((map->line[i] + j), "F ", 2))
			map->f_color = check_colors(map->line[i] + j);
		else if (!ft_strncmp((map->line[i] + j), "C ", 2))
			map->c_color = check_colors(map->line[i] + j);
		else
			exit_error("ERROR : wrong elements in map\n");
		i++;
	}
	check_null(map);
}

void	filling_map(t_map *map)
{
	int	j;
	int	i;

	i = 6;
	j = 0;
	map->len = doble_arr_len(map->line) - 5;
	map->map = malloc(sizeof(char *) * map->len);
	while (map->line[i] != NULL)
	{
		check_empty_line(map->line[i]);
		map->map[j] = ft_strdup(map->line[i]);
		i++;
		j++;
	}
	ft_free(map->line);
	map->map[j] = NULL;
}

void	map_elements(t_map *map)
{
	filling_color_textures(map);
	filling_map(map);
	check_elements(map->map);
	player_position(map);
	check_border(map);
	map->long_line = longest_line(map->map);
}
