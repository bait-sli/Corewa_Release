/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decode_ocp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atgerard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 22:36:56 by atgerard          #+#    #+#             */
/*   Updated: 2018/04/25 22:38:34 by atgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		get_integer(uint8_t t[4])
{
	int		ret;
	int		i;

	ret = 0;
	i = -1;
	while (++i < 4)
		ret = ret * 16 * 16 + t[i];
	return (ret);
}

int		get_uint16(uint8_t t[2])
{
	int		ret;
	short	tmp;

	tmp = 0;
	ret = 0;
	tmp = t[0] << 8;
	tmp += t[1];
	ret = tmp;
	return (ret);
}

int		check_reg(t_param *pls)
{
	int		i;

	i = -1;
	while (++i < 3)
	{
		if (pls->ocp[i] == REG_OP)
		{
			if (pls->p[i] < 1 || pls->p[i] > 16)
				return (0);
		}
	}
	return (1);
}

void	ocp_to_params(uint8_t *ret, uint8_t nb)
{
	int		i;

	i = -1;
	while (++i < 3)
	{
		ret[i] = nb << (i * 2);
		ret[i] >>= 6;
	}
}

void	get_buff(uint8_t *t, t_memory mem[MEM_SIZE], uint16_t start, int size)
{
	int		i;

	i = -1;
	while (++i < size)
		t[i] = mem[(start + i) % MEM_SIZE].octet;
}
