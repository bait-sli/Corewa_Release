/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_instruction.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bait-sli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 07:18:58 by bait-sli          #+#    #+#             */
/*   Updated: 2018/03/24 20:37:46 by bait-sli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		get_func_tab(int (*tab[19])(char*, t_env*))
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

int				ft_check_instruction(char *line, t_env *env)
{
	int			(*tab[19])(char*, t_env*);
	int			i;

	i = -1;
	get_func_tab(tab);
	env->error_code = INV_INSTRU;
	while (++i < 19)
	{
		if (tab[i](line, env) == 1)
			return (1);
	}
	return (0);
}
