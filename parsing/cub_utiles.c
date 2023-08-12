/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_utiles.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaadoun <yjaadoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 18:46:35 by yjaadoun          #+#    #+#             */
/*   Updated: 2023/03/09 16:26:59 by yjaadoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	ft_lstclear(t_alloc_lst **lst)
{
	t_alloc_lst	*temp;

	while (*lst)
	{
		temp = (*lst)->next;
		if (*lst && (*lst)->content)
			free((*lst)->content);
		if (*lst)
			free(*lst);
		(*lst) = temp;
	}
}

t_alloc_lst	*ft_lstnew(void *content)
{
	t_alloc_lst	*list;

	list = malloc(sizeof(t_alloc_lst));
	if (!list)
		return (NULL);
	list->content = content;
	list->next = NULL;
	return (list);
}

void	ft_lstadd_front(t_alloc_lst	**lst, t_alloc_lst	*new)
{
	if (!new)
		return ;
	if (*lst)
		new->next = *lst;
	*lst = new;
}

void	*alloc(size_t size)
{
	void	*content;

	content = malloc(size);
	if (!content)
	{
		perror("");
		exit(errno);
	}
	ft_lstadd_front(g_data.alloc_list, ft_lstnew(content));
	return (content);
}
