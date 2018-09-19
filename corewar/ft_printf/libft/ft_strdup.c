/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bait-sli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 18:09:09 by bait-sli          #+#    #+#             */
/*   Updated: 2017/02/23 02:23:11 by bait-sli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *str)
{
	int		i;
	int		strlen;
	char	*strdup;

	i = 0;
	strlen = ft_strlen((char*)str);
	strdup = (char*)malloc((strlen + 1) * sizeof(*str));
	if (!strdup)
		return (NULL);
	while (i < strlen)
	{
		strdup[i] = str[i];
		i++;
	}
	strdup[strlen] = '\0';
	return (strdup);
}
