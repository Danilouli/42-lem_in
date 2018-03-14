/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schmurz <schmurz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 19:16:41 by schmurz           #+#    #+#             */
/*   Updated: 2018/03/14 20:10:50 by schmurz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# define MAT(i,j)	(g_lemin->mat->inds[i][j])
# define ANT(i)		(g_lemin->ants[i])
# define ROOM(i)	(g_lemin->rooms[i])
# define NBROOMS	(g_lemin->nbrooms)
# define nbants		(g_lemin->nbants)

typedef struct	s_matrix
{
	int nbl;
	int nbc;
	int **inds;
}								t_matrix

typedef struct	s_room
{
	int		no;
	char	*name;
}								t_room

typedef struct	s_ant
{
	t_room	room;
	int			no;
}								t_ant

typedef struct 	s_lemin
{
	t_matrix	mat;
	int				nbants;
	int				nbrooms;
	t_ant			*ants;
	t_room		*rooms;
}

g_lemin		*lemin;

#endif
