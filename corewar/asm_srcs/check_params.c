/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bait-sli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 07:19:25 by bait-sli          #+#    #+#             */
/*   Updated: 2018/03/24 21:01:58 by bait-sli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			ft_is_digit(char *line, int begin)
{
	int		i;

	i = begin;
	if (line[i] != '-' && ft_isdigit(line[i]) != 1)
		return (0);
	if (line[i] == '-')
		i += 1;
	while (line[i] != '\0')
	{
		if (ft_isdigit(line[i]) != 1)
			return (0);
		i++;
	}
	return (1);
}

int			isreg(char *line)
{
	char	*tmp;

	tmp = ft_epur_str(line);
	if (tmp[0] != 'r' || ft_strlen(tmp) > 3 || ft_strlen(tmp) > 3)
		return (free_and_return(0, tmp));
	if (ft_strlen(tmp) == 3)
	{
		if (ft_charchr(REG_DIGIT, tmp[2]) == -1 || tmp[1] != '1')
			return (free_and_return(0, tmp));
	}
	if (ft_strlen(tmp) == 2)
	{
		if (ft_isdigit(tmp[1]) == 0)
			return (free_and_return(0, tmp));
	}
	return (free_and_return(1, tmp));
}

int			isdir(char *line)
{
	int		i;
	char	*ptr;
	char	*tmp;

	i = 2;
	tmp = ft_epur_str(line);
	if (tmp[0] != DIRECT_CHAR)
		return (free_and_return(0, tmp));
	if (tmp[1] != LABEL_CHAR)
	{
		if (ft_is_digit(tmp, 1) != 1)
			return (free_and_return(0, tmp));
	}
	if (tmp[1] == LABEL_CHAR)
	{
		while (tmp[i])
		{
			if (!(ptr = ft_strchr(LABEL_CHARS, tmp[i])))
				return (free_and_return(0, tmp));
			i++;
		}
	}
	return (free_and_return(1, tmp));
}

int			is_name(char *line, char *format)
{
	return ((ft_strcmp(line, format) == 0) ? 1 : 0);
}

int			isindir(char *line)
{
	char	*tmp;
	int		i;
	char	*ptr;

	i = 1;
	tmp = ft_epur_str(line);
	if (tmp[0] != LABEL_CHAR)
	{
		if (ft_is_digit(tmp, 0) != 1)
			return (free_and_return(0, tmp));
	}
	if (tmp[0] == LABEL_CHAR)
	{
		while (tmp[i])
		{
			if (!(ptr = ft_strchr(LABEL_CHARS, tmp[i])))
				return (free_and_return(0, tmp));
			i++;
		}
	}
	return (free_and_return(1, tmp));
}
