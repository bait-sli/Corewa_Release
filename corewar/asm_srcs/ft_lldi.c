/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lldi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bait-sli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 07:22:36 by bait-sli          #+#    #+#             */
/*   Updated: 2018/03/24 21:31:31 by bait-sli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			ft_lldi(char *line, t_env *env)
{
	char	*tmp;
	char	**sp;

	tmp = ft_strsub(line, 0, ft_charchr(line, ' '));
	if (ft_strcmp(tmp, "lldi") != 0 || ft_count_char(line, SEPARATOR_CHAR) != 2)
		return (free_and_return(0, tmp));
	free(tmp);
	tmp = ft_strsub(line, 4, ft_strlen(line));
	sp = ft_strsplit(tmp, SEPARATOR_CHAR);
	free(tmp);
	if (char_len(sp) != 3)
	{
		env->error_code = BAD_PARAM_NBR;
		return (free_split(0, sp));
	}
	env->error_code = PARAM_ERR;
	if (isreg(sp[0]) == 0 && isindir(sp[0]) == 0 && isdir(sp[0]) == 0)
		return (free_split(0, sp));
	if (isdir(sp[1]) == 0 && isreg(sp[1]) == 0)
		return (free_split(0, sp));
	if (isreg(sp[2]) == 0)
		return (free_split(0, sp));
	return (free_split(1, sp));
}
