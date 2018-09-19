/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acombe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 22:54:34 by acombe            #+#    #+#             */
/*   Updated: 2018/04/26 03:40:15 by acombe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	init_render(t_env *env)
{
	int	x;
	int	y;

	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, FEN_X, FEN_Y, NAME);
	if (!(env->frame = mlx_xpm_file_to_image(env->mlx, PARSE_PATH, &x, &y)))
		ft_error(PATH_ERR, env);
	env->vr.pause = 1;
	parse_stuff(env);
}

static void	run_corewar(t_env *env)
{
	int	tmp;

	if (env->vr.render == 1)
	{
		init_render(env);
		ft_render(env);
	}
	else
	{
		while (env->vr.game_over == 0)
		{
			ft_gameplay(env);
			if (env->vr.game_over == 1)
			{
				tmp = env->vr.last_live_id;
				ft_printf("Contestant %d <%s>, has won !", tmp, env->winner);
				end_game(env);
			}
		}
	}
}

int			main(int ac, char **av)
{
	t_env	env;
	char	**args;
	int		x;

	x = -1;
	args = NULL;
	ft_memset(&env, 0, sizeof(t_env));
	ft_init_env(&env);
	if (ac < 2)
	{
		display_manual();
		ft_error(ARGS_ERR, &env);
	}
	if (!(args = (char**)malloc(sizeof(char *) * (ac + 1))))
		ft_error(MALLOC_ERR, &env);
	args[ac] = NULL;
	while (++x < ac)
		args[x] = ft_strdup(av[x]);
	check_args(args, ac, &env);
	ft_parsing(&env);
	run_corewar(&env);
	return (0);
}
