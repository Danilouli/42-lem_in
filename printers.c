/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 11:12:55 by dsaadia           #+#    #+#             */
/*   Updated: 2018/03/19 11:13:00 by schmurz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void print_mat()
{
	int j;
	int i;

	ft_printf("\nMatrice d' adjacence\n");
	i = -1;
	while (++i < ADJ.nbl)
	{
		j = -1;
		ft_putstr("| ");
		while (++j < ADJ.nbc)
			ft_printf("%d ",MAT(i,j));
		ft_putstr("|\n");
	}
}

void print_lemin(int op) {
	int i;
	int j;

	i = -1;
	j = -1;
	ft_putendl("***********INFOS***********");
	ft_printf("\nNombre de fourmis :  %d",NBANTS);
	ft_printf("\nNombre de chambres : %d\n\nLes chambres :\n",NBROOMS);
	while (++i < NBROOMS)
		ft_printf("C no %d : nom %s, type %s, nb de fourmis %d, queue %d\n",i, ROOMS[i].name, ROOMS[i].type,
		ROOMS[i].count, ROOMS[i].queue);
	if (op)
		print_mat();
	i = -1;
	ft_putstr("\nFourmis\n");
	while (++i < NBANTS)
		ft_printf("Fourmi no %d : se trouve en salle %s (salle no %d)\n",
		ANTS[i].no, ANTS[i].room.name, ANTS[i].room.no);
	ft_putendl("\n***********FIN INFOS***********\n");
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
