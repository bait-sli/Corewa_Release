/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label_to_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bait-sli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 22:01:49 by bait-sli          #+#    #+#             */
/*   Updated: 2018/03/24 22:05:05 by bait-sli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void			ft_from_up(t_env *env, t_parse **buff)
{
	t_parse			*elem;
	int				check_sum;
	int				i;

	i = -1;
	check_sum = 0;
	elem = *buff;
	while (++i < env->verif.lab_pos)
		elem = elem->next;
	while (i < env->verif.line_pos)
	{
		env->verif.check_sum -= elem->content_size;
		elem = elem->next;
		i++;
	}
}

static void			ft_from_down(t_env *env, t_parse **buff)
{
	t_parse			*elem;
	int				i;

	i = -1;
	elem = *buff;
	while (++i < env->verif.line_pos)
		elem = elem->next;
	while (i < env->verif.lab_pos)
	{
		env->verif.check_sum += elem->content_size;
		elem = elem->next;
		i++;
	}
}

void				ft_label_to_int(t_env *env)
{
	if (env->verif.line_pos >= env->verif.lab_pos)
		ft_from_up(env, &env->buff);
	if (env->verif.line_pos < env->verif.lab_pos)
		ft_from_down(env, &env->buff);
	replace_ref(env, &env->buff);
}
