/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schmurz <schmurz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 20:22:50 by schmurz           #+#    #+#             */
/*   Updated: 2018/03/18 15:15:30 by dsaadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	main(void)
{
	int i = 0;
	// int next;

	read_lemin();
	// print_lemin();
	// ft_printf("\n----------dijkstra----------\n");
	// next = dijkstra(start_room());
	// ft_printf("next %d\n",next);
	manage_ants();
	while (i < NBROOMS)
	{
		ft_strdel(&(ROOMS[i].name));
		free(ROOMS[i].helptab);
		free(ADJ.inds[i]);
		i++;
	}
	free(ADJ.inds);
	free(ROOMS);
	free(ANTS);
	while (1);
	return (0);
}
