/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_label.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bait-sli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 22:16:44 by bait-sli          #+#    #+#             */
/*   Updated: 2018/03/24 22:19:20 by bait-sli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void			ft_replace_label(t_env *env, char **params)
{
	int				i;
	char			*itoa;

	i = env->verif.ref_pos;
	if (isindir(params[i]) == 1)
	{
		free(params[i]);
		params[i] = ft_itoa(env->verif.check_sum);
	}
	else
	{
		free(params[i]);
		itoa = ft_itoa(env->verif.check_sum);
		params[i] = ft_strjoin("%", itoa);
		free(itoa);
	}
	env->verif.ref_pos = 0;
	env->verif.line_pos = 0;
	env->verif.lab_pos = 0;
	env->verif.check_sum = 0;
}

void				replace_ref(t_env *env, t_parse **buff)
{
	t_parse			*elem;
	int				i;

	i = -1;
	elem = *buff;
	while (++i < env->verif.line_pos)
		elem = elem->next;
	ft_replace_label(env, elem->params);
}
