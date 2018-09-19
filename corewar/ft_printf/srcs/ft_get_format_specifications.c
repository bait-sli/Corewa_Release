/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_get_format_specifications.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bait-sli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 23:16:58 by bait-sli          #+#    #+#             */
/*   Updated: 2017/06/07 23:17:04 by bait-sli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ftpf_get_format_specifications(char const **format, va_list ap,
											t_specifiers *specifiers)
{
	while (ftpf_is_flag(**format) || ft_isdigit(**format) || **format == '*' ||
		**format == '.' || ftpf_is_length_specifier(**format))
	{
		if (ftpf_is_flag(**format))
			ftpf_get_flags(format, specifiers);
		else if (ft_isdigit(**format) || **format == '*')
			ftpf_get_width(format, specifiers, ap);
		else if (**format == '.')
			ftpf_get_precision(format, specifiers, ap);
		else if (ftpf_is_length_specifier(**format))
			ftpf_get_length_specifier(format, specifiers);
	}
	if (**format)
		ftpf_get_identifier(format, specifiers);
	else
		specifiers->identifier = '\0';
}
