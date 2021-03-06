/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_all_paths.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abykov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 14:42:20 by abykov            #+#    #+#             */
/*   Updated: 2017/04/24 14:42:21 by abykov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	push_path(t_data *data, t_rlist *path, int len)
{
	t_paths	*curr;

	if (!data->paths)
		return (cre_path(&data->paths, NULL, path, len));
	curr = data->paths;
	if (len <= curr->len)
		return (cre_path(&data->paths, data->paths, path, len));
	while (curr->next)
	{
		if (curr->len <= len && len <= curr->next->len)
			break ;
		curr = curr->next;
	}
	return (cre_path(&curr->next, curr->next, path, len));
}

static void	pop_room(t_rlist **path)
{
	t_rlist	*temp;

	temp = (*path)->next;
	free(*path);
	*path = temp;
}

static void	push_room(int index, t_rlist **path)
{
	t_rlist	*temp;

	temp = (t_rlist *)malloc(sizeof(t_rlist));
	temp->index = index;
	temp->ant = 0;
	temp->next = *path;
	*path = temp;
}

static void	can_traverse(t_data *data, int start, t_rlist **path, int len)
{
	int		i;

	i = 0;
	while (i < data->roomsnum)
	{
		if (data->matrix[start][i])
		{
			if (i == data->roomsnum - 1)
			{
				push_room(i, path);
				push_path(data, *path, len);
				pop_room(path);
			}
			else if (!data->visited[i])
			{
				data->visited[i] = 1;
				push_room(i, path);
				can_traverse(data, i, path, len + 1);
				pop_room(path);
				data->visited[i] = 0;
			}
		}
		i++;
	}
}

void		find_all_paths(t_data *data)
{
	t_rlist	*path;

	path = (t_rlist *)malloc(sizeof(t_rlist));
	path->index = 0;
	path->ant = 0;
	path->next = NULL;
	data->visited[0] = 1;
	can_traverse(data, 0, &path, 1);
	if (!data->paths)
		exit_error(NULL);
	free(path);
}
