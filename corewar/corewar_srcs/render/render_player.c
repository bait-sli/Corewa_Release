/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 23:53:45 by yarypert          #+#    #+#             */
/*   Updated: 2018/04/26 00:02:34 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	ft_plr_stat(t_env *env, int sum, int cord_y, int clr)
{
	int		i;
	int		all;
	char	*buff;
	double	percent;
	size_t	size;

	all = 0;
	i = -1;
	if (sum == 0)
		return ;
	while (++i < MAX_ARGS_NUMBER)
		all += env->p[i].total_lives;
	percent = (sum * 100) / all;
	size = (percent * 43) / 100;
	if (size == 0 || !(buff = (char*)malloc(sizeof(char) * (size + 1))))
		return ;
	ft_memset(buff, '>', size);
	buff[size] = '\0';
	mlx_string_put(env->mlx, env->win, PLR_CORD_X, cord_y, clr, buff);
	free(buff);
}

void		render_players(void *mlx, void *win, t_player p[4], t_env *env)
{
	int		i;
	int		lat;

	i = -1;
	lat = PLR_CORD_Y;
	while (++i < 4)
	{
		if (p[i].booked == 1)
		{
			mlx_string_put(mlx, win, PLR_CORD_X, lat, p[i].color, p[i].uname);
			ft_plr_stat(env, p[i].total_lives, lat + PLR_SCALE, p[i].color);
			display_free(p[i].total_lives, PLR_CORD_X, lat + (PLR_SCALE * 2),
					env);
		}
		lat += PLR_DIS;
	}
}
