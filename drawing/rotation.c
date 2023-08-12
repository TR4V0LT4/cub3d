/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlahyani <wlahyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 02:21:51 by wlahyani          #+#    #+#             */
/*   Updated: 2023/04/20 02:23:15 by wlahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	turn_right(t_data *img)
{
	img->map->angle -= 0.1;
	if (img->map->angle < 0)
		img->map->angle += (2 * M_PI);
}

void	turn_left(t_data *img)
{
	img->map->angle += 0.1;
	if (img->map->angle > (2 * M_PI))
		img->map->angle -= (2 * M_PI);
}
