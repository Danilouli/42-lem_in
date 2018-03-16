/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schmurz <schmurz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 20:22:50 by schmurz           #+#    #+#             */
/*   Updated: 2018/03/17 00:32:08 by schmurz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	main(void)
{
	int i = 0;

	read_lemin();
	while (i < NBROOMS)
	{
		ft_strdel(&(ROOMS[i].name));
		free(ADJ.inds[i]);
		i++;
	}
	free(ADJ.inds);
	free(ROOMS);
	while (1);
	return (0);
}
