/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_type.c                                        :+:      :+:    :+:   */
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

static int	isantnum(char *str)
{
	int		i;

	i = 0;
	while (ft_isdigit(str[i]))
		i++;
	if (str[i] != '\0')
		return (0);
	return (1);
}

static int	isjoin(char *str)
{
	int		i;
	int		j;

	i = 0;
	if (ft_isprint(str[i]) && str[i] != ' ' && str[i] != '#' 
		&& str[i] != 'L' && str[i] != '-')
		i++;
	else
		return (0);
	while (ft_isprint(str[i]) && str[i] != ' ' && str[i] != '-')
		i++;
	if (str[i++] != '-')
		return (0);
	j = i;
	if (ft_isprint(str[i]) && str[i] != ' ' && str[i] != '#' 
		&& str[i] != 'L' && str[i] != '-')
		i++;
	else
		return (0);
	while (ft_isprint(str[i]) && str[i] != ' ' && str[i] != '-')
		i++;
	if (str[i] != '\0' || j == i)
		return (0);
	return (1);
}

static int	isroom(char *str)
{
	int		i;
	int		j;

	i = 0;
	if (ft_isprint(str[i]) && str[i] != ' ' && str[i] != '#' && str[i] != 'L' && str[i] != '-')
		i++;
	else
		return (0);
	while (ft_isprint(str[i]) && str[i] != ' ' && str[i] != '-')
		i++;
	if (str[i++] != ' ')
		return (0);
	j = i;
	while (ft_isdigit(str[i]))
		i++;
	if (str[i++] != ' ' || j == i)
		return (0);
	j = i;
	while (ft_isdigit(str[i]))
		i++;
	if (str[i] != '\0' || j == i)
		return (0);
	return (1);
}

int			line_type(char *line)
{
	// printf("type of [%15s]", line);
	if (line[0] == '#' && line[1] == '#')
	{
		// printf(" is COMMAND\n");
		return (COMMAND);
	}
	else if (line[0] == '#')
	{
		// printf(" is COMMENT\n");
		return (COMMENT);
	}
	else if (isroom(line))
	{
		// printf(" is ROOM\n");
		return (ROOM);
	}
	else if (isjoin(line))
	{
		// printf(" is JOIN\n");
		return (JOIN);
	}
	else if (isantnum(line))
	{
		// printf(" is ANTNUM\n");
		return (ANTNUM);
	}

	// printf(" is UNKOWN\n");
	exit_error(NULL);
	return (42);
}
