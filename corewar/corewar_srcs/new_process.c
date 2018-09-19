/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acombe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 22:59:19 by acombe            #+#    #+#             */
/*   Updated: 2018/04/26 03:40:01 by acombe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	ft_put_data(t_process *dest, t_process *dad, int pc)
{
	int	i;

	i = -1;
	while (++i < REG_NUMBER + 1)
		dest->reg[i] = dad->reg[i];
	dest->par = dad->par;
	dest->rip = dad->rip;
	dest->pc = pc;
	dest->carry = dad->carry;
	dest->couldown = 0;
	dest->play = 0;
	dest->color = dad->color;
	dest->next = NULL;
}

void		ft_add_process(t_process **all, t_process *dad, int pc)
{
	t_process	*add;

	if (!(add = (t_process*)malloc(sizeof(t_process) * 1)))
		return ;
	ft_memset(add, 0, sizeof(t_process));
	ft_put_data(add, dad, pc);
	if (all)
	{
		if (add)
			add->next = *all;
		*all = add;
	}
	else
	{
		*all = add;
		add->next = NULL;
	}
}
