/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebena <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 15:24:18 by arebena           #+#    #+#             */
/*   Updated: 2016/09/21 19:05:26 by arebena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int i;
	int e;
	int	o;

	i = -1;
	if (s2[0] == 0)
		return ((char *)s1);
	while (s1[++i] != 0)
	{
		e = 0;
		o = i;
		if (s1[i] == s2[e])
			while (s1[o] == s2[e++])
			{
				o++;
				if (s2[e] == 0)
					return ((char *)&(s1[o - e]));
			}
	}
	return (NULL);
}
