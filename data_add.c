/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abykov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 14:42:20 by abykov            #+#    #+#             */
/*   Updated: 2017/04/24 14:42:21 by abykov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

char		*add_command(t_data *data, char *str, char *command)
{
	printf("COMMAND [%s]\n", str);
	int		len;

	if (command != 0)
		exit_error(g_n);
	len = ft_strlen(str) - 2;
	return (ft_strsub(str, 2, len));
}

void		add_room(t_data *data, char *str, char *command)
{
	t_rooms	*room;

	room = (t_rooms *)malloc(sizeof(t_rooms));
	room->name = ft_strsub(str, 0, ft_strchr(str, ' ') - str);
	room->x = ft_atoi_exit(ft_strchr(str, ' ') + 1);
	room->y = ft_atoi_exit(ft_strrchr(str, ' ') + 1);
	room->next = NULL;
	printf("ROOM [%s][%d][%d]\t[%s]\n", room->name, room->x, room->y, str);
	if (ft_strequ(command, "start"))
		room_add_start(data, room);
	else if (ft_strequ(command, "end"))
		room_add_end(data, room);
	else if (data->rooms != NULL)
		room_add_mid(data, room);
	else
		data->rooms = room;
	data->roomsnum += 1;
}

void		add_names(t_data *data)
{
	t_rooms	*curr;
	int		i;

	printf("GENERATING NAMES ARRAY\n");
	if (data->start == NULL || data->end == NULL)
		exit_error(g_n);
	curr = data->rooms;
	data->names = (char **)malloc(sizeof(char *) * data->roomsnum);
	matrix_init(data);
	print_matrix(data);
	data->names[0] = ft_strdup(data->start->name);
	i = 1;
	while (curr)
	{
		data->names[i] = ft_strdup(curr->name);
		curr = curr->next;
		i++;
	}
	data->names[i] = ft_strdup(data->end->name);
}

void		add_join(t_data *data, char *str, char *command)
{
	t_joins	*join;
	char	*str2;

	join = (t_joins *)malloc(sizeof(t_joins));
	join->name1 = ft_strsub(str, 0, ft_strchr(str, '-') - str);
	str2 = ft_strchr(str, '-') + 1;
	join->name2 = ft_strsub(str2, 0, ft_strlen(str2));
	join->next = NULL;
	printf("JOIN [%s]-[%s] [%s]\n", join->name1, join->name2, str);
	if (ft_strequ(join->name1, join->name2))
		exit_error(g_n);
	join_add(data, join);
}
