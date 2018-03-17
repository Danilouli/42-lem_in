/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finders.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schmurz <schmurz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 09:37:36 by schmurz           #+#    #+#             */
/*   Updated: 2018/03/17 11:42:47 by dsaadia          ###   ########.fr       */
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

t_room	start_room(void)
{
	int i;
	t_room urgret;

	i = 0;
	urgret.no = -1;
	while (i < NBROOMS)
	{
		if (ft_strequ(ROOMS[i].type, "start"))
			return(ROOMS[i]);
		i++;
	}
	return (urgret);
}

t_room	end_room(void)
{
	int i;
	t_room urgret;

	i = 0;
	urgret.no = -1;
	while (i < NBROOMS)
	{
		if (ft_strequ(ROOMS[i].type, "end"))
			return(ROOMS[i]);
		i++;
	}
	return (urgret);
}
