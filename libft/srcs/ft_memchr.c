/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebena <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 16:31:04 by arebena           #+#    #+#             */
/*   Updated: 2016/09/21 19:17:26 by arebena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int		i;
	char	*tmp;

	tmp = (char *)s;
	i = 0;
	if ((int)n < 0)
		return (NULL);
	while (i < (int)n)
		if (tmp[i++] == (char)c)
			return ((void *)&(tmp[--i]));
	return (NULL);
}
