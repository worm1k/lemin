/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path_group_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abykov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 14:42:20 by abykov            #+#    #+#             */
/*   Updated: 2017/04/24 14:42:21 by abykov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		add_path(t_paths **dst, t_paths *src)
{
	t_paths	*add;
	t_paths	*curr;

	src->visited = 1;
	add = (t_paths *)malloc(sizeof(t_paths));
	add->len = src->len;
	add->head = src->head;
	add->visited = 42;
	curr = *dst;
	if (curr == NULL || add->len <= curr->len)
	{
		add->next = *dst;
		*dst = add;
		return ;
	}
	while (curr->next)
	{
		if (curr->len <= add->len && add->len <= curr->next->len)
			break ;
		curr = curr->next;
	}
	add->next = curr->next;
	curr->next = add;
}

float		average_moves_num(t_paths *path, int antnum)
{
	float	res;
	int		roomsn;
	int		pathsn;

	roomsn = 0;
	pathsn = 0;
	while (path)
	{
		roomsn += path->len;
		pathsn += 1;
		path = path->next;
	}
	res = ((float)antnum + (float)roomsn) / (float)pathsn;
	return (res);
}

void		del_path(t_paths **path, t_paths *value)
{
	t_paths	*todel;

	while (*path)
	{
		todel = *path;
		*path = (*path)->next;
		free(todel);
	}
	*path = value;
}
