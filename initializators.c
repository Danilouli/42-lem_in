/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializators.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 18:45:17 by dsaadia           #+#    #+#             */
/*   Updated: 2018/03/15 19:19:59 by dsaadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void init_room(char *room_line, char *type, int room_num)
{
	char		**helptab;
	t_room	new_room;

	helptab = ft_strsplit(room_line, ' ');
	new_room.no = room_num;
	new_room.type = type;
	new_room.name = helptab[0];
	new_room.x = ft_atoi(helptab[1]);
	new_room.y = ft_atoi(helptab[2]);
	ft_free_strtab(helptab);
	add_room(new_room);
}
