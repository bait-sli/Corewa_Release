/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_chp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acombe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 22:39:38 by acombe            #+#    #+#             */
/*   Updated: 2018/04/26 03:41:18 by acombe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int			ischp(char *arg)
{
	char	*sub;
	int		len;

	len = ft_strlen(arg);
	if (len < 4)
		return (0);
	sub = ft_strsub(arg, len - 4, len);
	if (ft_strcmp(sub, EXT) != 0)
	{
		free(sub);
		return (0);
	}
	free(sub);
	return (1);
}

static void	book_slot(char *arg, int value, t_env *env)
{
	env->p[value].path = ft_strdup(arg);
	env->p[value].nbr = (value + 1);
	env->p[value].booked = 1;
}

static void	default_chp_nbr(char **all, char *arg, t_env *env)
{
	int		i;

	i = -1;
	while (++i < MAX_ARGS_NUMBER)
	{
		if (env->p[i].booked == 0)
		{
			book_slot(arg, i, env);
			return ;
		}
	}
	ft_arg_error(TOO_MANY_ARG, all, env);
}

void		check_chp(char **arg, int len, t_env *env)
{
	int		i;
	int		v;

	i = 0;
	while (++i < len)
	{
		if (ft_strcmp(arg[i], NBR) == 0)
		{
			if (((i + 1) < len) && ((i + 2) < len) &&
					st_isdigit(arg[i + 1]) == 1)
			{
				v = ft_atoi(arg[i + 1]);
				if (v >= 0 && v <= 3 && arg[i + 2] && ischp(arg[i + 2]) == 1
						&& env->p[v].booked == 0)
					book_slot(arg[i + 2], v, env);
				else
					ft_arg_error(BAD_PLR_NB, arg, env);
			}
			else
				ft_arg_error(BAD_PLR_NB, arg, env);
		}
		if (((ischp(arg[i]) == 1) && ((i - 2) < 1)) || ((ischp(arg[i]) == 1)
					&& ((i - 2) > 0) && (ft_strcmp(arg[i - 2], NBR) != 0)))
			default_chp_nbr(arg, arg[i], env);
	}
}
