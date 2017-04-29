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
