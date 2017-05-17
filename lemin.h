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
# define ANTNUM 4
int					g_n;

typedef struct		s_rooms
{
	char			*name;
	int				x;
	int				y;
	struct s_rooms	*next;
}					t_rooms;

typedef	struct		s_joins
{
	char			*name1;
	char			*name2;
	struct s_joins	*next;
}					t_joins;

typedef struct		s_line
{
	int				type;
	char			*name1;
	char			*name2;
	int				x;
	int				y;
}					t_line;

typedef struct		s_data
{
	int				antnum;
	int				roomsnum;
	t_rooms			*rooms;
	t_joins			*joins;
	char			**matrix;
	char			**names;
	t_rooms			*start;
	t_rooms			*end;
}					t_data;

void				read_data();
void				data_init(t_data **data);
int					isvalid(char **split);
int					line_type(char *line);
int					ft_atoi_exit(char *str);
void				exit_error(int n);
char				*add_command(t_data *data, char *str, char *command);
void				add_room(t_data *data, char *str, char *command);
void				add_names(t_data *data);
void				add_join(t_data *data, char *str, char *command);
void				room_add_start(t_data *data, t_rooms *room);
void				room_add_mid(t_data *data, t_rooms *room);
void				room_add_end(t_data *data, t_rooms *room);
void				join_add(t_data *data, char *join1, char *join2);
void				matrix_init(t_data *data);
void				print_matrix(t_data *data);
void				find_all_paths(t_data *data);
#endif
