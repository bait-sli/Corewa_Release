/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acombe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 22:44:22 by acombe            #+#    #+#             */
/*   Updated: 2018/04/26 03:42:08 by acombe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_error(char *format, t_env *env)
{
	free_mem(env);
	ft_putstr_fd(format, 2);
	ft_putchar_fd('\n', 2);
	exit(EXIT_FAILURE);
}

void	ft_arg_error(char *format, char **arg, t_env *env)
{
	free_mem(env);
	free_split(arg);
	ft_putstr_fd(format, 2);
	ft_putchar_fd('\n', 2);
	exit(EXIT_FAILURE);
}
