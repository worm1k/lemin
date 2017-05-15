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

void	print_matrix(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	printf("  ");
	while (i < data->roomsnum)
	{
		printf("|%d", i % 10);
		i++;
	}
	printf("\n");
	i = 0;
	printf("--");
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
		printf("%d ", i);
		while (j < data->roomsnum)
		{
			printf(" %d", data->matrix[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}
