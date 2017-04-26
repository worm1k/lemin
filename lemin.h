/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abykov <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 14:42:20 by abykov            #+#    #+#             */
/*   Updated: 2017/04/24 14:42:21 by abykov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H
# include "libft/libft.h"
#include <stdio.h>
# define UNKNOWN -1
# define COMMENT 0
# define COMMAND 1
# define ROOM 2
# define JOIN 3

typedef struct		s_vert
{
	int				number;
	char			*name;
	int				x;
	int				y;
	int				is_start;
	int				is_end;
}					t_vert;

typedef struct		s_graph
{
	t_vert			*vert;
	struct s_graph	*next;
}					t_graph;

typedef struct		s_line
{
	int				type;
	char			*name1;
	char			*name2;
	int				x;
	int				y;
}					t_line;

void				read_data();
int					isvalid(char **split);
#endif
