/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bait-sli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 07:22:58 by bait-sli          #+#    #+#             */
/*   Updated: 2018/04/05 16:09:12 by bait-sli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int			op_check(char *line, t_env *env)
{
	char			*tmp;

	if (env->verif.name == 0 || env->verif.comment == 0)
	{
		env->error_code = HEADER_ERR;
		return (0);
	}
	tmp = remove_comment(line);
	if (ft_is_label_only(tmp, env) == 1)
	{
		add_label(tmp, &env->buff, env);
		return (free_and_return(1, tmp));
	}
	if (ft_check_instruction(tmp, env) == 1)
	{
		add_instruction(tmp, &env->buff, env);
		return (free_and_return(1, tmp));
	}
	if (ft_label_and_instru(tmp, env) == 1)
	{
		add_lab_instruct(tmp, &env->buff, env);
		return (free_and_return(1, tmp));
	}
	return (free_and_return(0, tmp));
}

static int			ft_check_line(char *line, char *tmp, t_env *env)
{
	if (line_is_empty(line) == 1)
		return (1);
	if (ft_is_comment(line) == 1)
		return (1);
	if (ft_is_header(line, NAME_CMD_STRING) == 1 && env->verif.name == 0)
	{
		if (dump_header(tmp, env, NAME_CMD_STRING) == 1)
		{
			env->verif.name = 1;
			return (1);
		}
	}
	if (ft_is_header(line, COMMENT_CMD_STRING) == 1 && env->verif.comment == 0)
	{
		if (dump_header(tmp, env, COMMENT_CMD_STRING) == 1)
		{
			env->verif.comment = 1;
			return (1);
		}
	}
	if (op_check(line, env) == 1)
		return (1);
	return (0);
}

static void			free_gnl(char *line, char *tmp)
{
	free(line);
	free(tmp);
}

void				ft_parsing(char *file, t_env *env)
{
	int				fd;
	char			*line;
	char			*tmp;
	int				x;

	line = NULL;
	if (!((fd = open(file, O_RDONLY)) >= 0))
		ft_error(ERR_FILE, env);
	while ((x = get_next_line(fd, &line)))
	{
		if (x < 0)
		{
			free(line);
			ft_error(ERR_FILE, env);
		}
		tmp = ft_epur_str(line);
		if (ft_check_line(tmp, line, env) == 0)
		{
			free_gnl(line, tmp);
			ft_line_error(env->error_code, env, env->line_nbr);
		}
		free_gnl(line, tmp);
		env->line_nbr++;
	}
	close(fd);
}
