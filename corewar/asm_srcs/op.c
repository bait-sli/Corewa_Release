/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bait-sli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 07:24:13 by bait-sli          #+#    #+#             */
/*   Updated: 2018/03/24 22:26:44 by bait-sli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

t_op	g_tab[20] =
{
	{"live", 1, {T_DIR}, 0x1, 10, "alive", 0, 0, 0},
	{"ld", 2, {T_DIR | T_IND, T_REG}, 0x2, 5, "load", 1, 0, 1},
	{"st", 2, {T_REG, T_IND | T_REG}, 0x3, 5, "store", 1, 0, 1},
	{"add", 3, {T_REG, T_REG, T_REG}, 0x4, 10, "addition", 1, 0, 1},
	{"sub", 3, {T_REG, T_REG, T_REG}, 0x5, 10, "soustraction", 1, 0, 1},
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 0x6, 6,
		"et (and  r1, r2, r3   r1&r2 -> r3", 1, 0, 1},
	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 0x7, 6,
		"ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 0, 1},
	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 0x8, 6,
		"ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 0, 1},
	{"zjmp", 1, {T_DIR}, 0x9, 20, "jump if zero", 0, 1, 0},
	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 0x0a, 25,
		"load index", 1, 1, 1},
	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 0x0b, 25,
		"store index", 1, 1, 1},
	{"fork", 1, {T_DIR}, 0x0c, 800, "fork", 0, 1, 0},
	{"lld", 2, {T_DIR | T_IND, T_REG}, 0x0d, 10, "long load", 1, 0, 1},
	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 0x0e, 50,
		"long load index", 1, 1, 1},
	{"lfork", 1, {T_DIR}, 0x0f, 1000, "long fork", 0, 1, 0},
	{"aff", 1, {T_REG}, 0x10, 2, "aff", 1, 0, 1},
	{"mul", 3, {T_REG, T_REG, T_REG}, 0x11, 10, "multiplication", 1, 0, 1},
	{"div", 3, {T_REG, T_REG, T_REG}, 0x12, 10, "division", 1, 0, 1},
	{"mod", 3, {T_REG, T_REG, T_REG}, 0x13, 10, "division", 1, 0, 1},
	{0, 0, {0}, 0, 0, 0, 0, 0, 0}
};
