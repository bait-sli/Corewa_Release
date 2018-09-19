/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_render_verbose.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 23:53:31 by yarypert          #+#    #+#             */
/*   Updated: 2018/04/25 23:58:29 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	ft_shift(t_env *env, t_process *ec, char *format)
{
	int		i;
	char	*tmp;

	i = 0;
	while (++i < 12)
	{
		tmp = ft_strdup(env->v[i].content);
		free(env->v[i - 1].content);
		env->v[i - 1].content = ft_strdup(tmp);
		env->v[i - 1].color = env->v[i].color;
		free(tmp);
	}
	free(env->v[11].content);
	env->v[11].content = ft_strdup(format);
	free(format);
	env->v[11].color = ec->color;
	env->no_more_vrb = 1;
}

void		get_verbose(t_env *env, t_process *ec, char *format, int value)
{
	int		i;
	char	*tmp;
	char	*itoa;

	if (env->no_more_vrb == 1)
		return ;
	itoa = ft_itoa(value);
	tmp = ft_strjoin(format, itoa);
	free(itoa);
	i = -1;
	while (++i < 12)
	{
		if (env->v[i].booked == 0)
		{
			env->v[i].booked = 1;
			env->v[i].color = ec->color;
			env->v[i].content = ft_strjoin("~corewar_exec:   p   x | ", tmp);
			free(tmp);
			return ;
		}
	}
	ft_shift(env, ec, ft_strjoin("~corewar_exec:   p   x | ", tmp));
	free(tmp);
}
