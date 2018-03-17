/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schmurz <schmurz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 20:17:42 by schmurz           #+#    #+#             */
/*   Updated: 2018/03/17 14:28:59 by dsaadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void read_nbants(void) {
	char *l;

	while (get_next_line(0, &l) > 0 && !ft_isnumstr(l))
	{
		if (!is_comment_line(l) && ft_printf("ERROR\n") && ft_strdelbool(&l))
			exit(EXIT_SUCCESS);
		ft_strdel(&l);
	}
	NBANTS = 10;
	if (((NBANTS = (int)ft_atoi(l)) == 0) && ft_printf("ERROR\n"))
		exit(EXIT_SUCCESS);
	ft_strdel(&l);
}

static	int read_line(char *l)
{
	static char *room_type = 0;
	static int room_num = -1;

	if (is_command_line(l))
		room_type = is_command_line(l);
	else if (is_room_line(l) && (++room_num) >= 0)
	{
		if (!init_room(l, room_type, room_num)
		&& ft_printf("ERROR\n") && ft_strdelbool(&l))
			return (good_or_exit());
	}
	else if (is_tube_line(l))
	{
		if (!init_tube(l) && ft_printf("ERROR\n") && ft_strdelbool(&l))
			return (good_or_exit());
	}
	else if (!is_comment_line(l) && ft_strdelbool(&l))
		return (good_or_exit());
	if (!is_command_line(l))
		room_type = 0;
	return (1);
}

void	read_lemin(void)
{
	char	*l;
	int		status;

	init_g_lemin();
	read_nbants();
	status = 1;
	while (status && get_next_line(0, &l) > 0)
	{
		if (!is_comment_line(l))
			ft_printf("%s\n",l);
		if ((status = read_line(l)))
			ft_strdel(&l);
	}
	if (!add_ants())
		exit(EXIT_FAILURE);
}
