/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 15:09:39 by yarypert          #+#    #+#             */
/*   Updated: 2018/04/25 22:40:16 by atgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void			aff(t_process *ec, t_env *env)
{
	unsigned char	aff;

	aff = ec->reg[ec->par.p[0]] % 255;
	if (env->vr.verbose == 1)
	{
		ft_putstr("Aff: ");
		ft_putchar(aff);
		ft_putchar('\n');
	}
	ec->pc = (ec->pc + 3) % MEM_SIZE;
}

int					ft_aff(t_process *ec, t_env *env)
{
	uint8_t			opcode;
	int				reg;

	opcode = env->mem[ec->pc].octet;
	if (opcode != AFF_OP)
		return (0);
	ft_memset(&ec->par, 0, sizeof(t_param));
	ocp_to_params(ec->par.ocp, env->mem[(ec->pc + 1) % MEM_SIZE].octet);
	ec->par.ok_ocp = 1;
	if (ec->par.ocp[0] != REG_CODE)
		return (0);
	reg = env->mem[(ec->pc + 2) % MEM_SIZE].octet;
	if (reg < 1 || reg > 16)
		return (0);
	ec->par.p[0] = reg;
	ec->couldown = 2;
	ec->par.f = &aff;
	return (1);
}
