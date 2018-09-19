/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acombe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 22:52:56 by acombe            #+#    #+#             */
/*   Updated: 2018/04/25 23:58:02 by acombe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_destroy(t_process **all, int pos)
{
	int			x;
	t_process	*befor;
	t_process	*after;
	t_process	*elem;

	if (!all || all == NULL)
		return ;
	elem = *all;
	if (pos == 0)
	{
		*all = elem->next;
		free(elem);
		return ;
	}
	x = -1;
	while (++x < pos - 1)
		elem = elem->next;
	befor = elem;
	elem = elem->next;
	if (elem != NULL)
		after = elem->next;
	else
		after = NULL;
	free(elem);
	befor->next = after;
}
