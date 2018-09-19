/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acombe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 22:44:45 by acombe            #+#    #+#             */
/*   Updated: 2018/04/25 22:44:50 by acombe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static char		nbr_to_base(int number)
{
	char	*base;

	base = "0123456789abcdef";
	return (base[number]);
}

static int		size_itoa(intmax_t value, int base)
{
	int		i;

	i = 1;
	while ((value / base) != 0)
	{
		value = value / base;
		i++;
	}
	return (i);
}

static void		fill_str(intmax_t value, int base, char *str, int i)
{
	while ((value / base) != 0)
	{
		str[i] = nbr_to_base(-(value % base));
		i--;
		value = value / base;
	}
	str[i] = nbr_to_base(-(value % base));
}

char			*ft_itoa_base(intmax_t value, int base)
{
	char	*itoa;
	int		size;

	if (base < 2 || base > 16)
		return (NULL);
	size = size_itoa(value, base);
	if (value < 0 && base == 10)
		size++;
	if (!(itoa = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	if (value < 0 && base == 10)
		itoa[0] = '-';
	else if (value > 0)
		value = -value;
	itoa[size] = '\0';
	fill_str(value, base, itoa, size - 1);
	return (itoa);
}
