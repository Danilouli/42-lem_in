/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finders.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schmurz <schmurz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 09:37:36 by schmurz           #+#    #+#             */
/*   Updated: 2018/03/19 20:59:44 by dsaadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room	find_room(char *room_name)
{
	int		i;
	t_room	urgret;

	i = 0;
	urgret.no = -1;
	while (i < NBROOMS)
	{
		if (ft_strequ(ROOMS[i].name, room_name))
			return (ROOMS[i]);
		i++;
	}
	return (urgret);
}

t_room	start_room(void)
{
	int		i;
	t_room	urgret;

	i = 0;
	urgret.no = -1;
	while (i < NBROOMS)
	{
		if (ft_strequ(ROOMS[i].type, "start"))
			return (ROOMS[i]);
		i++;
	}
	return (urgret);
}

t_room	end_room(void)
{
	int		i;
	t_room	urgret;

	i = 0;
	urgret.no = -1;
	while (i < NBROOMS)
	{
		if (ft_strequ(ROOMS[i].type, "end"))
			return (ROOMS[i]);
		i++;
	}
	return (urgret);
}

int		find_way(int *pred, int ori)
{
	int j;

	ft_printf("from n %d\n", ori);
	j = (end_room()).no;
	while (j >= 0)
	{
		if (pred[j] == ori)
			return (j);
		j = pred[j];
	}
	return (-1);
}

int		find_way2(int *pred)
{
	int j;
	int k;
	int *help;
	int ret;

	if (!(help = ft_intarr_init(NBROOMS)))
		return (-1);
	j = (end_room()).no;
	k = 0;
	while (j >= 0)
	{
		help[k] = j;
		k++;
		j = pred[j];
	}
	if (k - 2 < 0)
		ret = ((end_room()).no);
	else
		ret = help[k - 2];
	free(help);
	return (ret);
}
