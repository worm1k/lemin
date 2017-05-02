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
	static int	n = 1;

	if (type == ANTNUM)
	{
		if (curr != 0)
			exit_error(n);
		printf("ANTNUM [%s]\n", str);
		data->antnum = ft_atoi(str);
		curr++;
	}
	else if (type == COMMAND)
	{
		add_command(data, str);
	}
	else if (type == ROOM)
	{
		if (curr != 1)
			exit_error(n);
		add_room(data, str);
	}
	else if (type == JOIN)
	{
		if (curr == 1)
		{
			curr = 2;
			add_names(data);
		}
		if (curr != 2)
			exit_error(n);
		add_join(data, str);
	}
	n++;
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
