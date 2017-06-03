/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abykov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 14:42:20 by abykov            #+#    #+#             */
/*   Updated: 2017/04/24 14:42:21 by abykov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		ft_atoi_exit(char *str)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (ft_isdigit(str[i]))
	{
		if (res > 214748364 || (res == 214748364 && str[i] >= '8'))
			exit_error(NULL);
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res);
}
