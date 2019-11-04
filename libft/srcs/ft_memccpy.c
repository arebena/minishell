/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebena <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 17:52:29 by arebena           #+#    #+#             */
/*   Updated: 2016/09/21 19:19:54 by arebena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	int		i;
	char	*temp;
	char	*tmp;

	i = 0;
	if ((char)n < 0)
		return (NULL);
	temp = dst;
	tmp = (char *)src;
	while (n--)
	{
		temp[i] = tmp[i];
		if (tmp[i++] == (char)c)
			return ((void *)&(temp[i]));
	}
	return (NULL);
}
