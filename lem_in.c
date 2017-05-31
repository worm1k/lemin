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

void		ant_step(t_rlist *room, t_data *data)
{
	if ()
		return ;
	if (room)
}

void		lem_in(t_data *data)
{
	int 	ant;
	t_paths	*path;
	int 	i;


	ants = 1;
	while (ant <= data->antnum)
	{
		path = data->group;
		while (path)
		{
			ant_step(path->head, data);
			path = path->next;
		}
		ant++;
	}
}
