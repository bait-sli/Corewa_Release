/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acombe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 22:57:57 by acombe            #+#    #+#             */
/*   Updated: 2018/04/26 03:40:55 by acombe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	display_manual(void)
{
	ft_printf("Usage: ./corewar [-dump N -n N -verbose...] <chp.cor> <...>\n");
	ft_printf("         -dump N : Dumps memory after N cycles then exits.\n");
	ft_printf("         -verbose: Display execution log and cycles.\n");
	ft_printf("         -n N: Fix next champion number (N).\n");
	ft_printf("         -render: Display graphic render.\n");
	ft_printf("Render Usage:\n");
	ft_printf("         ESC: Exit render after game end.\n");
	ft_printf("         SPACE: Run game.\n");
	ft_printf("         P: Pause game.\n");
}

void	ft_intro(t_env *env)
{
	int	i;

	i = -1;
	ft_printf("Introducing contestants for gameplay...\n");
	while (++i < MAX_ARGS_NUMBER)
	{
		if (env->p[i].booked == 1)
			ft_printf("* Player %d, weighing %d octet, <%s> <%s> !\n",
					env->p[i].nbr, env->p[i].size,
					env->p[i].name, env->p[i].comment);
	}
}
