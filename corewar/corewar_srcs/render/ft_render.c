/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 23:53:26 by yarypert          #+#    #+#             */
/*   Updated: 2018/04/25 23:57:34 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		display_free(int format, int x, int y, t_env *env)
{
	char *ret;

	ret = ft_itoa(format);
	mlx_string_put(env->mlx, env->win, x, y, NEUTRAL_CLR, ret);
	free(ret);
}

static void	ft_op(t_env *env)
{
	int i;
	int scale;

	i = -1;
	scale = 800;
	while (++i < 12)
	{
		if (env->v[i].content && env->v[i].content != NULL)
		{
			mlx_string_put(env->mlx, env->win, VISU_POS_X - 300,
					VISU_POS_Y + scale, env->v[i].color, env->v[i].content);
			scale += 15;
		}
	}
}

static void	ft_info(t_env *env)
{
	mlx_put_image_to_window(env->mlx, env->win, env->frame, 0, 0);
	render_arena(env->mlx, env->win, env->mem);
	display_free(env->cycle_to_die, VISU_POS_X, VISU_POS_Y, env);
	display_free(env->vr.died_cld - env->cycle_to_die, VISU_POS_X + 100,
			VISU_POS_Y, env);
	display_free(env->cycle_delta, VISU_POS_X, VISU_POS_Y + 55, env);
	display_free(env->nbr_live, VISU_POS_X, VISU_POS_Y + 115, env);
	display_free(env->processes, VISU_POS_X, VISU_POS_Y + 175, env);
	display_free(env->cycle, VISU_POS_X, VISU_POS_Y + 235, env);
	render_players(env->mlx, env->win, env->p, env);
}

void		ft_display(t_env *env)
{
	mlx_clear_window(env->mlx, env->win);
	ft_info(env);
	if (env->vr.pause == 1 && env->vr.game_over == 0)
		mlx_string_put(env->mlx, env->win, VISU_POS_X - 200, VISU_POS_Y - 55,
				LIVE_CLR, PAUSE);
	if (env->vr.game_over == 1)
	{
		mlx_string_put(env->mlx, env->win, VISU_POS_X - 200, VISU_POS_Y - 55,
				NEUTRAL_CLR, WINNER);
		if (env->winner != NULL)
			mlx_string_put(env->mlx, env->win, VISU_POS_X, VISU_POS_Y - 55,
					env->vr.win_clr, env->winner);
		if (env->winner == NULL || !env->winner)
			mlx_string_put(env->mlx, env->win, VISU_POS_X, VISU_POS_Y - 55,
					LIVE_CLR, UNDEF);
	}
	ft_op(env);
}

void		ft_render(t_env *env)
{
	ft_display(env);
	mlx_hook(env->win, 2, 3, ft_keyhook, env);
	mlx_loop_hook(env->mlx, ft_redraw, env);
	mlx_loop(env->mlx);
}
