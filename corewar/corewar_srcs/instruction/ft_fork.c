/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atgerard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 22:42:39 by atgerard          #+#    #+#             */
/*   Updated: 2018/04/25 23:01:58 by atgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		exec_fork(t_process *ec, t_env *env)
{
	int child_pc;

	env->processes += 1;
	env->mem[ec->pc].color = ec->color;
	child_pc = ft_get_addr(ec->pc, ec->par.p[0], IDX_MOD);
	ec->pc = (ec->pc + 3) % MEM_SIZE;
	ft_add_process(&env->data, ec, child_pc);
	if (env->vr.verbose == 1)
		ft_printf("p   x | fork %d (%d)\n", ec->par.p[0], child_pc);
	if (env->vr.render == 1)
		get_verbose(env, ec, "fork ", ec->par.p[0]);
}

int				ft_fork(t_process *ec, t_env *env)
{
	uint8_t opcode;
	uint8_t buff[2];

	opcode = env->mem[ec->pc].octet;
	if (opcode != FORK_OP)
		return (0);
	ft_memset(&ec->par, 0, sizeof(t_param));
	ec->par.dir = 2;
	get_buff(buff, env->mem, (ec->pc + 1) % MEM_SIZE, 2);
	ec->par.p[0] = get_uint16(buff);
	ec->couldown = 800;
	ec->par.f = &exec_fork;
	return (1);
}
