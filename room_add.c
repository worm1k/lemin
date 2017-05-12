/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abykov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 14:42:20 by abykov            #+#    #+#             */
/*   Updated: 2017/04/24 14:42:21 by abykov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	room_check(t_data *data, t_rooms *room)
{
	t_rooms	*curr;

	curr = data->rooms;
	while (curr)
	{
		if (ft_strequ(curr->name, room->name)
			|| (curr->x == room->x && curr->y == room->y))
			exit_error(g_n);
		curr = curr->next;
	}
	if (data->start)
	{
		curr = data->start;
		if (ft_strequ(curr->name, room->name)
			|| (curr->x == room->x && curr->y == room->y))
			exit_error(g_n);
	}
	if (data->end)
	{
		curr = data->end;
		if (ft_strequ(curr->name, room->name)
			|| (curr->x == room->x && curr->y == room->y))
			exit_error(g_n);
	}
}

void		room_add_start(t_data *data, t_rooms *room)
{
	if (data->start != NULL)
		exit_error(g_n);
	room_check(data, room);
	data->start = room;
}

void		room_add_mid(t_data *data, t_rooms *room)
{
	t_rooms	*curr;

	room_check(data, room);
	curr = data->rooms;
	while (curr->next)
		curr = curr->next;
	curr->next = room;
}

void		room_add_end(t_data *data, t_rooms *room)
{
	if (data->end != NULL)
		exit_error(g_n);
	room_check(data, room);
	data->end = room;
}
