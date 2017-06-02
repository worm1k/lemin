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

char		*add_command(char *str, char *command)
{
	//printf("COMMAND [%s]\n", str);
	size_t	len;

	if (command != 0)
		exit_error(NULL);
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
	//printf("ROOM [%s][%d][%d]\t[%s]\n", room->name, room->x, room->y, str);
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

	//printf("GENERATING NAMES ARRAY\n");
	if (data->start == NULL || data->end == NULL)
		exit_error(data);
	curr = data->rooms;
	data->names = (char **)malloc(sizeof(char *) * data->roomsnum);
	matrix_init(data);
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
	char	*join1;
	char	*join2;
	char	*str2;

	if (ft_strequ(command, "start") || ft_strequ(command, "end"))
		exit_error(data);
	join1 = ft_strsub(str, 0, ft_strchr(str, '-') - str);
	str2 = ft_strchr(str, '-') + 1;
	join2 = ft_strsub(str2, 0, ft_strlen(str2));
	//printf("JOIN [%s]-[%s] [%s]\n", join1, join2, str);
	if (ft_strequ(join1, join2))
		exit_error(data);
	join_add(data, join1, join2);
	(join1) ? (free(join1)) : (0);
	(join2) ? (free(join2)) : (0);
}
