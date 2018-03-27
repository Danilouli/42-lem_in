/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schmurz <schmurz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 19:16:41 by schmurz           #+#    #+#             */
/*   Updated: 2018/03/27 13:27:59 by dsaadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/includes/libft.h"
# define ADJ			(g_lemin.mat)
# define MAT(i,j)	((g_lemin.mat).inds[i][j])
# define ROOMS		(g_lemin.rooms)
# define ANTS			(g_lemin.ants)
# define NBROOMS	(g_lemin.nbrooms)
# define NBANTS		(g_lemin.nbants)
# define INF 2147483647

typedef struct			s_matrix
{
	int					nbl;
	int					nbc;
	int					**inds;
}						t_matrix;

typedef struct			s_room
{
	int					no;
	char				*name;
	char				*type;
	int					count;
	int					x;
	int					y;
	char				**helptab;
	int					queue;
}						t_room;

typedef struct			s_ant
{
	t_room				room;
	int					next_move;
	int					no;
}						t_ant;

typedef	struct			s_lemin
{
	t_matrix			mat;
	int					nbants;
	int					nbrooms;
	t_ant				*ants;
	t_room				*rooms;
}						t_lemin;

void					read_lemin(int op);
void					add_room(t_room new_room);
void					add_mat_line(void);
int						add_ants(void);
int						init_room(char *room_line, char *type, int room_num);
int						init_tube(char *tube_line);
t_room					find_room(char *room_name);
t_room					start_room(void);
t_room					end_room(void);
int						is_room_line(char *l);
int						is_room_name(char *str);
int						is_tube_line(char *l);
char					*is_command_line(char *l);
int						is_comment_line(char *l);
void					init_g_lemin(void);
void					print_lemin(int op);
int						read_ok(void);
int						good_or_exit(void);
int						dijkstra(t_room from);
void					print_preds(int *pred);
int						find_way(int *pred);
void					manage_ants(void);
int						is_option(char *option, char **av);

t_lemin					g_lemin;

#endif
