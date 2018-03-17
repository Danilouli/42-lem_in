/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dijkstra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 14:45:23 by dsaadia           #+#    #+#             */
/*   Updated: 2018/03/17 21:39:03 by dsaadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void init_dists_way(int **dists, int **pred, t_room from)
{
	int i;

	i = -1;
	while (++i < NBROOMS)
	{
		if (ROOMS[i].no == from.no)
			(*dists)[ROOMS[i].no] = 0;
		else
			(*dists)[ROOMS[i].no] = INF;
	}
	i = -1;
	while (++i < NBROOMS)
			(*pred)[ROOMS[i].no] = (ROOMS[i].no == from.no) ? -2 : -1;
}

int	get_min_dist(int *dists, int *explo)
{
	int i;
	int md;
	int ret;

	i = -1;
	md = INF;
	ret = -1;
	while (++i < NBROOMS)
	{
		if (!explo[ROOMS[i].no] && dists[ROOMS[i].no] < md)
		{
			md = dists[ROOMS[i].no];
			ret = ROOMS[i].no;
		}
	}
	return (ret);
}

void update_dists_for_room(int m, int *dists, int **pred, int **explo)
{
	int i;
	int d;

	i = -1;
	d = 0;
	while (++i < NBROOMS)
	{
		if (MAT(m, ROOMS[i].no) && !explo[ROOMS[i].no]
		&& (d = dists[m] + ROOMS[i].queue) < dists[ROOMS[i].no])
		{
			dists[ROOMS[i].no] = d;
			(*pred)[ROOMS[i].no] = m;
		}
	}
	(*explo)[m] = 1;
}

int update_dists_for_rooms(int *dists, int **pred, int **explo)
{
	int md;
	int m;
	int finished;

	md = get_min_dist(dists, *explo);
	m = -1;
	finished = 1;
	while (++m < NBROOMS)
	{
		if (!explo[m] && dists[m] == md
		&& !ft_strequ(ROOMS[m].type, "end") && (finished = 0) >= 0)
			update_dists_for_room(m, dists, pred, explo);
	}
	return (finished);
}

int	dijkstra(t_room from)
{
	int			*pred;
	int			*explo;
	int			*dists;

	if (!(pred = ft_intarr_init(NBROOMS)) || !(explo = ft_intarr_init(NBROOMS))
	|| !(dists = ft_intarr_init(NBROOMS)))
		return (-1);
	init_dists_way(&dists, &pred, from);
	while (!update_dists_for_rooms(dists, &pred, &explo))
		;
}
