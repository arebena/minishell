/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebena <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 22:25:13 by arebena           #+#    #+#             */
/*   Updated: 2016/09/21 20:29:01 by arebena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_digi_loop(char *str, long int nb, int n)
{
	int		i;
	int		digit;

	i = 0;
	while (nb != 0 && (i < (ft_intlen(n))))
	{
		digit = nb % 10;
		nb /= 10;
		if (digit < 10)
			str[i++] = '0' + digit;
		else
			str[i++] = 'A' + digit - 10;
	}
	str[ft_intlen(n)] = '\0';
	str = ft_strrev(str);
	return (str);
}

char	*ft_itoa(int n)
{
	long int	nb;
	char		*str;
	char		*mem;

	if (!(str = (char *)malloc(ft_intlen(n) + 1)))
		return (NULL);
	mem = str;
	if (n == 0)
	{
		str = "0";
		return (ft_strcpy(mem, str));
	}
	nb = n;
	if (n < 0)
		if ((nb = -nb) > 0)
			str[ft_intlen(-nb) - 1] = '-';
	str = ft_itoa_digi_loop(str, nb, n);
	ft_strcpy(mem, str);
	return (mem);
}
