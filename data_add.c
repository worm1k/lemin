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
	t_rooms *curr;

	room = (t_rooms *)malloc(sizeof(t_rooms));
	room->name = ft_strsub(str, 0, ft_strchr(str, ' ') - str);
	room->x = ft_atoi_exit(ft_strchr(str, ' ') + 1);
	room->y = ft_atoi_exit(ft_strrchr(str, ' ') + 1);
	room->next = NULL;
	printf("ROOM [%s][%d][%d]\t[%s]\n", room->name, room->x, room->y, str);
	if (!data->rooms)
		data->rooms = room;
	else
	{
		if (ft_strequ(command, "start"))
			room_add_front(&data->rooms, room);
		else if (ft_strequ(command, "end"))
			room_add_back(data->rooms, room);
		else
			room_add_mid(data->rooms, room);
	}
}

void		add_names(t_data *data)
{
	printf("GENERATING NAMES ARRAY\n");
}

void		add_join(t_data *data, char *str, char *command)
{
	printf("JOIN [%s]\n", str);
}
