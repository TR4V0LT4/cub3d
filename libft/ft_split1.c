/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaadoun <yjaadoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 17:30:27 by yjaadoun          #+#    #+#             */
/*   Updated: 2023/04/16 17:31:02 by yjaadoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nb_words(char const *str, char c)
{
	int	i;
	int	s;
	int	word;

	i = 0;
	word = 0;
	s = 1;
	while (str[i])
	{
		if (str[i] == c)
			s = 1;
		else if (s == 1)
		{
			s = 0;
			word++;
		}
		i++;
	}
	return (word);
}

static int	freemalloc(char **s, int i)
{
	while (i > 0)
	{
		free(s[i - 1]);
		i--;
	}
	free(s);
	return (0);
}

static int	fonction1(char **str, char *s, char c)
{
	int		i;
	int		count;
	int		j;

	j = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		count = 0;
		while (s[i] != c && s[i] != '\0')
		{
			count++;
			i++;
		}
		str[j] = ft_substr(s, i - count, count);
		if (str[j++] == NULL)
			return (freemalloc(str, j));
	}
	str[j] = NULL;
	return (1);
}

char	**ft_split1(char const *s, char c)
{
	char	**res;
	int		words;
	int		check;

	if (!s)
		return (NULL);
	words = nb_words(s, c);
	res = (char **)malloc(sizeof(char *) * (words + 1));
	if (!res)
		return (NULL);
	check = fonction1(res, (char *)s, c);
	if (check == 0)
		return (NULL);
	else
		return (res);
}
