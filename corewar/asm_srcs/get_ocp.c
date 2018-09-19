/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ocp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bait-sli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 21:50:34 by bait-sli          #+#    #+#             */
/*   Updated: 2018/04/26 05:37:54 by bait-sli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static uint8_t		param_ocp(char *str, int pos)
{
	if (isdir(str))
		return (DIR_OP << (pos * 2));
	if (isindir(str))
		return (INDIR_OP << (pos * 2));
	if (isreg(str))
		return (REG_OP << (pos * 2));
	return (0);
}

static int			*ft_encodage(int *binary, char **params)
{
	int				i;
	char			*tmp;
	long long		ttc;

	i = -1;
	while (++i < char_len(params))
	{
		tmp = ft_strsub(params[i], 1, ft_strlen(params[i]));
		if (isindir(params[i]) == 1)
		{
			ttc = ft_atoi_long_long(params[i]);
			binary[i] = ttc % INT_MAX;
		}
		else
		{
			ttc = ft_atoi_long_long(tmp);
			binary[i] = ttc % INT_MAX;
		}
		free(tmp);
	}
	return (binary);
}

static uint8_t		ft_get_ocp(char **params)
{
	uint8_t			ret;
	int				i;

	i = -1;
	ret = 0;
	while (++i < char_len(params))
		ret |= param_ocp(params[i], 3 - i);
	return (ret);
}

void				ft_convert(t_parse **buff)
{
	t_parse			*e;

	e = *buff;
	while (e != NULL)
	{
		if (e->form.dir_instruct == 1 || e->form.labeled_instruct == 1)
		{
			if (!(e->binary = (int*)malloc(sizeof(int*) * char_len(e->params))))
				return ;
			e->binary = ft_encodage(e->binary, e->params);
			if (e->form.has_ocp == 1)
				e->ocp = ft_get_ocp(e->params);
		}
		e = e->next;
	}
}
