/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acombe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 22:48:56 by acombe            #+#    #+#             */
/*   Updated: 2018/04/26 03:43:39 by acombe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int	get_render_clr(int i)
{
	if (i == 0)
		return (CLR_P1);
	if (i == 1)
		return (CLR_P2);
	if (i == 2)
		return (CLR_P3);
	if (i == 3)
		return (CLR_P4);
	return (0);
}

void		ft_init_env(t_env *env)
{
	int i;

	i = -1;
	env->cycle_to_die = CYCLE_TO_DIE;
	env->cycle_delta = CYCLE_DELTA;
	env->data = NULL;
	env->frame = NULL;
	while (++i < 4)
		env->stuff[i] = NULL;
	i = -1;
	while (++i < MAX_ARGS_NUMBER)
	{
		env->p[i].path = NULL;
		env->p[i].uname = NULL;
		env->p[i].color = get_render_clr(i);
	}
	i = -1;
	while (++i < MEM_SIZE)
		env->mem[i].color = NEUTRAL_CLR;
	i = -1;
	while (++i < 12)
		env->v[i].content = NULL;
}
