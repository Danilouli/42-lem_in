/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_in_strtab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 19:32:33 by dsaadia           #+#    #+#             */
/*   Updated: 2018/03/15 19:33:40 by dsaadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_in_strtab(char *str, char **strtab)
{
	while (*strtab)
	{
		if (ft_strequ(str, *strtab))
			return (1);
	}
	return (0);
}
