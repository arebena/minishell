/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itob.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebena <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 22:25:13 by arebena           #+#    #+#             */
/*   Updated: 2016/09/21 20:29:01 by arebena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itob(unsigned char ch)
{
	int		i;
	int		e;
	int		tmp;
	char	*bin;

	i = 8;
	if (ch == 0)
		return (ft_strdup("0"));
	bin = (char *)malloc(sizeof(char) * i + 1);
	bin[i--] = 0;
	e = 0;
	while (tmp = ch, i-- != -1)
		if ((tmp = ft_pow(2, i + 1)) <= ch)
		{
			bin[e++] = '1';
			ch -= tmp;
		}
		else
			bin[e++] = '0';
	return (bin);
}
