/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intarr_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schmurz <schmurz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 10:47:52 by schmurz           #+#    #+#             */
/*   Updated: 2018/03/19 10:48:18 by schmurz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_intarr_init(int len)
{
	int i;
	int *ret;

	i = 0;
	if (!(ret = (int*)malloc(sizeof(int) * len)))
		return (0);
	while (i < len)
	{
		ret[i] = 0;
		i++;
	}
	return (ret);
}
