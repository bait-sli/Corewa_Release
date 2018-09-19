/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atgerard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 11:40:08 by atgerard          #+#    #+#             */
/*   Updated: 2018/04/26 05:21:30 by atgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

long long	ft_atoi_long_long(const char *str)
{
	int				i;
	long long		res;
	int				sign;

	i = -1;
	res = 0;
	sign = 1;
	while (str[++i] < '0' || str[i] > '9')
	{
		if (str[i] == '-' || str[i] == '+')
			break ;
		else if (str[i] != ' ' && str[i] != '\f' && str[i] != '\v' &&
				str[i] != '\r' && str[i] != '\n' && str[i] != '\t')
			return (res);
	}
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		++i;
	while (str[++i - 1] >= '0' && str[i - 1] <= '9')
		res = res * 10 + (str[i - 1] - '0') * sign;
	return (res);
}
