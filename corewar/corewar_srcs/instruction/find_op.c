/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acombe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 16:37:40 by acombe            #+#    #+#             */
/*   Updated: 2018/04/17 16:37:47 by acombe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		get_func_tab(int (*tab[19])(t_process*, t_env*))
{
	if (!tab)
		return ;
	tab[0] = ft_live;
	tab[1] = ft_ld;
	tab[2] = ft_st;
	tab[3] = ft_add;
	tab[4] = ft_sub;
	tab[5] = ft_and;
	tab[6] = ft_or;
	tab[7] = ft_xor;
	tab[8] = ft_zjmp;
	tab[9] = ft_ldi;
	tab[10] = ft_sti;
	tab[11] = ft_fork;
	tab[12] = ft_lld;
	tab[13] = ft_lldi;
	tab[14] = ft_lfork;
	tab[15] = ft_aff;
	tab[16] = ft_mul;
	tab[17] = ft_div;
	tab[18] = ft_mod;
}

void			ft_try_op(t_process *current, t_env *env)
{
	int			(*tab[19])(t_process*, t_env*);
	int			i;

	i = -1;
	get_func_tab(tab);
	while (++i < 19)
	{
		if (tab[i](current, env) == 1)
		{
			current->play = 1;
			return ;
		}
	}
	current->pc = (current->pc + 1) % MEM_SIZE;
}
