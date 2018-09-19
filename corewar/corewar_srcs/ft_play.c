/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_play.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acombe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 22:46:54 by acombe            #+#    #+#             */
/*   Updated: 2018/04/25 23:55:37 by acombe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	kill_proc(t_env *env, t_process **data)
{
	t_process	*elem;
	t_process	*tmp;
	int			pos;

	pos = 0;
	if (!data || data == NULL)
		return ;
	elem = *data;
	while (elem != NULL)
	{
		if (elem->rip == 1)
		{
			tmp = elem->next;
			ft_destroy(data, pos);
			env->processes -= 1;
			pos -= 1;
			elem = tmp;
		}
		else
			elem = elem->next;
		pos += 1;
	}
}

static void	reset_rip(t_process **data)
{
	t_process *elem;

	elem = *data;
	while (elem != NULL)
	{
		elem->rip = 1;
		elem = elem->next;
	}
}

static void	ft_check_periode(t_env *env)
{
	if (env->vr.died_cld == env->cycle_to_die)
	{
		env->vr.died_cld = 0;
		if (env->vr.lives_prd >= NBR_LIVE || env->vr.nbr_check == MAX_CHECKS)
		{
			env->cycle_to_die -= env->cycle_delta;
			if (env->cycle_to_die < 0)
				env->cycle_to_die = 1;
			env->vr.lives_prd = 0;
			env->vr.nbr_check = 0;
		}
		else
		{
			env->vr.nbr_check += 1;
			env->vr.lives_prd = 0;
		}
		kill_proc(env, &env->data);
		reset_rip(&env->data);
		get_theme(env);
		if (env->vr.verbose == 1)
			ft_printf("Cycle to die is now %d\n", env->cycle_to_die);
	}
}

static void	ft_play_cycle(t_env *env, t_process **data)
{
	t_process *elem;

	elem = *data;
	while (elem != NULL)
	{
		if (elem->couldown == 0 && elem->play == 0)
			ft_try_op(elem, env);
		if (elem->couldown == 1 && elem->play == 1)
		{
			elem->play = 0;
			elem->par.f(elem, env);
		}
		if (elem->couldown > 0)
			elem->couldown -= 1;
		env->mem[elem->pc].pc_here = 1;
		elem = elem->next;
	}
	env->cycle += 1;
	env->vr.died_cld += 1;
}

void		ft_gameplay(t_env *env)
{
	if (env->vr.verbose == 1)
		ft_printf("It is now cycle  %d\n", env->cycle);
	env->no_more_vrb = 0;
	if (!env->data || env->data == NULL)
	{
		env->vr.game_over = 1;
		return ;
	}
	free_arena(env->mem);
	ft_play_cycle(env, &env->data);
	ft_convert_mem(env->mem);
	ft_check_periode(env);
	check_dump(env);
}
