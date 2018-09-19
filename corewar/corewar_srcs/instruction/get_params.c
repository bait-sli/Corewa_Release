/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atgerard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 22:58:56 by atgerard          #+#    #+#             */
/*   Updated: 2018/04/25 23:00:10 by atgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int					ft_endian(int x)
{
	int				ret;

	ret = x;
	ret = ((ret >> 24) & 0xff) | ((ret << 8) & 0xff0000) |
		((ret >> 8) & 0xff00) | ((ret << 24) & 0xff000000);
	return (ret);
}

static void			get_exec_size(t_param *par)
{
	int				i;

	i = -1;
	par->fsize += 1;
	if (par->ok_ocp == 1)
		par->fsize += 1;
	while (++i < 3)
	{
		if (par->ocp[i] == REG_OP)
			par->fsize += 1;
		if (par->ocp[i] == DIR_OP)
			par->fsize += par->dir;
		if (par->ocp[i] == INDIR_OP)
			par->fsize += 2;
	}
}

static int			get_direct(t_process *ec, t_env *env, int i, int pc)
{
	uint8_t			buff4[4];

	get_buff(buff4, env->mem, pc, 4);
	ec->par.p[i] = get_integer(buff4);
	pc = (pc + 4) % MEM_SIZE;
	return (pc);
}

void				ft_get_params(t_process *ec, t_env *env)
{
	int				pc;
	int				i;
	uint8_t			buff2[2];

	i = -1;
	pc = (ec->pc + 1 + ec->par.ok_ocp) % MEM_SIZE;
	while (++i < 3)
	{
		if (ec->par.ocp[i] == REG_OP)
		{
			ec->par.p[i] = env->mem[pc].octet;
			pc = (pc + 1) % MEM_SIZE;
		}
		if (ec->par.ocp[i] == DIR_OP && ec->par.dir == 4)
			pc = get_direct(ec, env, i, pc);
		if (ec->par.ocp[i] == INDIR_OP ||
				(ec->par.ocp[i] == DIR_OP && ec->par.dir == 2))
		{
			get_buff(buff2, env->mem, pc, 2);
			ec->par.p[i] = get_uint16(buff2);
			pc = (pc + 2) % MEM_SIZE;
		}
	}
	get_exec_size(&ec->par);
}
