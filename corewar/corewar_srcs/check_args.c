/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acombe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 22:37:40 by acombe            #+#    #+#             */
/*   Updated: 2018/04/25 23:55:04 by acombe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	check_dmp(char **arg, int len, t_env *env)
{
	int i;

	i = 0;
	while (++i < len)
	{
		if (ft_strcmp(arg[i], DMP) == 0)
		{
			if (env->vr.dump == 1)
				ft_arg_error(DOUBLE_ARG, arg, env);
			else
			{
				if (i + 1 >= len || st_isdigit(arg[i + 1]) != 1)
					ft_arg_error(BAD_DMP_FORMAT, arg, env);
				else
				{
					env->vr.dump_cycle = ft_atoi(arg[i + 1]);
					env->vr.dump = 1;
				}
			}
		}
	}
}

static void	check_options(char **arg, int len, t_env *env)
{
	int i;

	i = 0;
	while (++i < len)
	{
		if (ft_strcmp(arg[i], RENDER) == 0)
		{
			if (env->vr.render == 0)
				env->vr.render = 1;
			else
				ft_arg_error(DOUBLE_ARG, arg, env);
		}
		if (ft_strcmp(arg[i], VRBS) == 0)
		{
			if (env->vr.verbose == 0)
				env->vr.verbose = 1;
			else
				ft_arg_error(DOUBLE_ARG, arg, env);
		}
	}
}

static int	arg_validity(char **a, int len)
{
	int i;

	i = 0;
	while (++i < len)
	{
		if (st_isdigit(a[i]) == 1)
		{
			if (((i - 1) < 1) || ((ft_strcmp(a[i - 1], NBR) != 0
							&& ft_strcmp(a[i - 1], DMP) != 0)))
				return (0);
		}
		if (ischp(a[i]) == 0 && ft_strcmp(a[i], VRBS) != 0 &&
				ft_strcmp(a[i], RENDER) != 0 && ft_strcmp(a[i], NBR) != 0
				&& ft_strcmp(a[i], DMP) != 0 && st_isdigit(a[i]) == 0)
			return (0);
	}
	return (1);
}

void		check_args(char **arg, int len, t_env *env)
{
	if (arg_validity(arg, len) == 0)
		ft_arg_error(PARSE_ERR, arg, env);
	check_options(arg, len, env);
	check_dmp(arg, len, env);
	check_chp(arg, len, env);
}
