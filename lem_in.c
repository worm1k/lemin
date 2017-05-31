/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abykov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 14:42:20 by abykov            #+#    #+#             */
/*   Updated: 2017/04/24 14:42:21 by abykov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ****************
 * L1-3 L2-2
 * L1-1 L2-1 L3-3
 * L3-1
 * ****************/

#include "lemin.h"

static void	first_step(t_data *data, int *ant, int *in_way)
{
	t_paths	*path;

	path = data->group;
	while (path && *ant <= data->antnum)
	{
		if (data->antnum - *ant + 1 > path->profit)
		{
			*in_way = 1;
			path->head->ant = *ant;
			*ant += 1;
		}
		path = path->next;
	}
}

static void	ant_step(t_rlist *room, t_data *data, int *in_way)
{
	if (room->next != NULL)
	{
		ant_step(room->next, data, in_way);
		if ((room->next->next == NULL || room->next->ant == 0) && room->ant != 0)
		{
			if (data->space == 1)
				printf(" ");
			else
				data->space = 1;
			printf("L%d-%s", room->ant, data->names[room->next->index]);
			room->next->ant = room->ant;
			room->ant = 0;
			*in_way = 1;
			return;
		}
	}
}

static void	calc_profit(t_paths *group)
{
	int		i;
	int 	len0;

	i = 0;
	len0 = group->len;
	while (group)
	{
		group->profit = group->len - len0 + i - 1;
		group = group->next;
		i++;
	}
}

void		lem_in(t_data *data)
{
	int 	ant;
	int 	in_way;
	t_paths	*path;

	calc_profit(data->group);
	ant = 1;
	in_way = 1;
	while (in_way)
	{
		in_way = 0;
		path = data->group;
		while (path)
		{
			ant_step(path->head, data, &in_way);
			path = path->next;
		}
		(ant != 1) ? (printf("\n")) : (0);
		data->space = 0;
		first_step(data, &ant, &in_way);
	}
}
