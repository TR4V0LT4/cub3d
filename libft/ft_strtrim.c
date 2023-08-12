/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaadoun <yjaadoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 12:05:19 by yjaadoun          #+#    #+#             */
/*   Updated: 2023/03/09 16:23:03 by yjaadoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	check_char(char const *str, char c)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == c)
		{
			res = 1;
			break ;
		}
		i++;
	}
	return (res);
}

static	int	check_fst(char const *str, char const *set)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (check_char(set, str[i]) == 1)
			i++;
		else
			return (i);
	}
	return (-1);
}

static	int	check_lst(char const *str, char const *set)
{
	size_t	len_s;

	len_s = ft_strlen(str) - 1;
	while (len_s >= 0)
	{
		if (check_char((char *) set, str[len_s]) == 1)
		len_s--;
		else
			return ((size_t)len_s);
	}
	return (-1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		len_trim;
	char	*res;
	int		index_fst;
	int		index_lst;

	i = 0;
	if (!s1 || !set)
		return (NULL);
	index_fst = check_fst(s1, set);
	if (index_fst == -1)
		return (ft_strdup(""));
	index_lst = check_lst(s1, set);
	len_trim = index_lst - index_fst + 1;
	res = (char *)malloc(len_trim + 1);
	if (!res)
		return (NULL);
	while (index_fst <= index_lst)
	{
		res[i++] = s1[index_fst++];
	}
	res[i] = '\0';
	return (res);
}
