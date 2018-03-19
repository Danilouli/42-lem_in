/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verificators.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 17:58:06 by dsaadia           #+#    #+#             */
/*   Updated: 2018/03/19 21:39:57 by dsaadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		is_room_line(char *l)
{
	int i;
	int spcs;

	i = 0;
	spcs = 0;
	if (l[0] == ' ' || l[0] == '#' || l[0] == 'L' || !ft_isprint(l[0]))
		return (0);
	while (l[i] && l[i] != ' ')
		i++;
	spcs = (l[i] == ' ') ? spcs + 1 : spcs;
	if (!l[i] || !l[i + 1])
		return (0);
	i++;
	while (l[i] && l[i] != ' ')
	{
		if (!ft_isdigit(l[i]))
			return (0);
		i++;
	}
	spcs = (l[i] == ' ') ? spcs + 1 : spcs;
	if (!l[i + 1] || !ft_isnumstr(l + i + 1))
		return (0);
	return (spcs == 2);
}

int		is_room_name(char *str)
{
	int i;

	i = 0;
	while (i < NBROOMS)
	{
		if (ft_strequ(ROOMS[i].name, str))
			return (1);
		i++;
	}
	return (0);
}

int		is_tube_line(char *l)
{
	int i;
	int len;

	i = 0;
	len = 0;
	if (l[0] == ' ' || l[0] == '#' || l[0] == 'L' || !ft_isprint(l[0]))
		return (0);
	while (i < NBROOMS)
	{
		len = ft_strlen(ROOMS[i].name);
		if (ft_strequ(ft_strstr(l, ROOMS[i].name), l) && l[len] == '-'
		&& is_room_name(l + len + 1))
			return (1);
		i++;
	}
	return (0);
}

char	*is_command_line(char *l)
{
	if (!(l[0] == '#' && l[1] == '#'))
		return (0);
	if (!ft_strequ(l + 2, "start") && !ft_strequ(l + 2, "end"))
		return (0);
	return ((ft_strequ(l + 2, "start")) ? "start" : "end");
}

int		is_comment_line(char *l)
{
	if (is_command_line(l))
		return (0);
	return (l[0] == '#');
}
