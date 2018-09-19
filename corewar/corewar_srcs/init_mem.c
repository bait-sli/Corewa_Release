/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acombe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 22:51:21 by acombe            #+#    #+#             */
/*   Updated: 2018/04/25 23:56:23 by acombe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	toggle_vm(t_memory mem[MEM_SIZE], t_player p)
{
	int		i;
	uint8_t	tmp;

	i = -1;
	while (++i < p.size)
	{
		tmp = p.content[i];
		mem[i + p.main_pc].octet = tmp;
		mem[i + p.main_pc].color = p.color;
	}
}

static int	chp_nbr(t_player p[MAX_ARGS_NUMBER])
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (++i < MAX_ARGS_NUMBER)
	{
		if (p[i].booked == 1)
			count += 1;
	}
	return (count);
}

static void	init_process(t_process **data, t_player p)
{
	t_process *one;

	if (!(one = (t_process *)malloc(sizeof(t_process) * 1)))
		return ;
	ft_memset(one, 0, sizeof(t_process));
	one->pc = p.main_pc;
	one->color = p.color;
	one->reg[1] = p.nbr;
	one->rip = 1;
	if (data)
	{
		if (one)
			one->next = *data;
		*data = one;
	}
	else
	{
		*data = one;
		one->next = NULL;
	}
}

static void	get_pos(t_player p[MAX_ARGS_NUMBER])
{
	int	diff;
	int	i;

	diff = 0;
	i = -1;
	while (++i < MAX_ARGS_NUMBER)
	{
		if (p[i].booked == 1)
		{
			p[i].main_pc = diff;
			diff += MEM_SIZE / chp_nbr(p);
		}
	}
}

void		init_mem(t_env *env)
{
	int	i;

	i = -1;
	get_pos(env->p);
	while (++i < MAX_ARGS_NUMBER)
	{
		if (env->p[i].booked == 1)
		{
			toggle_vm(env->mem, env->p[i]);
			init_process(&env->data, env->p[i]);
			env->processes += 1;
		}
	}
	ft_convert_mem(env->mem);
}
