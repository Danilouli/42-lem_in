/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schmurz <schmurz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 20:17:42 by schmurz           #+#    #+#             */
/*   Updated: 2018/03/16 18:16:43 by schmurz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void read_nbants(void) {
	char *l;

	while (get_next_line(0, &l) > 0 && !ft_isnumstr(l))
	{
		if (!is_comment_line(l) && ft_printf("ERROR"))
		{
			ft_strdel(&l);
			exit(EXIT_SUCCESS);
		}
		ft_strdel(&l);
	}
	NBANTS = 10;
	if (((NBANTS = (int)ft_atoi(l)) == 0) && ft_printf("ERROR"))
		exit(EXIT_SUCCESS);
}

void	read_lemin(void)
{
	char *l;
	int can_go;
	char *room_type;
	int room_num;

	init_g_lemin();
	can_go = 0;
	room_type = 0;
	room_num = -1;
	read_nbants();
	ft_printf("NBANTS %d\n",NBANTS);
	while (get_next_line(0, &l) > 0)
	{
		ft_printf("ligne-->%s\n",l);
		if ((room_type = is_command_line(l)))
			;
		else if (is_room_line(l) && (++room_num) >= 0)
		{
			if (!init_room(l, room_type, room_num) && ft_printf("ERROR"))
			{
				ft_strdel(&l);
				exit(EXIT_SUCCESS);
			}
		}
		else if (is_tube_line(l))
		{
			if (!init_tube(l) && ft_printf("ERROR"))
			{
				ft_strdel(&l);
				exit(EXIT_SUCCESS);
			}
		}
		else if (!is_comment_line(l))
		{
			ft_strdel(&l);
			exit(EXIT_SUCCESS);
		}
		ft_strdel(&l);
	}
	ft_printf("NBROOMS %d\n",NBROOMS);
	int i = 0;
	while (i < NBROOMS)
	{
		ft_printf("ROOM %s\n",ROOMS[i].name);
		i++;
	}
	i = 0;
	int j = 0;
	while (i < ADJ.nbl)
	{
		j = 0;
		while (j < ADJ.nbc)
		{
			ft_printf("%d ",MAT(i,j));
			j++;
		}
		ft_printf("\n");
		i++;
	}
}
