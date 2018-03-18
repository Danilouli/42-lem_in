/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 11:12:55 by dsaadia           #+#    #+#             */
/*   Updated: 2018/03/18 10:18:41 by schmurz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void print_lemin(void) {
	int i;
	int j;

	i = -1;
	ft_printf("\nNombre de fourmis :  %d\n",NBANTS);
	ft_printf("\nNombre de chambres : %d\nLes chambres :\n",NBROOMS);
	while (++i < NBROOMS)
		ft_printf("C no %d : nom %s, type %s, nb de fourmis %d, queue %d\n",i, ROOMS[i].name, ROOMS[i].type,
		ROOMS[i].count, ROOMS[i].queue);
	i = -1;
	ft_printf("\nMatrice d' adjacence\n");
	while (++i < ADJ.nbl)
	{
		j = -1;
		ft_putstr("| ");
		while (++j < ADJ.nbc)
			ft_printf("%d ",MAT(i,j));
		ft_putstr("|\n");
	}
	i = -1;
	ft_putstr("\nFourmis\n");
	while (++i < NBANTS)
		ft_printf("Fourmi no %d : se trouve en salle %s (salle no %d)\n",
		ANTS[i].no, ANTS[i].room.name, ANTS[i].room.no);
}

void print_preds(int *pred)
{
	int j;

	ft_printf("Reverse chemin\n");
	j = (end_room()).no;
	while (j >= 0)
	{
		ft_printf("%d, ",j);
		j = pred[j];
	}
	ft_printf("\n(Fin sur un %d)\n",j);
}
