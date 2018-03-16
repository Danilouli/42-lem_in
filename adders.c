/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adders.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 18:53:03 by dsaadia           #+#    #+#             */
/*   Updated: 2018/03/16 22:44:51 by schmurz          ###   ########.fr       */
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

void add_mat_line(void)
{
	int				i;
	t_matrix	new_adj;

	i = 0;
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
	while (i < NBROOMS - 1)
	{
		if (!(new_adj.inds[i] = (int*)malloc(sizeof(int) * new_adj.nbc)))
			exit(EXIT_FAILURE);
		ft_int_tab_cpy(new_adj.inds[i], ADJ.inds[i], ADJ.nbc);
		free(ADJ.inds[i]);
		new_adj.inds[i][new_adj.nbc - 1] = 0;
		i++;
	}
	if (!(new_adj.inds[new_adj.nbl - 1] = ft_intarr_init(new_adj.nbc)))
		exit(EXIT_FAILURE);
	free(ADJ.inds);
	ADJ = new_adj;
}
