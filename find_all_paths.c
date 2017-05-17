/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_all_pathes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abykov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 14:42:20 by abykov            #+#    #+#             */
/*   Updated: 2017/04/24 14:42:21 by abykov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	print_path(t_lst *path)
{
	if (!path)
		return ;
	printf("[%d]", path->fd);
	path = path->next;
	while (path)
	{
		printf(" => [%d]", path->fd);
		path = path->next;
	}
	printf("\n");
}

static int	can_traverse(char **matrix, t_lst *path, int start, int end)
{
	return (1);
}

void		find_all_paths(t_data *data)
{
	int		i;
	t_lst	*path;

	path = (t_lst *)malloc(sizeof(t_lst));
	path = NULL;
	i = 0;
	while (i < data->roomsnum)
	{
		if (can_traverse(data->matrix, path, 0, data->roomsnum - 1))
		{
			print_path(path);
		}
		i++;
	}
}
