/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bait-sli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 07:19:40 by bait-sli          #+#    #+#             */
/*   Updated: 2018/04/05 16:04:00 by bait-sli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char		*ft_epur_str(char *str)
{
	char	*src;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (((src = malloc(sizeof(char *) * (ft_strlen(str) + 1))) == NULL))
		return (NULL);
	while (str[i] != '\0')
	{
		if (str[i] == ' ' || str[i] == '\t')
		{
			while ((str[i] == ' ' || str[i] == '\t') && str[i] != '\0')
				i = i + 1;
			if (j > 0 && str[i] != '\0')
				src[j++] = ' ';
		}
		src[j] = str[i];
		j = j + 1;
		if (str[i] != '\0')
			i = i + 1;
	}
	src[j] = '\0';
	return (src);
}

char		*remove_comment(char *line)
{
	int		i;
	char	*ret;
	char	*tmp;

	i = ft_charchr(line, '#');
	if (i < 0)
		return (ft_strdup(line));
	tmp = ft_strsub(line, 0, i);
	ret = ft_epur_str(tmp);
	free(tmp);
	return (ret);
}

char		*rm_comment_in_hd(char *line)
{
	char	*tmp;
	int		len;
	char	*ret;
	int		i;

	len = ft_charchr(line, '"') + 1;
	tmp = ft_strsub(line, len, ft_strlen(line));
	i = ft_charchr(tmp, '"');
	if (tmp[i + 1] && tmp[i + 1] != '#' && tmp[i + 1] != ' ')
	{
		free(tmp);
		return (NULL);
	}
	if (tmp[i + 1] && tmp[i + 1] == ' ')
	{
		if (tmp[i + 2] && tmp[i + 2] != '#')
		{
			free(tmp);
			return (NULL);
		}
	}
	ret = ft_strsub(line, 0, i + len + 1);
	free(tmp);
	return (ret);
}
