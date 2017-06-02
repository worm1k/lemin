/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abykov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 14:42:20 by abykov            #+#    #+#             */
/*   Updated: 2017/04/24 14:42:21 by abykov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	print_usage(void)
{
	ft_putendl("usage: ./lem_in [-f file]");
}

int		main(int argc, char **argv)
{
	int	fd;

	if (argc == 1)
		read_data(0);
	else if (argc == 3)
	{
		if (ft_strequ(argv[1], "-f"))
		{
			if ((fd = open(argv[2], O_RDONLY)) > 0)
				read_data(fd);
			else
				exit_error(NULL);
		}
		else
			print_usage();
	}
	else
		print_usage();
	return (0);
}
