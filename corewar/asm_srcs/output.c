/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bait-sli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 07:24:25 by bait-sli          #+#    #+#             */
/*   Updated: 2018/03/24 22:16:12 by bait-sli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int			ft_endian(int x)
{
	int				ret;

	ret = x;
	ret = ((ret >> 24) & 0xff) | ((ret << 8) & 0xff0000) |
		((ret >> 8) & 0xff00) | ((ret << 24) & 0xff000000);
	return (ret);
}

static void			output_line(int *format, char **params, int dir, int fd)
{
	int				i;
	int				len;
	int				rip;

	len = char_len(params);
	i = -1;
	while (++i < len)
	{
		if (isreg(params[i]) == 1)
			write(fd, &format[i], 1);
		if (isindir(params[i]) == 1 || (isdir(params[i]) == 1 && dir == 2))
		{
			write(fd, ((char *)&format[i]) + 1, 1);
			write(fd, &format[i], 1);
		}
		rip = ft_endian(format[i]);
		if (isdir(params[i]) == 1 && dir == 4)
			write(fd, &rip, 4);
	}
}

static void			output_core(t_parse **output, int fd)
{
	t_parse			*elem;

	elem = *output;
	while (elem != NULL)
	{
		if (elem->form.dir_instruct == 1 || elem->form.labeled_instruct == 1)
		{
			write(fd, &elem->opcode, 1);
			if (elem->form.has_ocp == 1)
				write(fd, &elem->ocp, 1);
			output_line(elem->binary, elem->params, elem->dir_size, fd);
		}
		elem = elem->next;
	}
}

void				ft_output(t_env *env)
{
	int				fd;
	int				magic;
	int				length;
	int				x;

	x = 0;
	length = ft_endian(env->prog_length);
	magic = ft_endian(env->magic_nbr);
	if (!(fd = open(env->output_name, O_CREAT | O_RDWR | O_TRUNC, 0644)))
		ft_error(CREAT_FILE_ERR, env);
	write(fd, &magic, 4);
	write(fd, env->prog_name, PROG_NAME_LENGTH);
	write(fd, &x, 4);
	write(fd, &length, 4);
	write(fd, env->prog_comment, COMMENT_LENGTH);
	write(fd, &x, 4);
	output_core(&env->buff, fd);
	ft_putstr(SUCCES);
	ft_putendl(env->output_name);
	close(fd);
}
