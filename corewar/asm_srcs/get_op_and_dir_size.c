/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_op_and_dir_size.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bait-sli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 21:56:38 by bait-sli          #+#    #+#             */
/*   Updated: 2018/03/24 22:27:31 by bait-sli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

extern			t_op g_tab[20];

int				params_size(char *param, int dir)
{
	int			size;

	size = 0;
	if (isreg(param) == 1)
		size = 1;
	if (isdir(param) == 1)
		size = dir;
	if (isindir(param) == 1)
		size = 2;
	return (size);
}

static void		ft_line_size(t_parse *elem, char **params)
{
	int			i;

	i = 0;
	elem->content_size += 1;
	while (i < char_len(params))
	{
		elem->content_size += params_size(params[i], elem->dir_size);
		i++;
	}
	if (elem->form.has_ocp == 1)
		elem->content_size += 1;
}

void			get_op_and_dir_size(t_parse *elem)
{
	int			ret;
	int			index;

	ret = 0;
	index = -1;
	while (++index < 16)
	{
		if (ft_strcmp(elem->op_name, g_tab[index].name) == 0)
		{
			elem->opcode = g_tab[index].opcode;
			if (g_tab[index].dir_indir == 1)
				elem->dir_size = 2;
			if (g_tab[index].dir_indir == 0)
				elem->dir_size = 4;
			if (g_tab[index].ocp == 1)
				elem->form.has_ocp = 1;
		}
	}
	ft_line_size(elem, elem->params);
}
