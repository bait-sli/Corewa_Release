/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lld.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acombe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 16:12:04 by acombe            #+#    #+#             */
/*   Updated: 2018/04/25 23:03:12 by atgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void			lld(t_process *ec, t_env *env)
{
	uint8_t		b[4];
	int			addr;

	if (ec->par.ocp[0] == DIR_OP)
		ec->reg[ec->par.p[1]] = ec->par.p[0];
	if (ec->par.ocp[0] == INDIR_OP)
	{
		addr = ft_get_addr(ec->pc, ec->par.p[0], MEM_SIZE);
		get_buff(b, env->mem, addr, 4);
		ec->reg[ec->par.p[1]] = get_integer(b);
	}
	if (ec->reg[ec->par.p[1]] == 0)
		ec->carry = 1;
	if (ec->reg[ec->par.p[1]] != 0)
		ec->carry = 0;
	if (env->vr.verbose == 1)
		ft_printf("p   x | lld %d r%d\n", ec->reg[ec->par.p[1]], ec->par.p[1]);
	ec->pc = (ec->pc + ec->par.fsize) % MEM_SIZE;
}

int					ft_lld(t_process *ec, t_env *env)
{
	uint8_t		opcode;

	opcode = env->mem[ec->pc].octet;
	if (opcode != LLD_OP)
		return (0);
	ft_memset(&ec->par, 0, sizeof(t_param));
	ec->par.ok_ocp = 1;
	ec->par.dir = 4;
	ocp_to_params(ec->par.ocp, env->mem[(ec->pc + 1) % MEM_SIZE].octet);
	if ((ec->par.ocp[0] != INDIR_OP && ec->par.ocp[0] != DIR_OP) ||
			(ec->par.ocp[1] != REG_OP))
		return (0);
	ft_get_params(ec, env);
	if (check_reg(&ec->par) == 0)
		return (0);
	ec->couldown += 10;
	ec->par.f = &lld;
	return (1);
}
