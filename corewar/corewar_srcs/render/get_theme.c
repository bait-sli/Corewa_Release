/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_theme.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 23:53:35 by yarypert          #+#    #+#             */
/*   Updated: 2018/04/25 23:59:23 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int	max_int(int tab[4])
{
	int ret;
	int max;
	int i;

	max = 0;
	i = -1;
	while (++i < 4)
	{
		if (tab[i] > max)
		{
			max = tab[i];
			ret = i;
		}
	}
	if (max == 0)
		return (-5);
	return (ret);
}

void		parse_stuff(t_env *env)
{
	int x;
	int y;

	if (!(env->stuff[0] = mlx_xpm_file_to_image(env->mlx, AR_1, &x, &y)))
		ft_error(PATH_ERR, env);
	if (!(env->stuff[1] = mlx_xpm_file_to_image(env->mlx, AR_2, &x, &y)))
		ft_error(PATH_ERR, env);
	if (!(env->stuff[2] = mlx_xpm_file_to_image(env->mlx, AR_3, &x, &y)))
		ft_error(PATH_ERR, env);
	if (!(env->stuff[3] = mlx_xpm_file_to_image(env->mlx, AR_4, &x, &y)))
		ft_error(PATH_ERR, env);
}

void		get_theme(t_env *env)
{
	int tab[4];
	int i;

	i = 0;
	while (++i < 4)
		tab[i] = env->p[i].total_lives;
	if (max_int(tab) == -5)
		return ;
	env->frame = env->stuff[max_int(tab)];
}
