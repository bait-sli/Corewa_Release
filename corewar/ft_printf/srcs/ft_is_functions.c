/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_is_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bait-sli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 23:18:24 by bait-sli          #+#    #+#             */
/*   Updated: 2017/06/07 23:18:30 by bait-sli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_bool	ftpf_is_unsigned_conv(char c)
{
	return (c == 'u' || c == 'U' || c == 'o' || c == 'O' ||
			c == 'x' || c == 'X' ||
			c == 'b' || c == 'B' || c == 'p');
}

t_bool	ftpf_is_signed_conv(char c)
{
	return (c == 'd' || c == 'D' || c == 'i');
}

t_bool	ftpf_is_characters_conv(char c)
{
	return (c == 'c' || c == 'C' || c == 's' || c == 'S');
}
