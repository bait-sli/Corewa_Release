/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_and.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atgerard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 14:44:35 by atgerard          #+#    #+#             */
/*   Updated: 2018/04/25 23:01:14 by atgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void			and(t_process *ec, t_env *env)
{
	int			t[2];
	uint8_t		b[4];
	int			i;
	uint16_t	addr;

	i = -1;
	while (++i < 2)
	{
		if (ec->par.ocp[i] == REG_OP)
			t[i] = ec->reg[ec->par.p[i]];
		if (ec->par.ocp[i] == DIR_OP)
			t[i] = ec->par.p[i];
		if (ec->par.ocp[i] == INDIR_OP)
		{
			addr = ft_get_addr(ec->pc, ec->par.p[i], IDX_MOD);
			get_buff(b, env->mem, addr, 4);
			t[i] = get_integer(b);
		}
	}
	if (env->vr.verbose == 1)
		ft_printf("P   X | and %d %d r%d\n", t[0], t[1], ec->par.p[2]);
	ec->reg[ec->par.p[2]] = t[0] & t[1];
	ec->carry = ((t[0] & t[1]) == 0 ? 1 : 0);
	ec->pc = (ec->pc + ec->par.fsize) % MEM_SIZE;
}

int					ft_and(t_process *ec, t_env *env)
{
	uint8_t		opcode;

	opcode = env->mem[ec->pc].octet;
	if (opcode != AND_OP)
		return (0);
	ft_memset(&ec->par, 0, sizeof(t_param));
	ec->par.ok_ocp = 1;
	ec->par.dir = 4;
	ocp_to_params(ec->par.ocp, env->mem[(ec->pc + 1) % MEM_SIZE].octet);
	if (((ec->par.ocp[0] != REG_OP) && (ec->par.ocp[0] != DIR_OP) &&
				(ec->par.ocp[0] != INDIR_OP)) || ((ec->par.ocp[1] != REG_OP) &&
					(ec->par.ocp[1] != DIR_OP) &&
					(ec->par.ocp[1] != INDIR_OP)) ||
			(ec->par.ocp[2] != REG_OP))
		return (0);
	ft_get_params(ec, env);
	if (check_reg(&ec->par) == 0)
		return (0);
	ec->couldown += 6;
	ec->par.f = &and;
	return (1);
}
