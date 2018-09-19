/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unicode_encoder_string.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bait-sli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 23:13:59 by bait-sli          #+#    #+#             */
/*   Updated: 2017/06/07 23:14:05 by bait-sli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_unicode_encoder_string(wchar_t *unicode_str)
{
	char	*encoding;
	char	*to_add;
	char	*tmp;

	encoding = ft_strdup("");
	while (*unicode_str)
	{
		if ((to_add = ft_unicode_encoder((wint_t)(*unicode_str))) == NULL)
			return (NULL);
		tmp = encoding;
		encoding = ft_strjoin(encoding, to_add);
		free(to_add);
		free(tmp);
		unicode_str++;
	}
	return (encoding);
}
