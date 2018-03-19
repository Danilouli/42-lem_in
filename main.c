/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schmurz <schmurz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 20:22:50 by schmurz           #+#    #+#             */
/*   Updated: 2018/03/19 21:07:33 by dsaadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	main(int ac, char **av)
{
	int i;

	i = 0;
	(void)ac;
	read_lemin(is_option("-q", av));
	if (is_option("-v", av))
		print_lemin(is_option("-m", av));
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
	return (0);
}
