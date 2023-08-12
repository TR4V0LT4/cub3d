/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlahyani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 21:39:14 by wlahyani          #+#    #+#             */
/*   Updated: 2023/04/20 05:49:02 by wlahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s1)
{
	char	*t;

	t = malloc(ft_strlen(s1) + 1);
	if (!t)
		return (0);
	ft_memcpy(t, s1, ft_strlen(s1) + 1);
	return (t);
}

char	*ft_g_strjoin(char const *s1, char const *s2)
{
	char	*t;
	int		len;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2);
	t = (char *)malloc(sizeof(char) * len + 1);
	if (!t)
		return (0);
	while (s1[i])
	{
		t[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		t[i++] = s2[j++];
	t[i] = '\0';
	return (t);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*t;
	size_t	i;
	size_t	s_len;

	if (!s)
		return (0);
	s_len = ft_strlen(s);
	i = 0;
	if (s_len < len)
		len = s_len;
	t = malloc(len + 1);
	if (!t)
		return (0);
	while (s[i] && (i < len) && start < s_len)
	{
		t[i] = s[start];
		start++;
		i++;
	}
	t[i] = '\0';
	return (t);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*n_dst;
	unsigned char	*n_src;

	n_dst = (unsigned char *)dst;
	n_src = (unsigned char *)src;
	i = 0;
	if (src != dst)
	{
		if ((!src && n == 0) || (!src && !dst && n != 0))
			return (NULL);
		while (i < n)
		{
			n_dst[i] = n_src[i];
			i++;
		}
	}
	return (dst);
}
