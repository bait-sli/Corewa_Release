/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_label.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bait-sli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 20:38:12 by bait-sli          #+#    #+#             */
/*   Updated: 2018/03/24 20:44:40 by bait-sli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int				label_ref(char *data)
{
	if (isdir(data) == 1)
	{
		if (data[1] == LABEL_CHAR)
			return (1);
	}
	if (isindir(data) == 1)
	{
		if (data[0] == LABEL_CHAR)
			return (1);
	}
	return (0);
}

static char		*get_label(char *data)
{
	char		*tmp;
	char		*ret;

	tmp = NULL;
	if (isdir(data) == 1)
		tmp = ft_strsub(data, 2, ft_strlen(data));
	else if (isindir(data) == 1)
		tmp = ft_strsub(data, 1, ft_strlen(data));
	ret = ft_strjoin(tmp, ":");
	free(tmp);
	return (ret);
}

static int		label_exist(char *label, t_parse **buff, t_env *env)
{
	char		*tmp;
	t_parse		*elem;
	int			pos;

	pos = 0;
	tmp = get_label(label);
	elem = *buff;
	while (elem != NULL)
	{
		if (elem->label_name != NULL)
		{
			if (ft_strcmp(tmp, elem->label_name) == 0)
			{
				env->verif.lab_pos = pos;
				ft_label_to_int(env);
				free(tmp);
				return (1);
			}
		}
		pos++;
		elem = elem->next;
	}
	free(tmp);
	return (0);
}

static void		verif_label(char **data, t_parse **buff, t_env *env)
{
	int			i;

	i = 0;
	while (i < char_len(data))
	{
		if (label_ref(data[i]) == 1)
		{
			env->verif.ref_pos = i;
			if (label_exist(data[i], buff, env) == 0)
				ft_label_error(LABEL_ERR, data[i], env);
		}
		i++;
	}
}

void			check_label(t_parse **buff, t_env *env)
{
	t_parse		*elem;
	int			pos;

	pos = 0;
	elem = *buff;
	while (elem != NULL)
	{
		if (elem->form.dir_instruct == 1 || elem->form.labeled_instruct == 1)
		{
			env->line_nbr = elem->form.line_in_file;
			env->verif.line_pos = pos;
			verif_label(elem->params, buff, env);
		}
		pos++;
		elem = elem->next;
	}
}
