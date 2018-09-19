/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bait-sli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 07:19:11 by bait-sli          #+#    #+#             */
/*   Updated: 2018/03/24 20:55:58 by bait-sli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			ft_label_and_instru(char *line, t_env *env)
{
	int		i;
	char	*sub;
	char	*clean;

	i = ft_charchr(line, LABEL_CHAR);
	if (i == -1 || i == 0)
		return (0);
	sub = ft_strsub(line, 0, i + 1);
	if (ft_is_label_only(sub, env) == 0)
	{
		env->error_code = LABEL_INVALID_FORMAT;
		return (free_and_return(0, sub));
	}
	free(sub);
	sub = ft_strsub(line, i + 1, (ft_strlen(line) - i));
	clean = ft_epur_str(sub);
	free(sub);
	if (ft_check_instruction(clean, env) == 0)
		return (free_and_return(0, clean));
	return (free_and_return(1, clean));
}

int			line_is_empty(char *line)
{
	if (line == NULL)
		return (1);
	if (ft_strcmp(line, "") == 0)
		return (1);
	return (0);
}

int			ft_is_label_only(char *line, t_env *env)
{
	char	*ptr;
	size_t	index;
	size_t	len;

	index = 0;
	len = ft_strlen(line) - 1;
	ptr = NULL;
	env->error_code = LABEL_INVALID_FORMAT;
	if (line[len] != LABEL_CHAR)
		return (0);
	while (index < len - 1)
	{
		if (!(ptr = ft_strchr(LABEL_CHARS, line[index])))
			return (0);
		index++;
	}
	return (1);
}

int			ft_is_header(char *line, char *macro)
{
	char	*tmp;
	char	*rm_sharp;
	char	*clean;

	rm_sharp = rm_comment_in_hd(line);
	if (rm_sharp == NULL)
		return (0);
	tmp = ft_strsub(rm_sharp, 0, ft_strlen(macro));
	if (ft_strcmp(tmp, macro) != 0)
	{
		free(tmp);
		return (free_and_return(0, rm_sharp));
	}
	free(tmp);
	tmp = ft_strsub(rm_sharp, ft_strlen(macro), ft_strlen(rm_sharp));
	free(rm_sharp);
	clean = ft_epur_str(tmp);
	free(tmp);
	if (clean[0] != '"' || clean[ft_strlen(clean) - 1] != '"')
		return (free_and_return(0, clean));
	return (free_and_return(1, clean));
}

int			ft_is_comment(char *line)
{
	if (line[0] == '#')
		return (1);
	return (0);
}
