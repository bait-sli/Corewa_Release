/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dump..c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acombe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 22:43:07 by acombe            #+#    #+#             */
/*   Updated: 2018/04/25 22:43:57 by acombe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	ft_putnbr_base(int nbr, int base)
{
	char *format;

	format = ft_itoa_base(nbr, base);
	ft_putstr("0x");
	if (ft_strlen(format) == 3)
		ft_putchar('0');
	if (ft_strlen(format) == 2)
		ft_putstr("00");
	if (ft_strlen(format) == 1)
		ft_putstr("000");
	ft_putstr(format);
	ft_putstr(": ");
	free(format);
}

void		end_game(t_env *env)
{
	free_mem(env);
	exit(EXIT_SUCCESS);
}

static void	dump_mem(t_memory mem[MEM_SIZE])
{
	int x;
	int y;

	x = -1;
	y = 0;
	while (y < MEM_SIZE)
	{
		x = -1;
		ft_putnbr_base(y, 16);
		while (++x < 64)
		{
			ft_putstr(mem[x + y].itoa_value);
			ft_putchar(' ');
		}
		ft_putchar('\n');
		y += 64;
	}
}

void		check_dump(t_env *env)
{
	if (env->vr.dump == 1)
	{
		if (env->cycle == env->vr.dump_cycle)
		{
			if (env->vr.render == 1)
			{
				env->vr.game_over = 1;
				dump_mem(env->mem);
			}
			else
			{
				dump_mem(env->mem);
				end_game(env);
			}
		}
	}
}
