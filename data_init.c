/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abykov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 14:42:20 by abykov            #+#    #+#             */
/*   Updated: 2017/04/24 14:42:21 by abykov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	data_init(t_data **data)
{
	(*data) = malloc(sizeof(t_data));
	(*data)->antnum = -1;
	(*data)->roomsnum = 0;
	(*data)->rooms = 0;
	(*data)->joins = 0;
	(*data)->names = 0;
	(*data)->command = 0;
}
