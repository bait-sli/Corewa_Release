/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acombe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 22:45:16 by acombe            #+#    #+#             */
/*   Updated: 2018/04/26 03:43:00 by acombe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int	get_int(int fd, t_env *env)
{
	uint8_t	buff[4];
	int		i;
	int		ret;

	i = -1;
	ret = 0;
	if (!(read(fd, buff, 4) > 0))
		ft_error(HEADER_ERR, env);
	while (++i < 4)
		ret = ret * 16 * 16 + buff[i];
	return (ret);
}

static char	*toggle_name(char buff[PROG_NAME_LENGTH + 1])
{
	char	*ret;
	int		len;
	int		i;

	i = -1;
	len = ft_strlen(buff);
	if (!(ret = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ret[len] = '\0';
	while (++i < len)
		ret[i] = buff[i];
	return (ret);
}

static void	read_header(int fd, t_env *env, t_player *p)
{
	uint8_t empty[4];

	if ((p->magic = get_int(fd, env)) != COREWAR_EXEC_MAGIC)
		ft_error(BAD_MAGIC, env);
	if (!(read(fd, p->name, PROG_NAME_LENGTH) > 0))
		ft_error(HEADER_ERR, env);
	if (!(read(fd, empty, 4) > 0))
		ft_error(HEADER_ERR, env);
	if ((p->size = get_int(fd, env)) > CHAMP_MAX_SIZE)
		ft_error(BIG_SIZE_NBR, env);
	if (!(read(fd, p->comment, COMMENT_LENGTH) > 0))
		ft_error(HEADER_ERR, env);
	if (!(read(fd, empty, 4) > 0))
		ft_error(HEADER_ERR, env);
	p->uname = toggle_name(p->name);
}

static void	ft_parse_chp(t_env *env, t_player *p)
{
	int fd;
	int count;
	int i;

	i = -1;
	count = 0;
	if (!((fd = open(p->path, O_RDONLY)) >= 0))
		ft_error(ERR_FILE, env);
	read_header(fd, env, p);
	while (++i < CHAMP_MAX_SIZE)
	{
		if (read(fd, &p->content[i], 1) == 0)
		{
			if (p->size != count)
				ft_error(SIZE_DIFF, env);
			close(fd);
			return ;
		}
		count++;
	}
	close(fd);
	ft_error(SIZE_ERR, env);
}

void		ft_parsing(t_env *env)
{
	int i;

	i = -1;
	while (++i < MAX_ARGS_NUMBER)
	{
		if (env->p[i].booked == 1)
		{
			ft_parse_chp(env, &env->p[i]);
			free(env->p[i].path);
		}
	}
	ft_intro(env);
	init_mem(env);
}
