/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abykov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 14:42:20 by abykov            #+#    #+#             */
/*   Updated: 2017/04/24 14:42:21 by abykov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	data_init(t_data **data)
{
	(*data) = malloc(sizeof(t_data));
	(*data)->antnum = -1;
	(*data)->roomsnum = 0;
	(*data)->pathsnum = 0;
	(*data)->rooms = NULL;
	(*data)->names = NULL;
	(*data)->start = NULL;
	(*data)->end = NULL;
	(*data)->matrix = NULL;
	(*data)->paths = NULL;
	(*data)->group = NULL;
}

void	matrix_init(t_data *data)
{
	int	i;

	data->matrix = (char **)malloc(sizeof(char *) * data->roomsnum);
	i = 0;
	while (i < data->roomsnum)
	{
		data->matrix[i] = ft_strnew(data->roomsnum - 1);
		i++;
	}
	data->visited = ft_strnew((size_t)data->roomsnum - 1);
}
