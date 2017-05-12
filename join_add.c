/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abykov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 14:42:20 by abykov            #+#    #+#             */
/*   Updated: 2017/04/24 14:42:21 by abykov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		join_add(t_data *data, t_joins *join)
{
	t_joins	*curr;	

	if (data->joins == NULL)
		data->joins = join;
	else
	{
		curr = data->joins;
		while (curr)
		{
			curr = curr->next;
		}
	}
}
