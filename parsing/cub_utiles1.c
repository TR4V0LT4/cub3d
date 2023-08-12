/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_utiles1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaadoun <yjaadoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 20:59:08 by yjaadoun          #+#    #+#             */
/*   Updated: 2023/04/17 02:45:43 by yjaadoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	print_2d(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
	{
		printf("[%s]\n", str[i]);
		i++;
	}
}

void	exit_error(char	*str)
{
	ft_putstr_fd(str, 2);
	exit(EXIT_FAILURE);
}

int	doble_arr_len(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
		i++;
	return (i);
}

int	longest_line(char **map)
{
	size_t	len;
	int		i;

	i = 0;
	len = ft_strlen(map[i]);
	while (map[i] != NULL)
	{
		if (len < ft_strlen(map[i + 1]))
		{
			len = ft_strlen(map[i + 1]);
			i++;
		}
		else
			i++;
	}
	return ((int)len);
}

int	encode_rgb(int red, int green, int blue)
{
	return ((red << 16) + (green << 8) + (blue));
}
