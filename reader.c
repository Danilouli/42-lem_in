/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schmurz <schmurz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 20:17:42 by schmurz           #+#    #+#             */
/*   Updated: 2018/03/17 12:23:39 by dsaadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void read_nbants(void) {
	char *l;

	while (get_next_line(0, &l) > 0 && !ft_isnumstr(l))
	{
		if (!is_comment_line(l) && ft_printf("ERROR") && ft_strdelbool(&l))
			exit(EXIT_SUCCESS);
		ft_strdel(&l);
	}
	NBANTS = 10;
	if (((NBANTS = (int)ft_atoi(l)) == 0) && ft_printf("ERROR"))
		exit(EXIT_SUCCESS);
	ft_strdel(&l);
}

static	void read_line(char *l)
{
	static char *room_type = 0;
	int room_num;

	room_num = -1;
	if (is_command_line(l))
		room_type = is_command_line(l);
	else if (is_room_line(l) && (++room_num) >= 0)
	{
		if (!init_room(l, room_type, room_num)
		&& ft_printf("ERROR") && ft_strdelbool(&l))
			exit(EXIT_SUCCESS);
	}
	else if (is_tube_line(l))
	{
		if (!init_tube(l) && ft_printf("ERROR") && ft_strdelbool(&l))
			exit(EXIT_SUCCESS);
	}
	else if (!is_comment_line(l) && ft_strdelbool(&l))
		exit(EXIT_SUCCESS);
}

void	read_lemin(void)
{
	char *l;

	init_g_lemin();
	read_nbants();
	while (get_next_line(0, &l) > 0)
	{
		if (!is_comment_line(l))
			ft_printf("%s\n",l);
		read_line(l);
		ft_strdel(&l);
	}
	if (!add_ants())
		exit(EXIT_FAILURE);
}
