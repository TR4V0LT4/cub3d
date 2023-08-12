/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaadoun <yjaadoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:37:17 by yjaadoun          #+#    #+#             */
/*   Updated: 2023/03/03 16:38:46 by yjaadoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	main(int ac, char **av)
{
	t_data	img;

	if (ac == 2)
	{
		if (!check_path(av[1], TRUE))
			exit_error("ERROR : PATH must be *.cub\n");
		img.map = parsing(av[1]);
		raycasting(&img);
	}
	else
		exit_error("ERROR : Enought args [./cub3D map.cub]\n");
}
