/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verificators2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 13:17:24 by dsaadia           #+#    #+#             */
/*   Updated: 2018/03/17 13:35:20 by dsaadia          ###   ########.fr       */
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
