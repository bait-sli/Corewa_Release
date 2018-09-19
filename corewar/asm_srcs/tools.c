/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bait-sli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 07:24:36 by bait-sli          #+#    #+#             */
/*   Updated: 2018/04/05 15:59:42 by bait-sli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			ft_count_char(char *str, char c)
{
	int		count;
	int		i;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			count += 1;
		i++;
	}
	return (count);
}

int			char_len(char **format)
{
	int		index;

	index = 0;
	while (format[index] != NULL)
		index++;
	return (index);
}

int			tab_len(int *tab)
{
	int		index;

	index = 0;
	while (tab[index])
		index++;
	return (index);
}

int			ft_charchr(char *line, char c)
{
	int		i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == c)
			return (i);
		i++;
	}
	return (-1);
}
