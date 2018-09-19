/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acombe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 22:42:17 by acombe            #+#    #+#             */
/*   Updated: 2018/04/26 03:41:43 by acombe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		free_str(char *data)
{
	free(data);
}

void			free_split(char **content)
{
	int			index;

	if (!content || content == NULL)
		return ;
	index = 0;
	while (content[index])
	{
		free(content[index]);
		index++;
	}
	free(content);
}

void			free_process(t_process **content)
{
	t_process		*elem;
	t_process		*save;

	if (!content)
		return ;
	elem = *content;
	while (elem)
	{
		save = elem->next;
		free(elem);
		elem = save;
	}
}

void			free_arena(t_memory mem[MEM_SIZE])
{
	int i;

	i = -1;
	while (++i < MEM_SIZE)
	{
		free_str(mem[i].itoa_value);
		mem[i].pc_here = 0;
		mem[i].live_here = 0;
	}
}

void			free_mem(t_env *env)
{
	int i;

	i = -1;
	while (++i < MEM_SIZE)
		free_str(env->mem[i].itoa_value);
	i = -1;
	while (++i < MAX_ARGS_NUMBER)
		free_str(env->p[i].uname);
	i = -1;
	while (++i < 12)
		free_str(env->v[i].content);
}
