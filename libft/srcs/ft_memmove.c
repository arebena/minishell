/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebena <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 16:06:55 by arebena           #+#    #+#             */
/*   Updated: 2016/09/21 19:17:01 by arebena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int		i;
	char	*srcb;
	char	*dstb;

	i = -1;
	if ((char)len == 0)
		return (dst);
	dstb = ft_strdup((char *)dst);
	srcb = (char *)src;
	while (++i < (int)len)
		dstb[i] = srcb[i];
	ft_memcpy((char *)dst, dstb, len);
	free(dstb);
	return ((void *)dst);
}
