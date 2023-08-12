/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaadoun <yjaadoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 11:31:54 by yjaadoun          #+#    #+#             */
/*   Updated: 2021/11/29 13:59:08 by yjaadoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	i;

	i = ((int)ft_strlen(str));
	while (i >= 0)
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
		else
			i--;
	}
	return (NULL);
}
