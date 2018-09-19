/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bait-sli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 07:23:57 by bait-sli          #+#    #+#             */
/*   Updated: 2018/04/05 16:00:07 by bait-sli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			ft_init(t_env *env)
{
	env->buff = NULL;
	env->magic_nbr = COREWAR_EXEC_MAGIC;
	env->line_nbr = 1;
	env->verif.name = 0;
	env->prog_length = 0;
	env->verif.comment = 0;
	env->verif.ref_pos = 0;
	env->verif.line_pos = 0;
	env->verif.lab_pos = 0;
	env->verif.check_sum = 0;
	env->prog_name = NULL;
	env->prog_comment = NULL;
	env->output_name = NULL;
}

static int		arg_validity(char *name, t_env *env)
{
	int			x;
	char		*tmp;

	x = ft_strlen(name) - 1;
	if (x < 0)
		return (0);
	if (name[x] != 's' || name[x - 1] != '.')
		return (0);
	tmp = ft_strsub(name, 0, x - 1);
	env->output_name = ft_strjoin(tmp, OUTPUT_EXT);
	free(tmp);
	return (1);
}

static void		check_size(t_parse **buff, t_env *env)
{
	t_parse		*elem;
	int			check_sum;

	check_sum = 0;
	elem = *buff;
	while (elem != NULL)
	{
		check_sum += elem->content_size;
		elem = elem->next;
	}
	if (check_sum <= 0)
		ft_error(EMPTY_FILE, env);
	if (check_sum > CHAMP_MAX_SIZE)
		ft_error(BIG_SIZE, env);
	env->prog_length = check_sum;
}

static void		reverse_parse(t_parse **l)
{
	t_parse		*inv;
	t_parse		*head;

	inv = *l;
	if (inv && inv->next)
	{
		head = inv->next;
		reverse_parse(&(inv->next));
		head->next = inv;
		*l = inv->next;
		head->next->next = NULL;
	}
}

int				main(int ac, char **av)
{
	int			i;
	t_env		env;

	i = 0;
	ft_init(&env);
	if (ac <= 1)
		ft_error(ARGS_ERR, &env);
	if (arg_validity(av[ac - 1], &env) == 0)
		ft_error(BAD_EXT, &env);
	ft_parsing(av[ac - 1], &env);
	reverse_parse(&env.buff);
	ft_build_content(&env.buff);
	check_label(&env.buff, &env);
	ft_convert(&env.buff);
	check_size(&env.buff, &env);
	ft_output(&env);
	free_mem(&env);
	return (0);
}
