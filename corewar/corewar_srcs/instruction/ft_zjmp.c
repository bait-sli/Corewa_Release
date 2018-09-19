/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 03:29:52 by yarypert          #+#    #+#             */
/*   Updated: 2018/04/25 23:04:38 by atgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		zjmp(t_process *ec, t_env *env)
{
	if (ec->carry == 1)
	{
		ec->pc = ft_get_addr(ec->pc, ec->par.p[0], MEM_SIZE);
		if (env->vr.verbose == 1)
			ft_printf("p   x | zjmp %d OK\n", ec->par.p[0]);
	}
	else
	{
		ec->pc = (ec->pc + 3) % MEM_SIZE;
		if (env->vr.verbose == 1)
			ft_printf("p   x | zjmp %d FAILED\n", ec->pc);
	}
}

int				ft_zjmp(t_process *ec, t_env *env)
{
	uint8_t opcode;
	uint8_t buff[2];

	opcode = env->mem[ec->pc].octet;
	if (opcode != ZJMP_OP)
		return (0);
	ft_memset(&ec->par, 0, sizeof(t_param));
	ec->par.dir = 2;
	get_buff(buff, env->mem, (ec->pc + 1) % MEM_SIZE, 2);
	ec->par.p[0] = get_uint16(buff);
	ec->couldown = 20;
	ec->par.f = &zjmp;
	return (1);
}
