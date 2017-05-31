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
#include <fcntl.h>
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

typedef struct 		s_rlist
{
	int 			index;
	int 			ant;
	struct s_rlist	*next;
}					t_rlist;

typedef struct 		s_paths
{
	int 			len;
	char			visited;
	t_rlist			*head;
	struct s_paths	*next;
}					t_paths;

typedef struct		s_data
{
	int				antnum;
	int				roomsnum;
	int				pathsnum;
	t_rooms			*rooms;
	t_rooms			*start;
	t_rooms			*end;
	char			**matrix;
	char			**names;
	t_paths			*paths;
	t_paths			*group;
	char			*visited;
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
void				print_paths(t_data *data);
void				find_all_paths(t_data *data);
void		        find_path_group(t_data *data);
void				lem_in(t_data *data);
void				ft_destruct(t_data *data);
#endif
