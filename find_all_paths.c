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

static void print_path(t_lst *path)
{
	if (!path)
	{
		return;
	}
	printf("[%d]", path->fd);
	path = path->next;
	while (path)
	{
		printf(" => [%d]", path->fd);
		path = path->next;
	}
	printf("\n");
}

static int can_traverse(char **matrix, t_lst **path, int start, int roomsnum
						, char *visited)
{
	int		i;
	t_lst	*lsnew;

	printf("check [%d]" ,start);
	i = 0;
	visited[start] = 1;
	while (i < roomsnum - 1)
	{
		if (matrix[start][i] && !visited[i])
		{
			if (can_traverse(matrix, path, i, roomsnum, visited))
			{
				lsnew = (t_lst *) malloc(sizeof(t_lst));
				lsnew->fd = i;
				lsnew->next = *path;
				*path = lsnew;
				return (1);
			}
		}
		i++;
	}
	if (matrix[i][roomsnum - 1])
	{
		lsnew = (t_lst *)malloc(sizeof(t_lst));
		lsnew->fd = i;
		lsnew->next = *path;
		*path = lsnew;
		print_path(*path);
		path = NULL;
		printf("|OK|\n");
		return (1);
	}
	printf("||||\n");
	return (0);
}

void		find_all_paths(t_data *data)
{
	t_lst	*path;
	char 	*visited;
	int 	i;

	visited = ft_strnew(data->roomsnum - 1);

	path = (t_lst *) malloc(sizeof(t_lst));
	path = NULL;
	can_traverse(data->matrix, &path, 0, data->roomsnum, visited);
}
