/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abykov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 14:42:20 by abykov            #+#    #+#             */
/*   Updated: 2017/04/24 14:42:21 by abykov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int	index_of(t_data *data, char *str)
{
	int		res;

	res = 0;
	while (res < data->roomsnum)
	{
		if (ft_strequ(str, data->names[res]))
		{
			printf("INDEX_OF[%s]:[%d]\n", str, res);
			return (res);
		}
		res++;
	}
	exit_error(g_n);
	return (-1);
}

void		join_add(t_data *data, char *join1, char *join2)
{
	int		i;
	int		j;

	i = index_of(data, join1);
	j = index_of(data, join2);
	if (data->matrix[i][j] || data->matrix[j][i])
		exit_error(g_n);
	data->matrix[i][j] = 1;
	data->matrix[j][i] = 1;
}
