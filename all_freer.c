/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_freer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 17:46:03 by dsaadia           #+#    #+#             */
/*   Updated: 2018/04/05 18:13:51 by dsaadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	free_all(void)
{
	int i;

	i = 0;
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
	return (1);
}
