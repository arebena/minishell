/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebena <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 15:34:55 by arebena           #+#    #+#             */
/*   Updated: 2016/09/21 19:20:15 by arebena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int		i;
	char	*temp;
	char	*tmp;

	i = -1;
	if ((int)n == 0)
		return (dst);
	temp = dst;
	tmp = (char *)src;
	while (n-- != 0)
	{
		i++;
		temp[i] = tmp[i];
	}
	dst = (void *)temp;
	return (dst);
}
