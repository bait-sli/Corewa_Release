/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bait-sli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 07:21:39 by bait-sli          #+#    #+#             */
/*   Updated: 2018/03/24 21:24:20 by bait-sli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			ft_ld(char *line, t_env *env)
{
	char	*tmp;
	char	**sp;

	tmp = ft_strsub(line, 0, ft_charchr(line, ' '));
	if (ft_strcmp(tmp, "ld") != 0 || ft_count_char(line, SEPARATOR_CHAR) != 1)
		return (free_and_return(0, tmp));
	free(tmp);
	tmp = ft_strsub(line, 2, ft_strlen(line));
	sp = ft_strsplit(tmp, SEPARATOR_CHAR);
	free(tmp);
	if (char_len(sp) != 2)
	{
		env->error_code = BAD_PARAM_NBR;
		return (free_split(0, sp));
	}
	env->error_code = PARAM_ERR;
	if (isdir(sp[0]) == 0 && isindir(sp[0]) == 0)
		return (free_split(0, sp));
	if (isreg(sp[1]) == 0)
		return (free_split(0, sp));
	return (free_split(1, sp));
}
