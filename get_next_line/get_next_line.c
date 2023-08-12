/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlahyani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 16:07:19 by wlahyani          #+#    #+#             */
/*   Updated: 2023/04/20 05:45:32 by wlahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_g_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == (char)c)
			return (1);
		i++;
	}
	return (0);
}

int	until_new_line(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != '\n')
		i++;
	return (i);
}

char	*ft_helper(int fd, char *t)
{
	char	*h;
	char	*buffer;
	int		r;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (ft_g_strchr(t, '\n') == 0)
	{
		r = read(fd, buffer, BUFFER_SIZE);
		if (r <= 0)
			break ;
		buffer[r] = '\0';
		if (!t)
			t = ft_strdup(buffer);
		else
		{
			h = ft_g_strjoin(t, buffer);
			free(t);
			t = h;
		}
	}
	free(buffer);
	if (!(t))
		return (NULL);
	return (t);
}

char	*get_next_line(int fd)
{
	static char	*t ;
	int			j;
	char		*tmp;
	char		*tmp1;

	if (fd < 0)
		return (NULL);
	t = ft_helper(fd, t);
	j = until_new_line(t);
	tmp = ft_substr(t, 0, j + 1);
	tmp1 = ft_substr(t, j + 1, ft_strlen(t));
	if (!tmp)
		return (NULL);
	free(t);
	if (tmp1[0] == '\0')
	{
		free(tmp1);
		t = NULL;
	}
	else
		t = tmp1;
	return (tmp);
}
