/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unicode_encoder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bait-sli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 23:13:36 by bait-sli          #+#    #+#             */
/*   Updated: 2017/06/07 23:13:46 by bait-sli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_unicode_encoder_four_digits(wint_t unicode, char *encoding)
{
	encoding[0] = (240 | (unicode >> 18));
	encoding[1] = (128 | ((unicode >> 12) & 63));
	encoding[2] = (128 | ((unicode >> 6) & 63));
	encoding[3] = (128 | (unicode & 63));
}

char			*ft_unicode_encoder(wint_t unicode)
{
	char	*encoding;

	encoding = (char*)ft_strnew(5);
	if (unicode <= 127)
		encoding[0] = unicode;
	else if (unicode <= 2047)
	{
		encoding[0] = (192 | (unicode & 1984) >> 6);
		encoding[1] = (128 | (unicode & 63));
	}
	else if (55296 <= unicode && unicode <= 57343)
		encoding = NULL;
	else if (unicode <= 65535)
	{
		encoding[0] = (224 | (unicode >> 12));
		encoding[1] = (128 | ((unicode >> 6) & 63));
		encoding[2] = (128 | (unicode & 63));
	}
	else if (unicode <= 1114111)
		ft_unicode_encoder_four_digits(unicode, encoding);
	return (encoding);
}
