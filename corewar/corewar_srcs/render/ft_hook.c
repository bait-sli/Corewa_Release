/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 23:52:53 by yarypert          #+#    #+#             */
/*   Updated: 2018/04/25 23:55:17 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		ft_redraw(t_env *env)
{
	if (env->vr.pause == 0)
	{
		ft_gameplay(env);
		ft_display(env);
	}
	if (env->vr.pause == 1)
		ft_display(env);
	return (1);
}

int		ft_keyhook(int key, t_env *env)
{
	if (key == SUSPEND)
		env->vr.pause = 1;
	if (key == RUN)
		env->vr.pause = 0;
	if (key == ECS && env->vr.game_over == 1)
	{
		free_mem(env);
		exit(0);
	}
	return (1);
}
