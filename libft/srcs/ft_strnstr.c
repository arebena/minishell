/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebena <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 18:19:32 by arebena           #+#    #+#             */
/*   Updated: 2016/09/21 19:06:32 by arebena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	int i;
	int e;
	int	o;

	i = -1;
	if (s2[0] == 0)
		return ((char *)s1);
	e = 0;
	while (s1[++i] != 0 && i < (int)n)
	{
		o = i;
		if (s1[i] == s2[e])
			while (s1[o] == s2[e++] && o++ < (int)n)
				if (s2[e] == 0)
					return ((char *)&(s1[o - e]));
	}
	return (NULL);
}
