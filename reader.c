/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schmurz <schmurz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 20:17:42 by schmurz           #+#    #+#             */
/*   Updated: 2018/03/15 19:53:31 by dsaadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	get_start(void)
{
	char *l;
	if ((get_next_line(0, &l) <= 0 || ) && ft_printf("ERROR"))
	{
		ft_strdel(&l);
		exit(EXIT_SUCCESS);
	}

}

void	read_lemin(void)
{
	char *l;
	int can_go;
	char *room_type;

	can_go = 0;
	room_type = 0;
	while (get_next_line(0, &l) > 0 && !ft_isnumstr(l))
	{
		if (l[0] != '#' && ft_printf("ERROR"))
		{
			ft_strdel(&l);
			exit(EXIT_SUCCESS);
		}
		ft_strdel(&l);
	}
	if (((NBANTS = (int)ft_atoi(l)) == 0) && ft_printf("ERROR"))
		exit(EXIT_SUCCESS);
	while (get_next_line(0, &l) > 0)
	{
		if ()
		if ()
		ft_strdel(&l);
	}
}
