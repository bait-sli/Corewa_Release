/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bait-sli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 23:12:05 by bait-sli          #+#    #+#             */
/*   Updated: 2017/06/07 23:12:13 by bait-sli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strcnew(size_t size, char c)
{
	char	*output;

	if (!(output = (char*)malloc(size + 1)))
		return (NULL);
	ft_memset(output, c, size);
	output[size] = '\0';
	return (output);
}
