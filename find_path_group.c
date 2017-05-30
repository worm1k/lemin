/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abykov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 14:42:20 by abykov            #+#    #+#             */
/*   Updated: 2017/04/24 14:42:21 by abykov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void		print_group(t_paths *group)
{
	t_paths		*curr;
	t_rlist		*room;

	curr = group;
	while (curr)
	{
		printf("{%d}: ", curr->len);
		room = curr->head;
		printf("[%d]", room->index);
		room = room->next;
		while (room)
		{
			printf(" => [%d]", room->index);
			room = room->next;
		}
		printf("\n");
		curr = curr->next;
	}
}

static void		add_path(t_paths **dst, t_paths *src)
{
	t_paths		*add;

	src->visited = 1;
	add = (t_paths *)malloc(sizeof(t_paths));
	add->len = src->len;
	add->head = src->head;
	add->next = *dst;
	add->visited = 42;
	*dst = add;
}

static float    average_moves_num(t_paths *path, int antnum)
{
	float       res;
	int         roomsn;
	int         pathsn;

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

static void     compare_group(t_paths **res, t_paths **temp, int antnum)
{
	float 		a;
	float 		b;

	a = average_moves_num(*res, antnum);
	b = average_moves_num(*temp, antnum);

	if (a < b)
		printf("OK[%f] < [%f]\n", a, b);
	else
		printf("NO[%f] >= [%f]\n", a, b);
}

static int      has_dup_in_path(t_rlist *a, t_rlist *b)
{
	t_rlist     *curr;

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

static int      has_dup_in_group(t_paths *group, t_paths *path)
{
	while (group)
	{
		if (has_dup_in_path(group->head->next, path->head->next))
			return (1);
		group = group->next;
	}
	return (0);
}

static int		find_next_group(t_paths **dst, t_paths *src, int i)
{
	int         j;
	t_paths		*curr;

	printf ("group #[%d]:\n", i);
	curr = src;
	j = 0;
	while (curr)
	{
		if (curr->visited == 0)
		{
			printf ("Added path #[%d]\n", j);
			add_path(dst, curr);
			break ;
		}
		curr = curr->next;
		j++;
	}
	if (curr == NULL)
		return (0);
	j = 0;
	while (src)
	{
		if (src != curr && !has_dup_in_group(*dst, src))
		{
			printf ("Added path ##[%d]\n", j);
			add_path(dst, src);
		}
		j++;
		src = src->next;
	}
	print_group(*dst);
	return (1);
}

void            find_path_group(t_data *data)
{
	t_paths     *res;
	t_paths     *temp;
	int         i;

	i = 0;
	res = NULL;
	temp = NULL;
	find_next_group(&res, data->paths, i++);
	printf("INIT CREATED\n");
	while (find_next_group(&temp, data->paths, i++))
	{

		compare_group(&res, &temp, data->antnum);
		printf ("===============\n\n");
		temp = NULL;
	}
}
