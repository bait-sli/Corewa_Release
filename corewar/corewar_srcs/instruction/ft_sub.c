/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 01:49:41 by yarypert          #+#    #+#             */
/*   Updated: 2018/04/25 22:56:26 by atgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		sub(t_process *ec, t_env *env)
{
	char *pref;

	pref = "P   X | sub r";
	ec->reg[ec->par.p[2]] = ec->reg[ec->par.p[0]] - ec->reg[ec->par.p[1]];
	if (ec->reg[ec->par.p[0]] - ec->reg[ec->par.p[1]] == 0)
		ec->carry = 1;
	else if (ec->reg[ec->par.p[0]] - ec->reg[ec->par.p[1]] != 0)
		ec->carry = 0;
	if (env->vr.verbose == 1)
		ft_printf("%s%d r%d r%d\n",
				pref, ec->par.p[0], ec->par.p[1], ec->par.p[2]);
	ec->pc = (ec->pc + ec->par.fsize) % MEM_SIZE;
}

int				ft_sub(t_process *ec, t_env *env)
{
	uint8_t opcode;

	opcode = env->mem[ec->pc].octet;
	if (opcode != SUB_OP)
		return (0);
	ft_memset(&ec->par, 0, sizeof(t_param));
	ec->par.ok_ocp = 1;
	ocp_to_params(ec->par.ocp, env->mem[(ec->pc + 1) % MEM_SIZE].octet);
	if (ec->par.ocp[0] != REG_OP || ec->par.ocp[1] !=
			REG_OP || ec->par.ocp[2] != REG_OP)
		return (0);
	ft_get_params(ec, env);
	if (check_reg(&ec->par) == 0)
		return (0);
	ec->couldown += 10;
	ec->par.f = &sub;
	return (1);
}
