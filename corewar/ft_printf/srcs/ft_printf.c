/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bait-sli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 23:11:34 by bait-sli          #+#    #+#             */
/*   Updated: 2017/06/07 23:11:43 by bait-sli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*get_formated_string(const char **format, va_list ap,
									int *size, int n)
{
	t_specifiers	specifiers;
	char			*s;

	ftpf_initialize_specifiers(&specifiers);
	ftpf_get_format_specifications(format, ap, &specifiers);
	s = ftpf_get_raw_data(ap, specifiers, size, n);
	if (s != NULL)
		ftpf_process_data(&s, size, specifiers);
	return (s);
}

int			ft_printf(const char *format, ...)
{
	va_list	ap;
	char	*s;
	int		size;
	int		n;

	n = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format != '%')
			ft_putchar(*format++);
		else
		{
			format++;
			if ((s = get_formated_string(&format, ap, &size, n)) == NULL)
				return (-1);
			write(1, s, size);
			n = n + size - 1;
			free(s);
		}
		n++;
	}
	va_end(ap);
	return (n);
}
