/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bait-sli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 23:12:39 by bait-sli          #+#    #+#             */
/*   Updated: 2017/06/07 23:12:45 by bait-sli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strndup(char const *s1, size_t n)
{
	size_t	i;
	char	*dup;

	i = 0;
	while (s1[i] != '\0' && i < n)
		i++;
	n = i;
	dup = (char*)malloc(sizeof(char) * (i + 1));
	if (dup == 0)
		return (NULL);
	i = 0;
	while (i < n)
	{
		dup[i] = s1[i];
		i++;
	}
	dup[n] = '\0';
	return (dup);
}
