/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 03:51:36 by yarypert          #+#    #+#             */
/*   Updated: 2018/04/25 23:02:57 by atgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		identify_last_live(t_env *env, int x)
{
	int			i;

	i = -1;
	while (++i < MAX_ARGS_NUMBER)
	{
		if (x == env->p[i].nbr && env->p[i].booked == 1)
		{
			env->p[i].total_lives += 1;
			env->vr.last_live_id = env->p[i].nbr;
			env->winner = env->p[i].uname;
			env->vr.win_clr = env->p[i].color;
			if (env->vr.verbose == 1)
				ft_printf("P(%d) %s is alive!\n", env->p[i].nbr, env->winner);
		}
	}
}

static void		live(t_process *ec, t_env *env)
{
	int			i;

	i = ec->pc;
	env->nbr_live += 1;
	env->vr.lives_prd += 1;
	env->mem[ec->pc].live_here = 1;
	ec->pc = (ec->pc + 5) % MEM_SIZE;
	identify_last_live(env, ec->par.p[0]);
	ec->rip = 0;
	while (i <= ec->pc)
	{
		env->mem[i].color = ec->color;
		env->mem[i].live_here = 1;
		i++;
	}
	if (env->vr.render == 1)
		get_verbose(env, ec, "live ", ec->par.p[0]);
}

int				ft_live(t_process *ec, t_env *env)
{
	uint8_t		opcode;
	uint8_t		buff[4];

	opcode = env->mem[ec->pc].octet;
	if (opcode != LIVE_OP)
		return (0);
	ft_memset(&ec->par, 0, sizeof(t_param));
	ec->par.dir = 4;
	get_buff(buff, env->mem, (ec->pc + 1) % MEM_SIZE, 4);
	ec->par.p[0] = get_integer(buff);
	ec->couldown = 10;
	ec->par.f = &live;
	return (1);
}
