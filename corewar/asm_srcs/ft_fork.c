/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bait-sli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 07:21:26 by bait-sli          #+#    #+#             */
/*   Updated: 2018/03/24 21:22:36 by bait-sli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			ft_fork(char *line, t_env *env)
{
	char	*tmp;

	tmp = ft_strsub(line, 0, ft_charchr(line, ' '));
	if (ft_strcmp(tmp, "fork") != 0)
		return (free_and_return(0, tmp));
	free(tmp);
	tmp = ft_strsub(line, 4, ft_strlen(line));
	env->error_code = PARAM_ERR;
	if (isdir(tmp) == 0)
		return (free_and_return(0, tmp));
	return (free_and_return(1, tmp));
}
