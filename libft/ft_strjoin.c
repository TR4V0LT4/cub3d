/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlahyani <wlahyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 22:44:53 by yjaadoun          #+#    #+#             */
/*   Updated: 2023/04/20 09:10:19 by wlahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_check(char *s1, int *free_s1)
{
	if (s1 == 0)
	{
		s1 = ft_strdup("");
		*free_s1 = 1;
	}
	return (s1);
}

char	*ft_malloc(int len)
{
	char	*res;

	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	return (res);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	int		i;
	int		j;
	size_t	len;
	char	*res;
	int		free_s1;

	free_s1 = 0;
	s1 = ft_check(s1, &free_s1);
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	res = ft_malloc(len);
	i = -1;
	while (s1[++i] != '\0')
		res[i] = s1[i];
	j = 0;
	while (s2[j] != '\0')
	{
		res[i + j] = s2[j];
		++j;
	}
	res[i + j] = '\0';
	if (free_s1)
		free(s1);
	return (res);
}
