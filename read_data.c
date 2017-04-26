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

static int	isjoin(char *str)
{

}

static int	isroom(char *str)
{
	int		i;

	i = 0;
	while (str[i] == ' ')
		i++;
	while (ft_isprint(str[i]) && str[i] != '#' && str[i] != 'L')
		i++;
	if (str[i++] != ' ')
		return (0);
	while (ft_isdigit(str[i]))
		i++;
	if (str[i++] != ' ')
		return (0);
	while (ft_isdigit(str[i]))
		i++;
	while (str[i] == ' ')
		i++;
	if (str[i] != '\0')
		return (0);
	return (1);
}

static int	line_type(char *line)
{
	printf("type of [%20s]", line);
	if (line[0] == '#' && line[1] == '#')
	{
		printf(" is COMMAND\n");
		return (COMMAND);
	}
	else if (line[0] == '#')
	{
		printf(" is COMMENT\n");
		return (COMMENT);
	}
	else if (isroom(line))
	{
		printf(" is ROOM\n");
		return (ROOM);
	}
	else if (isjoin(line))
	{
		printf(" is JOIN\n");
		return (JOIN);
	}

	printf(" is UNKOWN\n");
	return (UNKNOWN);
}

static void	read_input(t_graph *head)
{
	char	*temp;
	int		type;

	temp = 0;
	while (get_next_line(0, &temp) > 0)
	{
		type = line_type(temp);
		(temp) ? (free(temp)) : (0);
		temp = 0;
	}
}

void		read_data()
{
	char	*str;
	int		lemnum;

	t_graph	*head;	
	head = malloc(sizeof(t_graph));
	read_input(head);
	free(str);
}
