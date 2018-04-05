/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schmurz <schmurz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 20:22:50 by schmurz           #+#    #+#             */
/*   Updated: 2018/04/05 18:12:36 by dsaadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	main(int ac, char **av)
{
	(void)ac;
	read_lemin(is_option("-q", av));
	if (is_option("-v", av))
		print_lemin(is_option("-m", av));
	if (read_ok())
		manage_ants();
	else
		ft_putendl("ERROR - NO START OR NO END");
	free_all();
	return (0);
}
