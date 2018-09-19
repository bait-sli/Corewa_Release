/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_arena.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 23:53:40 by yarypert          #+#    #+#             */
/*   Updated: 2018/04/26 00:01:25 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_dsp	init_metric(void)
{
	t_dsp ret;

	ret.lat = 20;
	ret.lon = 25;
	ret.ter = 0;
	ret.ter2 = -1;
	ret.c = 0;
	return (ret);
}

void	render_arena(void *mlx, void *win, t_memory mem[MEM_SIZE])
{
	t_dsp m;

	m = init_metric();
	while (++m.ter2 < 64)
	{
		m.lon = 25;
		m.ter = 0;
		while (m.ter < 64)
		{
			if (mem[m.c].pc_here == 0 && mem[m.c].live_here == 0)
				mlx_string_put(mlx, win, m.lon, m.lat, mem[m.c].color,
						mem[m.c].itoa_value);
			if (mem[m.c].live_here == 1)
				mlx_string_put(mlx, win, m.lon, m.lat, LIVE_CLR,
						mem[m.c].itoa_value);
			if (mem[m.c].pc_here == 1 && mem[m.c].live_here == 0)
				mlx_string_put(mlx, win, m.lon, m.lat, PROCESS_CLR,
						mem[m.c].itoa_value);
			m.lon += 20;
			m.ter++;
			m.c++;
		}
		m.lat += 18;
	}
}
