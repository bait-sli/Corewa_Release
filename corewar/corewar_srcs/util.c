/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acombe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 23:01:07 by acombe            #+#    #+#             */
/*   Updated: 2018/04/25 23:01:52 by acombe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_convert_mem(t_memory mem[MEM_SIZE])
{
	int		i;
	char	*tmp;

	i = -1;
	while (++i < MEM_SIZE)
	{
		tmp = ft_itoa_base(mem[i].octet, 16);
		if (ft_strlen(tmp) == 2)
			mem[i].itoa_value = ft_strdup(tmp);
		else
			mem[i].itoa_value = ft_strjoin("0", tmp);
		free(tmp);
	}
}

int		st_isdigit(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (ft_isdigit(line[i]) != 1)
			return (0);
		i++;
	}
	return (1);
}
