/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_all_paths_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abykov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 14:42:20 by abykov            #+#    #+#             */
/*   Updated: 2017/04/24 14:42:21 by abykov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		cpy_path(t_rlist **dst, t_rlist *src)
{
	t_rlist	*temp;

	while (src)
	{
		temp = (t_rlist *)malloc(sizeof(t_rlist));
		temp->index = src->index;
		temp->ant = 0;
		temp->next = *dst;
		*dst = temp;
		src = src->next;
	}
}

void		cre_path(t_paths **ps, t_paths *n, t_rlist *path, int len)
{
	*ps = (t_paths *)malloc(sizeof(t_paths));
	(*ps)->visited = 0;
	(*ps)->len = len;
	(*ps)->next = n;
	(*ps)->head = NULL;
	cpy_path(&(*ps)->head, path);
}
