/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verificators2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 13:17:24 by dsaadia           #+#    #+#             */
/*   Updated: 2018/03/19 11:03:18 by schmurz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	read_ok(void)
{
	t_room start;
	t_room end;

	start = start_room();
	end = end_room();
	if (start.no != -1 && end.no != -1)
		return (1);
	return (0);
}

int good_or_exit() {
	if (read_ok())
		return (0);
	else
		exit(EXIT_SUCCESS);
}

int is_option(char *option, char **av)
{
	int i;

	i = 1;
	while (av[i])
	{
		if (ft_strequ(option, av[i]))
			return (1);
		i++;
	}
	return (0);
}
