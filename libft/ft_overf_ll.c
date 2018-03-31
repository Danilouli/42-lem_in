/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_overf_ll.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaadia <dsaadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 16:10:47 by dsaadia           #+#    #+#             */
/*   Updated: 2018/03/31 16:28:30 by dsaadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_overf_ll(char *llstr)
{
	long long	atoi_ll;
	char		*re_itoa;
	int			ret;

	atoi_ll = ft_atoi(llstr);
	re_itoa = ft_itoa(atoi_ll);
	if (ft_strequ(re_itoa, llstr) && atoi_ll <= 9223372036854775807)
		ret = 0;
	else
		ret = 1;
	ft_strdel(&re_itoa);
	return (ret);
}
