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

static void		try_add_2(char *str, int type, t_data *data, char *command)
{
	if (type == ROOM)
	{
		if (data->curr != 1)
			exit_error(data);
		add_room(data, str, command);
	}
	else if (type == JOIN)
	{
		if (data->curr == 1)
		{
			data->curr = 2;
			add_names(data);
		}
		if (data->curr != 2)
			exit_error(data);
		add_join(data, str, command);
	}
	else if (type == COMMENT)
	{
		if (command != 0)
			exit_error(data);
	}
}

static int		try_add(char *str, int type, t_data *data)
{
	static char	*command = NULL;

	if (type == ANTNUM)
	{
		if (data->curr != 0)
			exit_error(data);
		if (ft_strequ(command, "start") || ft_strequ(command, "end"))
			exit_error(data);
		data->antnum = ft_atoi_exit(str);
		if (data->antnum == 0)
			exit_error(data);
		data->curr += 1;
	}
	else if (type == COMMAND)
	{
		command = add_command(str, command);
		return (42);
	}
	else
		try_add_2(str, type, data, command);
	(command) ? (free(command)) : (0);
	command = 0;
	return (data->curr);
}

static void		join(t_data *data, char *str)
{
	char		*todel;

	todel = data->input;
	data->input = ft_strjoin(data->input, str);
	(todel) ? (free(todel)) : (0);
	todel = data->input;
	data->input = ft_strjoin(data->input, "\n");
	(todel) ? (free(todel)) : (0);
}

static void		read_input(t_data *data, int fd)
{
	char		*temp;
	int			step;

	temp = 0;
	step = -1;
	while (get_next_line(fd, &temp) > 0)
	{
		step = try_add(temp, line_type(temp), data);
		join(data, temp);
		(temp) ? free(temp) : 0;
		temp = 0;
	}
	if (step != 2)
	{
		exit_error(data);
	}
}

void			read_data(int fd)
{
	t_data		*data;

	data_init(&data);
	data->curr = 0;
	read_input(data, fd);
	find_all_paths(data);
	ft_putendl(data->input);
	free(data->input);
	data->input = NULL;
	find_path_group(data);
	lem_in(data);
	ft_destruct(data);
}
