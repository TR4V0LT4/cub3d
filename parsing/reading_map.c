/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlahyani <wlahyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 20:57:36 by yjaadoun          #+#    #+#             */
/*   Updated: 2023/04/20 09:15:57 by wlahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

char	**split_map(char *buf)
{
	char	**line;

	line = ft_split(buf, '\n');
	if (!line)
		exit_error("ERROR : Empty file\n");
	free(buf);
	return (line);
}

void	f_free(void *tmp, void *current)
{
	free(tmp);
	free(current);
}

char	**get_map(char *av)
{
	char	*buf;
	char	*current;
	char	*tmp;
	int		fd;
	t_bool	n;

	fd = open(av, O_RDWR);
	if (fd < 0)
		exit_error("ERROR : no such file\n");
	buf = 0;
	n = FALSE;
	current = get_next_line(fd);
	while (current)
	{
		if (current[skip_spaces_begin(current)] == '1')
			n = TRUE;
		if (n && current[skip_spaces_begin(current)] == '\n')
			exit_error("ERROR : map not valid");
		tmp = buf;
		buf = ft_strjoin(buf, current);
		f_free(tmp, current);
		current = get_next_line(fd);
	}
	free(current);
	return (split_map(buf));
}
