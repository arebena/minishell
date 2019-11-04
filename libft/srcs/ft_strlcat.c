/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebena <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 18:41:20 by arebena           #+#    #+#             */
/*   Updated: 2016/09/21 19:12:39 by arebena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		get_count(char *dst, const char *src, size_t size)
{
	if ((int)ft_strlen(dst) < (int)size)
		return (ft_strlen(dst) + ft_strlen((char *)src));
	else
		return ((int)size + ft_strlen((char *)src));
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int i;
	int e;
	int flag;
	int count;

	e = 0;
	i = 0;
	flag = 0;
	count = get_count(dst, src, size);
	while ((i - 1) != (int)size - 1 && flag != -1)
	{
		if (flag == 1 && src[e])
		{
			dst[i - 1] = src[e++];
			dst[i] = 0;
		}
		else if (dst[i] == 0 && (i) < (int)size)
			flag = 1;
		i++;
	}
	if (flag == 1)
		dst[i - 1] = 0;
	return (count);
}
