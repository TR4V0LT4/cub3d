/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlahyani <wlahyani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 00:21:48 by yjaadoun          #+#    #+#             */
/*   Updated: 2023/04/20 08:20:19 by wlahyani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

t_bool	check_path(char *av, t_bool a)
{
	int		i;
	char	*extension;

	i = 0;
	if (a)
		extension = ft_strnstr(av, ".cub", ft_strlen(av));
	else
		extension = ft_strnstr(av, ".xpm", ft_strlen(av));
	if (extension && ft_strlen(extension) == 4)
		return (TRUE);
	else
		return (FALSE);
}

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

char	*check_textures(char *path)
{
	char	**str;
	char	*tmp;

	str = ft_split(path, ' ');
	if (str[1] && !check_path(str[1], FALSE))
	{
		exit_error("ERROR : PATH must be *.xpm\n");
		return (NULL);
	}
	else
	{
		tmp = ft_strdup(str[1]);
		ft_free(str);
		return (tmp);
	}
}
