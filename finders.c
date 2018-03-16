/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finders.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schmurz <schmurz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 09:37:36 by schmurz           #+#    #+#             */
/*   Updated: 2018/03/16 13:25:44 by schmurz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room	find_room(char *room_name)
{
	int i;
	t_room urgret;

	i = 0;
	urgret.no = -1;
	while (i < NBROOMS)
	{
		if (ft_strequ(ROOMS[i].name, room_name))
			return(ROOMS[i]);
		i++;
	}
	return (urgret);
}
