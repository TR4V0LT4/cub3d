/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaadoun <yjaadoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 13:48:04 by yjaadoun          #+#    #+#             */
/*   Updated: 2021/11/25 13:21:11 by yjaadoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hay, const char *need, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (need[0] == '\0')
		return ((char *)hay);
	while (hay[i] && i < len)
	{
		j = 0;
		if (need[j++] == hay[i])
		{
			while (need[j] && hay[i + j] && need[j] == hay[i + j])
			j++;
			if (!need[j] && (i + j) <= len)
				return ((char *)&hay[i]);
		}
		i++;
	}
	return (0);
}
