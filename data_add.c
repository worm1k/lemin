/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abykov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 14:42:20 by abykov            #+#    #+#             */
/*   Updated: 2017/04/24 14:42:21 by abykov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void		del_command(t_data *data)
{
	if (data->command)
		ft_strdel(&data->command);
}

void		add_command(t_data *data, char *str)
{
	printf("COMMAND [%s]\n", str);
	int		len;

	del_command(data);
	len = ft_strlen(str) - 2;
	data->command = ft_strsub(str, 2, len);
}

void		add_room(t_data *data, char *str)
{
	printf("ROOM [%.*s]\n", (int)(ft_strchr(str, ' ') - str), str);
	if (!data->rooms)
}

void		add_names(t_data *data)
{
	printf("GENERATING NAMES ARRAY\n");
}

void		add_join(t_data *data, char *str)
{
	printf("JOIN [%s]\n", str);
}
