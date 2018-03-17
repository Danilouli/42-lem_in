/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adders.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 18:53:03 by dsaadia           #+#    #+#             */
/*   Updated: 2018/03/17 14:11:45 by dsaadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	add_room(t_room new_room)
{
	t_room	*new_rooms;
	int i;

	i = 0;
	if (!(new_rooms = (t_room*)(malloc(sizeof(t_room) * NBROOMS))))
		exit(EXIT_FAILURE);
	if (NBROOMS == 1)
	{
		new_rooms[0] = new_room;
		ROOMS = new_rooms;
		return ;
	}
	while (i < NBROOMS - 1)
	{
		new_rooms[i] = ROOMS[i];
		i++;
	}
	new_rooms[NBROOMS - 1] = new_room;
	free(ROOMS);
	ROOMS = new_rooms;
}

static void copy_old_mat(t_matrix *new_adj)
{
	int	i;

	i = 0;
	while (i < NBROOMS - 1)
	{
		if (!((*new_adj).inds[i] = (int*)malloc(sizeof(int) * (*new_adj).nbc)))
			exit(EXIT_FAILURE);
		ft_int_tab_cpy((*new_adj).inds[i], ADJ.inds[i], ADJ.nbc);
		free(ADJ.inds[i]);
		(*new_adj).inds[i][(*new_adj).nbc - 1] = 0;
		i++;
	}
}

void add_mat_line(void)
{
	t_matrix	new_adj;

	new_adj.nbl = NBROOMS;
	new_adj.nbc = NBROOMS;
	if (!(new_adj.inds = (int**)malloc(sizeof(int*) * NBROOMS)))
		exit(EXIT_FAILURE);
	if (NBROOMS == 1)
	{
		if (!(new_adj.inds[0] = (int*)malloc(sizeof(int))))
			exit(EXIT_FAILURE);
		new_adj.inds[0][0] = 0;
		ADJ = new_adj;
		return ;
	}
	copy_old_mat(&new_adj);
	if (!(new_adj.inds[new_adj.nbl - 1] = ft_intarr_init(new_adj.nbc)))
		exit(EXIT_FAILURE);
	free(ADJ.inds);
	ADJ = new_adj;
}

int add_ants(void)
{
	t_room start;
	int i;

	i = -1;
	start = start_room();
	if (!(ANTS = (t_ant*)malloc(sizeof(t_ant) * NBANTS)))
		return (0);
	while (++i < NBANTS)
	{
		ANTS[i].no = i;
		ANTS[i].room = start;
	}
	return (1);
}
