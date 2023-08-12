/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaadoun <yjaadoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 11:51:43 by yjaadoun          #+#    #+#             */
/*   Updated: 2023/04/15 03:18:05 by yjaadoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../cub.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	size_t			l;
	size_t			i;

	if (!s)
		return (NULL);
	l = ft_strlen(s);
	if (len == 0)
		exit_error("ERROR : code color");
	if (start >= l)
		return (ft_strdup(""));
	if ((l - start) < len)
		sub = (char *)malloc(l - start + 1);
	else
		sub = (char *)malloc(len + 1);
	if (!sub)
		return (0);
	i = 0;
	while (s[i + start] && i < len)
	{
		sub[i] = s[i + start];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
