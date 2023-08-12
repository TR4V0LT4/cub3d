/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlahyani <wlahyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 22:03:32 by yjaadoun          #+#    #+#             */
/*   Updated: 2023/04/20 02:03:43 by wlahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

t_bool	is_map_valid(t_map *map)
{
	int	i;
	int	j;

	i = 1;
	while (map->map[i] != NULL)
	{
		j = 1;
		while (map->map[i][j] != '\0')
		{
			if (map->map[i][j] == '0')
			{
				if (ft_strlen(map->map[i - 1]) - 1 < (size_t)j
					|| ft_strlen(map->map[i + 1]) - 1 < (size_t)j)
					return (FALSE);
				else if (!ft_strchr("01", map->map[i][j + 1])
					|| !ft_strchr("01", map->map[i][j - 1])
					|| !ft_strchr("01", map->map[i - 1][j])
					|| !ft_strchr("01", map->map[i + 1][j]))
					return (FALSE);
			}	
			j++;
		}
		i++;
	}
	return (TRUE);
}

t_bool	check_top_bottom(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != '1' && line[i] != SPACE && line[i] != TAB)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

t_bool	check_border_left_and_right(char **map)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	while (map[i] != NULL)
	{
		len = ft_strlen(map[i]);
		if ((map[i][0] != '1' && map[i][0] != SPACE && map[i][0] != TAB)
			|| (map[i][len - 1] != '1' && map[i][len - 1] != SPACE
			&& map[i][len - 1] != TAB))
			return (FALSE);
		i++;
	}
	return (TRUE);
}	

t_bool	check_border(t_map *map)
{
	int	len;

	len = doble_arr_len(map->map);
	if (!check_top_bottom(map->map[0])
		|| !check_top_bottom(map->map[len -1])
		|| !check_border_left_and_right(map->map)
		|| !is_map_valid(map))
		exit_error("ERROR : unclosed map\n");
	return (TRUE);
}
