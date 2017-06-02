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
	if (line[0] == '#' && line[1] == '#')
	{
		return (COMMAND);
	}
	else if (line[0] == '#')
	{
		return (COMMENT);
	}
	else if (isroom(line))
	{
		return (ROOM);
	}
	else if (isjoin(line))
	{
		return (JOIN);
	}
	else if (isantnum(line))
	{
		return (ANTNUM);
	}
	exit_error(NULL);
	return (42);
}
