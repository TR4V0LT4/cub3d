/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaadoun <yjaadoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 14:50:33 by yjaadoun          #+#    #+#             */
/*   Updated: 2023/04/16 17:28:38 by yjaadoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../cub.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	res;
	int	j;

	i = 0;
	j = 0;
	res = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			exit_error("ERROR : invalid color code");
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			res = res * 10 + (str[i] - 48);
			j++;
		}
		else if (!ft_isdigit(str[i]) && j < 3)
			exit_error("ERROR : invalid color code");
		i++;
	}
	return (res);
}
