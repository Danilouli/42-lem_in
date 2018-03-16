/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializators.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 18:45:17 by dsaadia           #+#    #+#             */
/*   Updated: 2018/03/16 16:24:36 by schmurz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void init_g_lemin(void) {
	ADJ.nbl = 0;
	ADJ.nbc = 0;
	ADJ.inds = NULL;
	NBANTS = 0;
	NBROOMS = 0;
	ANTS = NULL;
	ROOMS = NULL;
}

int	init_room(char *room_line, char *type, int room_num)
{
	char		**helptab;
	t_room	new_room;
	int j;

	j = 0;
	helptab = ft_strsplit(room_line, ' ');
	if (is_room_name(helptab[0]))
		return (0);
	new_room.no = room_num;
	new_room.type = (type) ? type : "path";
	new_room.name = helptab[0];
	new_room.count = (ft_strequ(new_room.type, "start")) ? NBANTS : 0;
	new_room.x = ft_atoi(helptab[1]);
	new_room.y = ft_atoi(helptab[2]);
	NBROOMS++;
	add_room(new_room);
	add_mat_line();
	return (1);
}

int	init_tube(char *tube_line)
{
	int	i;
	int	len;
	int	from;
	int	to;

	i = -1;
	len = 0;
	from = -1;
	to = -1;
	while (++i < NBROOMS)
	{
		len = ft_strlen(ROOMS[i].name);
		if (ft_strequ(ft_strstr(tube_line, ROOMS[i].name), tube_line)
		&& tube_line[len] == '-' && is_room_name(tube_line + len + 1))
		{
			from = find_room(ROOMS[i].name).no;
			to = find_room(tube_line + len + 1).no;
			break;
		}
	}
	if (from == -1 || to == -1)
		return (0);
	MAT(from, to) = 1;
	MAT(to, from) = 1;
	return (1);
}
