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
	printf(" ");
	while (i < data->roomsnum)
	{
		printf("|%d", i % 10);
		i++;
	}
	printf("\n");
	i = 0;
	printf("-");
	while (i < data->roomsnum)
	{
		printf("+-");
		i++;
	}
	exit(0);
}