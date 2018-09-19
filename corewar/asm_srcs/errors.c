/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bait-sli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 07:19:51 by bait-sli          #+#    #+#             */
/*   Updated: 2018/03/24 21:06:05 by bait-sli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_error(char *format, t_env *env)
{
	ft_putendl_fd(format, 2);
	free_mem(env);
	exit(EXIT_FAILURE);
}

void	ft_line_error(char *format, t_env *env, int index)
{
	ft_putstr_fd(format, 2);
	ft_putnbr_fd(index, 2);
	ft_putchar_fd('\n', 2);
	free_mem(env);
	exit(EXIT_FAILURE);
}

void	ft_label_error(char *format, char *label, t_env *env)
{
	ft_putstr_fd(format, 2);
	ft_putnbr_fd(env->line_nbr, 2);
	ft_putchar_fd(' ', 2);
	ft_putstr_fd("param ", 2);
	ft_putstr_fd(label, 2);
	ft_putchar_fd('\n', 2);
	free_mem(env);
	exit(EXIT_FAILURE);
}
