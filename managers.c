/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   managers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schmurz <schmurz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 08:41:54 by schmurz           #+#    #+#             */
/*   Updated: 2018/03/18 16:08:38 by dsaadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static	void 	move_ant(t_ant *ant, t_room *from, t_room *to)
{
	ft_printf("L%d-%s ",ant->no, to->name);
	if (from->count > 0)
		(from->count)--;
	if (ft_strequ(from->type, "path") && from->queue > 1)
		(from->queue)--;
	ant->room = *to;
	if (ft_strequ(to->type, "path"))
		(to->queue)++;
	(to->count)++;
}

static 	void	manage_ant(t_ant *ant)
{
	int nm;

	nm = dijkstra(ant->room);
	if (ft_strequ((ant->room).type, "end"))
		return ;
	if (nm < 0)
	{
		ft_printf("LOGIC ERROR 1\n");
		exit(EXIT_FAILURE);
	}
	if (ft_strequ(ROOMS[nm].type, "path"))
	{
		if (ROOMS[nm].count == 1)
			ROOMS[nm].queue++;
		else if (ROOMS[nm].count == 0)
			move_ant(ant, &(ROOMS[(ant->room).no]), &(ROOMS[nm]));
		else if (ROOMS[nm].count < 0 || ROOMS[nm].count > 1)
		{
			ft_printf("LOGIC ERROR 2\n");
			exit(EXIT_FAILURE);
		}
	}
	else if (ft_strequ(ROOMS[nm].type, "end"))
		move_ant(ant, &(ROOMS[(ant->room).no]), &(ROOMS[nm]));
}

void manage_ants(void) {
	int i;

	while (((end_room()).count < NBANTS))
	{
		i = -1;
		while (++i < NBANTS)
				manage_ant(&(ANTS[i]));
		ft_putchar('\n');
		// print_lemin();
	}
}
