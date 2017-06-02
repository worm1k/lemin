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

static int		try_add(char *str, int type, t_data *data)
{
	static int	curr = 0;
	static char	*command = NULL;

	if (type == ANTNUM)
	{
		if (curr != 0)
			exit_error(data);
		//printf("ANTNUM [%s]\n", str);
		if (ft_strequ(command, "start") || ft_strequ(command, "end"))
			exit_error(data);
		data->antnum = ft_atoi_exit(str);
		if (data->antnum == 0)
			exit_error(data);
		curr++;
	}
	else if (type == COMMAND)
	{
		command = add_command(str, command);
		return (42);
	}
	else if (type == ROOM)
	{
		if (curr != 1)
			exit_error(data);
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
			exit_error(data);
		add_join(data, str, command);
	}
	else if (type == COMMENT)
	{
		//printf("Comment [%s]\n", str);
		if (command != 0)
			exit_error(data);
	}
	(command) ? (free(command)) : (0);
	command = 0;
	return (curr);
}

static void join(t_data *data, char *str)
{
	char	*todel;

	todel = data->input;
	data->input = ft_strjoin(data->input, str);
	(todel) ? (free(todel)) : (0);
	todel = data->input;
	data->input = ft_strjoin(data->input, "\n");
	(todel) ? (free(todel)) : (0);
}

static void	read_input(t_data *data, int fd)
{
	char	*temp;
	int		step;

	//fd = open("./maps/2", O_RDONLY);
	//fd = open("/nfs/2016/a/abykov/ClionProjects/lemin/maps/5", O_RDONLY);
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

void		read_data(int fd)
{
	t_data	*data;

	data_init(&data);
	read_input(data, fd);
	find_all_paths(data);
	ft_putendl(data->input);
	free(data->input);
	data->input = NULL;
	find_path_group(data);
	lem_in(data);
	ft_destruct(data);
}
