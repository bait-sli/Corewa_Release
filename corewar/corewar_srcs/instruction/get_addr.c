/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_addr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atgerard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 22:58:13 by atgerard          #+#    #+#             */
/*   Updated: 2018/04/25 22:58:48 by atgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int			exec_modulo(int a, int b)
{
	if (a % b >= 0)
		return (a % b);
	else
		return ((a % b) + b);
}

uint16_t			ft_get_addr(uint16_t pc, int addr, int m_size)
{
	uint16_t		ret;
	int				tmp;

	ret = 0;
	tmp = pc;
	tmp += addr % m_size;
	pc = exec_modulo(tmp, MEM_SIZE);
	ret = pc;
	return (ret);
}
