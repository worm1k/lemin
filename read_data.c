/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abykov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 14:42:20 by abykov            #+#    #+#             */
/*   Updated: 2017/04/24 14:42:21 by abykov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

// # define UNKNOWN -1
// # define COMMENT 0
// # define COMMAND 1
// # define ROOM 2
// # define JOIN 3
// # define ANTNUM 4

static void		try_add(char *str, int type, t_data *data)
{
	static int	curr = 0;
	static char	*command = 0;

	if (type == ANTNUM)
	{
		if (curr != 0)
			exit_error(g_n);
		printf("ANTNUM [%s]\n", str);
		data->antnum = ft_atoi_exit(str);
		if (data->antnum == 0)
			exit_error(g_n);
		curr++;
	}
	else if (type == COMMAND)
	{
		command = add_command(data, str, command);
		g_n++;
		return ;
	}
	else if (type == ROOM)
	{
		if (curr != 1)
			exit_error(g_n);
		add_room(data, str, command);
	}
	else if (type == JOIN)
	{
		if (curr == 1)
		{
			curr = 2;
			add_names(data);
		}
		if (curr != 2)
			exit_error(g_n);
		add_join(data, str, command);
	}
	else if (type == COMMENT)
	{
		printf("Comment [%s]\n", str);
		if (command != 0)
			exit_error(g_n);
	}
	(command) ? (free(command)) : (0);
	command = 0;
	g_n++;
}

static void	read_input(t_data *data)
{
	char	*temp;

	temp = 0;
	while (get_next_line(0, &temp) > 0)
	{
		try_add(temp, line_type(temp), data);
		(temp) ? free(temp) : 0;
		temp = 0;
	}
}

void		read_data()
{
	t_data	*data;

	data_init(&data);
	read_input(data);
}
