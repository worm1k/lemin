/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path_group.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abykov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 14:42:20 by abykov            #+#    #+#             */
/*   Updated: 2017/04/24 14:42:21 by abykov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void		compare_group(t_paths **res, t_paths **temp, int antnum)
{
	float		a;
	float		b;

	a = average_moves_num(*res, antnum);
	b = average_moves_num(*temp, antnum);
	if (a <= b)
	{
		del_path(temp, NULL);
	}
	else
	{
		del_path(res, *temp);
	}
}

static int		has_dup_in_path(t_rlist *a, t_rlist *b)
{
	t_rlist		*curr;

	while (a->next)
	{
		curr = b;
		while (curr->next)
		{
			if (a->index == curr->index)
			{
				return (1);
			}
			curr = curr->next;
		}
		a = a->next;
	}
	return (0);
}

static int		has_dup_in_group(t_paths *group, t_paths *path)
{
	while (group)
	{
		if (has_dup_in_path(group->head->next, path->head->next))
			return (1);
		group = group->next;
	}
	return (0);
}

static int		find_next_group(t_paths **dst, t_paths *src)
{
	int			j;
	t_paths		*curr;

	curr = src;
	j = 0;
	while (curr)
	{
		if (curr->visited == 0)
		{
			add_path(dst, curr);
			break ;
		}
		curr = curr->next;
		j++;
	}
	if (curr == NULL && (j = 0 == 0))
		return (0);
	while (src)
	{
		if (src != curr && !has_dup_in_group(*dst, src))
			add_path(dst, src);
		j++;
		src = src->next;
	}
	return (1);
}

void			find_path_group(t_data *data)
{
	t_paths		*temp;

	temp = NULL;
	find_next_group(&data->group, data->paths);
	while (find_next_group(&temp, data->paths))
	{
		compare_group(&data->group, &temp, data->antnum);
		temp = NULL;
	}
}
