/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 15:26:51 by yarypert          #+#    #+#             */
/*   Updated: 2018/04/25 23:35:55 by atgerard         ###   ########.fr       */
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

static void	print(t_process *ec, int *t, uint16_t addr)
{
	ft_printf("p   x | sti r%d %d %d\n", ec->par.p[0], t[1], t[2]);
	ft_printf("      | -> store to %d + %d = %d (with pc and mod %d)\n",
			t[1], t[2], t[1] + t[2], addr);
}

static void	sti(t_process *ec, t_env *env)
{
	int				t[3];
	uint8_t			b[4];
	int				i;
	uint16_t		addr;

	i = -1;
	while (++i < 3)
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
	addr = ft_get_addr(ec->pc, t[1] + t[2], IDX_MOD);
	store_int(ec, env->mem, addr, t[0]);
	if (env->vr.verbose == 1)
		print(ec, t, addr);
	ec->carry = 1;
	ec->pc = (ec->pc + ec->par.fsize) % MEM_SIZE;
}

int			ft_sti(t_process *ec, t_env *env)
{
	uint8_t			opcode;

	opcode = env->mem[ec->pc].octet;
	if (opcode != STI_OP)
		return (0);
	ft_memset(&ec->par, 0, sizeof(t_param));
	ec->par.ok_ocp = 1;
	ec->par.dir = 2;
	ocp_to_params(ec->par.ocp, env->mem[(ec->pc + 1) % MEM_SIZE].octet);
	if (ec->par.ocp[0] != REG_OP || (ec->par.ocp[1] != REG_OP &&
				ec->par.ocp[1] != DIR_OP && ec->par.ocp[1] != INDIR_OP)
			|| (ec->par.ocp[2] != DIR_OP && ec->par.ocp[2] != REG_OP))
		return (0);
	ft_get_params(ec, env);
	if (check_reg(&ec->par) == 0)
		return (0);
	ec->couldown += 25;
	ec->par.f = &sti;
	return (1);
}
