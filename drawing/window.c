/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlahyani <wlahyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 19:17:42 by yjaadoun          #+#    #+#             */
/*   Updated: 2023/04/20 08:26:33 by wlahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	close_window(t_data *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

int	esc_key(int key, t_data *game)
{
	if (key == 53)
		close_window(game);
	return (0);
}

int	cross_key(void)
{
	exit(1);
}

void	destroy_window(t_data *game)
{
	mlx_hook(game->win, 2, 1L << 0, &esc_key, game);
	mlx_hook(game->win, 17, 1L << 0, &cross_key, game);
}
