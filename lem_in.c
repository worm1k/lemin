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

#include "lemin.h"

static void	ft_printf(int d, char *s)
{
	write(1, "L", 1);
	ft_putnbr(d);
	write(1, "-", 1);
	ft_putstr(s);
}

static void	first_step(t_data *data, int *ant, int *in_way)
{
	t_paths	*path;
	int		temp;

	if (*in_way == 1)
	{
		(write(1, "\n", 1));
	}
	path = data->group;
	temp = 0;
	while (path && *ant + temp <= data->antnum)
	{
		if (data->antnum - *ant + 1 > path->profit)
		{
			*in_way = 1;
			path->head->ant = *ant + temp;
			temp += 1;
		}
		path = path->next;
	}
	*ant += temp;
}

static void	ant_step(t_rlist *room, t_data *data, int *in_way)
{
	if (room->next != NULL)
	{
		ant_step(room->next, data, in_way);
		if ((room->next->next == NULL
			|| room->next->ant == 0) && room->ant != 0)
		{
			if (data->space == 1)
				write(1, " ", 1);
			else
				data->space = 1;
			ft_printf(room->ant, data->names[room->next->index]);
			room->next->ant = room->ant;
			room->ant = 0;
			*in_way = 1;
			return ;
		}
	}
}

static void	calc_profit(t_paths *group)
{
	int		i;
	int		len0;

	i = 0;
	len0 = group->len;
	while (group)
	{
		group->profit = group->len - len0 + i;
		group = group->next;
		i++;
	}
}

void		lem_in(t_data *data)
{
	int		ant;
	int		in_way;
	t_paths	*path;

	calc_profit(data->group);
	ant = 1;
	in_way = 1;
	while (in_way != 0)
	{
		in_way = 0;
		path = data->group;
		while (path)
		{
			ant_step(path->head, data, &in_way);
			path = path->next;
		}
		data->space = 0;
		first_step(data, &ant, &in_way);
	}
}
