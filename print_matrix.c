/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_matrix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abykov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 14:42:20 by abykov            #+#    #+#             */
/*   Updated: 2017/04/24 14:42:21 by abykov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		print_matrix(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	printf("   ");
	while (i < data->roomsnum)
	{
		printf(" %d", i % 10);
		i++;
	}
	printf("\n");
	i = 0;
	printf("---");
	while (i < data->roomsnum)
	{
		printf("+-");
		i++;
	}
	printf("\n");
	i = 0;
	while (i < data->roomsnum)
	{
		j = 0;
		printf("%2d ", i);
		while (j < data->roomsnum)
		{
			printf(" %d", data->matrix[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

void		print_paths(t_data *data)
{
	t_paths	*curr;
	t_rlist	*room;
	
	curr = data->paths;
	printf("PRINTING PATHS [%d]:\n", data->pathsnum);
	if (!curr)
		printf("ERROR: No Paths\n");
	while (curr)
	{
		printf("{%2d}: ", curr->len);
		room = curr->head;
		printf("[%2d]", room->index);
		room = room->next;
		while (room)
		{
			printf(" => [%2d]", room->index);
			room = room->next;
		}
		printf("\n");
		curr = curr->next;
	}
	printf("PATHS ENDED\n");
}
