/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_copiers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 18:53:03 by dsaadia           #+#    #+#             */
/*   Updated: 2018/03/15 19:05:40 by dsaadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	add_room(t_room new_room)
{
	t_room	*new_rooms;
	int i;

	i = 0;
	NBROOMS++;
	if (!(new_rooms = (t_room*)(malloc(sizeof(t_room) * NBROOMS))))
		return ;
	if (NBROOMS - 1 == 0)
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
