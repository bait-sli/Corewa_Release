/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dump_header.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bait-sli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 07:21:14 by bait-sli          #+#    #+#             */
/*   Updated: 2018/03/24 21:20:23 by bait-sli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int		check_size(char *line, t_env *env, char *macro)
{
	if (ft_strcmp(macro, NAME_CMD_STRING) == 0)
	{
		if (ft_strlen(line) <= 128)
			return (1);
	}
	if (ft_strcmp(macro, COMMENT_CMD_STRING) == 0)
	{
		if (ft_strlen(line) <= 2048)
			return (1);
	}
	env->error_code = NAME_ERR;
	return (0);
}

static int		attribute(char *line, t_env *env, char *macro)
{
	if (ft_strcmp(macro, NAME_CMD_STRING) == 0)
	{
		if (check_size(line, env, macro) == 1)
		{
			if (!(env->prog_name = malloc((PROG_NAME_LENGTH) * sizeof(char))))
				return (0);
			ft_memset(env->prog_name, 0, (PROG_NAME_LENGTH));
			env->prog_name = ft_strcpy(env->prog_name, line);
			return (free_and_return(1, line));
		}
	}
	if (ft_strcmp(macro, COMMENT_CMD_STRING) == 0)
	{
		if (check_size(line, env, macro) == 1)
		{
			if (!(env->prog_comment = malloc((COMMENT_LENGTH) * sizeof(char))))
				return (0);
			ft_memset(env->prog_comment, 0, (COMMENT_LENGTH));
			env->prog_comment = ft_strcpy(env->prog_comment, line);
			return (free_and_return(1, line));
		}
	}
	free(line);
	return (0);
}

int				dump_header(char *line, t_env *env, char *macro)
{
	int			i;
	int			j;
	char		*tmp;
	char		*sub;

	i = ft_charchr(line, '"') + 1;
	tmp = ft_strsub(line, i, ft_strlen(line));
	j = ft_charchr(tmp, '"');
	sub = ft_strsub(tmp, 0, j);
	free(tmp);
	return (attribute(sub, env, macro));
}
