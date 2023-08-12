/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaadoun <yjaadoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 10:21:47 by yjaadoun          #+#    #+#             */
/*   Updated: 2021/11/28 21:06:52 by yjaadoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int	i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (void *)dest;
	str2 = (void *)src;
	if (!str1 && !str2)
		return (0);
	if (!n)
		return (dest);
	while (i < n)
	{
		str1[i] = str2[i];
		i++;
	}
	return (dest);
}
