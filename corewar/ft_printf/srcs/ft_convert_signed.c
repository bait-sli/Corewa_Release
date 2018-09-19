/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_convert_signed.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bait-sli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 23:15:55 by bait-sli          #+#    #+#             */
/*   Updated: 2017/06/07 23:16:11 by bait-sli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static intmax_t	get_arg(va_list ap, char id, t_length length)
{
	intmax_t output;

	if (length.l >= 2)
		output = (intmax_t)va_arg(ap, long long);
	else if (length.l == 1 || id == 'D')
		output = (intmax_t)va_arg(ap, long);
	else if (length.z >= 1)
		output = va_arg(ap, ssize_t);
	else if (length.j >= 1)
		output = va_arg(ap, intmax_t);
	else if (length.h >= 2)
		output = (intmax_t)(char)va_arg(ap, int);
	else if (length.h == 1)
		output = (intmax_t)(short)va_arg(ap, int);
	else
		output = (intmax_t)va_arg(ap, int);
	return (output);
}

char			*ftpf_convert_signed(va_list ap, t_specifiers specifiers,
									int *size)
{
	intmax_t	arg;
	int			base;
	char		*s;

	arg = get_arg(ap, specifiers.identifier, specifiers.length);
	base = ftpf_get_conv_base(specifiers.identifier);
	s = ft_itoa_base_lld(arg, base);
	*size = ft_strlen(s);
	return (s);
}
