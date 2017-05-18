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

static void print_path(t_list *path)
{
	if (!path)
	{
		return;
	}
	printf("[%zu]", path->content_size);
	path = path->next;
	while (path)
	{
		printf(" => [%zu]", path->content_size);
		path = path->next;
	}
	printf("\n");
}

static int	can_traverse(char **matrix, int start, char *visited, int n, t_list **path)
{
	int		j;
	t_list	*temp;

	if (start == n - 1)

	return (0);
}

void		find_all_paths(t_data *data)
{
	char 	*visited;
	t_list	*path;

	path = 0;
	visited = ft_strnew((size_t)data->roomsnum - 1);

	can_traverse(data->matrix, 0, visited, data->roomsnum, &path);
}
