/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bait-sli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 07:20:07 by bait-sli          #+#    #+#             */
/*   Updated: 2018/03/24 21:08:19 by bait-sli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int				free_and_return(int ret, char *data)
{
	if (!data || data == NULL)
		return (ret);
	free(data);
	return (ret);
}

int				free_split(int ret, char **content)
{
	int			index;

	if (!content)
		return (ret);
	index = 0;
	while (content[index])
	{
		free(content[index]);
		index++;
	}
	free(content);
	return (ret);
}

static void		free_tab(int *tab)
{
	if (!tab)
		return ;
	free(tab);
}

void			free_parse(t_parse **content)
{
	t_parse		*elem;
	t_parse		*save;

	if (!content)
		return ;
	elem = *content;
	while (elem)
	{
		save = elem->next;
		free_and_return(1, elem->line);
		free_and_return(1, elem->op_name);
		free_and_return(1, elem->label_name);
		free_split(0, elem->params);
		free_tab(elem->binary);
		free(elem);
		elem = save;
	}
}

void			free_mem(t_env *env)
{
	free_and_return(1, env->output_name);
	free_and_return(1, env->prog_name);
	free_and_return(1, env->prog_comment);
	free_parse(&env->buff);
}
