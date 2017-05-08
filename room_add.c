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

static void	room_check(t_rooms *head, t_rooms *room)
{
	t_rooms	*curr;

	curr = head;
	while (curr)
	{
		if (ft_strequ(curr->name, room->name)
			|| (curr->x == room->x && curr->y == room->y))
			exit_error(g_n);
		curr = curr->next;
	}
}

void		room_add_front(t_rooms **head, t_rooms *room)
{
	t_rooms	*temp;

	room_check(*head, room);
}

void		room_add_mid(t_rooms *head, t_rooms *room)
{
	room_check(head, room);
}

void		room_add_back(t_rooms *head, t_rooms *room)
{
	room_check(head, room);
}
