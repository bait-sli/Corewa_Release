/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_content.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bait-sli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 20:27:46 by bait-sli          #+#    #+#             */
/*   Updated: 2018/03/24 20:35:07 by bait-sli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static char		**epur_split(char **data)
{
	char		**ret;
	int			index;

	index = 0;
	if (!(ret = (char**)malloc(sizeof(char*) * (char_len(data) + 1))))
		return (NULL);
	while (index < char_len(data))
	{
		ret[index] = ft_epur_str(data[index]);
		index++;
	}
	ret[index] = NULL;
	free_split(1, data);
	return (ret);
}

static char		**one_param(char *line)
{
	char		**data;

	if (!(data = (char**)malloc(sizeof(char*) * 2)))
		return (NULL);
	data[0] = ft_epur_str(line);
	data[1] = NULL;
	return (data);
}

static void		build_instruction(t_parse *elem, char *line)
{
	int			i;
	char		*tmp;

	i = ft_charchr(line, ' ');
	elem->op_name = ft_strsub(line, 0, i);
	tmp = ft_strsub(line, i + 1, ft_strlen(line));
	if (ft_charchr(tmp, SEPARATOR_CHAR) <= 0)
	{
		elem->params = one_param(tmp);
		free(tmp);
		return ;
	}
	elem->params = epur_split(ft_strsplit(tmp, SEPARATOR_CHAR));
	free(tmp);
}

static void		build_labeled_instruct(t_parse *elem, char *line)
{
	char		*tmp;
	char		*tmp2;
	int			i;

	i = ft_charchr(line, LABEL_CHAR);
	elem->label_name = ft_strsub(line, 0, i + 1);
	tmp = ft_strsub(line, i + 1, ft_strlen(line));
	tmp2 = ft_epur_str(tmp);
	build_instruction(elem, tmp2);
	free(tmp);
	free(tmp2);
}

void			ft_build_content(t_parse **buff)
{
	t_parse		*elem;

	elem = *buff;
	while (elem != NULL)
	{
		if (elem->form.only_label == 1)
		{
			elem->label_name = ft_strdup(elem->line);
			elem->op_name = NULL;
			elem->params = NULL;
		}
		if (elem->form.dir_instruct == 1)
		{
			build_instruction(elem, elem->line);
			get_op_and_dir_size(elem);
			elem->label_name = NULL;
		}
		if (elem->form.labeled_instruct == 1)
		{
			build_labeled_instruct(elem, elem->line);
			get_op_and_dir_size(elem);
		}
		elem = elem->next;
	}
}
