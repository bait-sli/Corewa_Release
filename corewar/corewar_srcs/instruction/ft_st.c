/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 15:01:56 by yarypert          #+#    #+#             */
/*   Updated: 2018/04/25 23:04:05 by atgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	store_int(t_process *ec, t_memory mem[MEM_SIZE], int pos, int value)
{
	int				i;

	i = -1;
	while (++i < 4)
		mem[pos + i].color = ec->color;
	mem[pos + 0].octet = value >> 24 & 0xff;
	mem[pos + 1].octet = value >> 16 & 0xff;
	mem[pos + 2].octet = value >> 8 & 0xff;
	mem[pos + 3].octet = value & 0xff;
}

static void	st(t_process *ec, t_env *env)
{
	int				value;
	uint16_t		addr;

	value = ec->reg[ec->par.p[0]];
	if (ec->par.ocp[1] == REG_OP)
		ec->reg[ec->par.p[1]] = value;
	if (ec->par.ocp[1] == INDIR_OP)
	{
		addr = ft_get_addr(ec->pc, ec->par.p[1], IDX_MOD);
		store_int(ec, env->mem, addr, value);
	}
	if (ec->reg[ec->par.p[0]] == 0)
		ec->carry = 1;
	if (env->vr.verbose == 1)
		ft_printf("p   x | st r%d %d\n", ec->par.p[0], ec->par.p[1]);
	ec->pc = (ec->pc + ec->par.fsize) % MEM_SIZE;
}

int			ft_st(t_process *ec, t_env *env)
{
	uint8_t			opcode;

	opcode = env->mem[ec->pc].octet;
	if (opcode != ST_OP)
		return (0);
	ft_memset(&ec->par, 0, sizeof(t_param));
	ec->par.ok_ocp = 1;
	ocp_to_params(ec->par.ocp, env->mem[(ec->pc + 1) % MEM_SIZE].octet);
	if (ec->par.ocp[0] != REG_OP ||
			(ec->par.ocp[1] != INDIR_OP && ec->par.ocp[1] != REG_OP))
		return (0);
	ft_get_params(ec, env);
	if (check_reg(&ec->par) == 0)
		return (0);
	ec->couldown += 5;
	ec->par.f = &st;
	return (1);
}
