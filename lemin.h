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
# include <fcntl.h>

enum				e_line
{
	COMMENT = 0,
	COMMAND,
	ROOM,
	JOIN,
	ANTNUM
};

typedef struct		s_rooms
{
	char			*name;
	int				x;
	int				y;
	struct s_rooms	*next;
}					t_rooms;

typedef struct		s_rlist
{
	int				index;
	int				ant;
	struct s_rlist	*next;
}					t_rlist;

typedef struct		s_paths
{
	int				len;
	char			visited;
	int				profit;
	t_rlist			*head;
	struct s_paths	*next;
}					t_paths;

typedef struct		s_data
{
	int				curr;
	int				antnum;
	int				roomsnum;
	int				space;
	t_rooms			*rooms;
	t_rooms			*start;
	t_rooms			*end;
	char			**matrix;
	char			**names;
	t_paths			*paths;
	t_paths			*group;
	char			*visited;
	char			*input;
}					t_data;

void				read_data(int fd);
void				data_init(t_data **data);
int					isvalid(char **split);
int					line_type(char *line);
int					ft_atoi_exit(char *str);
void				exit_error(t_data *data);
char				*add_command(char *str, char *command);
void				add_room(t_data *data, char *str, char *command);
void				add_names(t_data *data);
void				add_join(t_data *data, char *str, char *command);
void				room_add_start(t_data *data, t_rooms *room);
void				room_add_mid(t_data *data, t_rooms *room);
void				room_add_end(t_data *data, t_rooms *room);
void				join_add(t_data *data, char *join1, char *join2);
void				matrix_init(t_data *data);
void				find_all_paths(t_data *data);
void				cpy_path(t_rlist **dst, t_rlist *src);
void				cre_path(t_paths **ps, t_paths *n, t_rlist *path, int len);
void				find_path_group(t_data *data);
void				add_path(t_paths **dst, t_paths *src);
float				average_moves_num(t_paths *path, int antnum);
void				del_path(t_paths **path, t_paths *value);
void				lem_in(t_data *data);
void				ft_destruct(t_data *data);
#endif
