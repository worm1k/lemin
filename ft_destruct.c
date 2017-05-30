/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destruct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abykov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 14:42:20 by abykov            #+#    #+#             */
/*   Updated: 2017/04/24 14:42:21 by abykov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	ft_delgroup(t_paths *group)
{
	t_paths		*todel;

	while (group)
	{
		todel = group;
		group = group->next;
		free(todel);
	}
}

static void ft_delpaths(t_paths *paths)
{
    t_paths	*curr;
    t_paths *ctmp;
	t_rlist	*room;
	t_rlist *rtmp;
	
	curr = paths;
	while (curr)
	{
		room = curr->head;
		while (room)
		{
			rtmp = room->next;
			free(room);
			room = rtmp;
		}
		ctmp = curr->next;
		free(curr);
		curr = ctmp;
	}
}

static void ft_del2dchar(t_data *data)
{
    int     i;
    
    i = 0;
    while (i < data->roomsnum)
    {
        free(data->matrix[i]);
        free(data->names[i]);
        i++;
    }
    free(data->matrix);
    free(data->names);
}

static void ft_delrooms(t_rooms *room)
{
    t_rooms *curr;
    t_rooms *temp;

    curr = room;
    while (curr)
    {
        temp = curr->next;
        free(curr->name);
        free(curr);
        curr = temp;
    }
}

void        ft_destruct(t_data *data)
{
    ft_delrooms(data->rooms);
    ft_delrooms(data->end);
    ft_delrooms(data->start);
    ft_del2dchar(data);
    ft_delpaths(data->paths);
	ft_delgroup(data->group);
    free(data->visited);
    free(data);
}
