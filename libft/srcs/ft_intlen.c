/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebena <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/26 15:40:16 by arebena           #+#    #+#             */
/*   Updated: 2016/09/21 21:16:43 by arebena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_intlen(int n)
{
	long int	nb;
	int			len;

	nb = n;
	if (nb == 0)
		return (1);
	len = 0;
	if (nb < 0)
		if ((nb = -nb) > 0)
			len++;
	while (nb > 0)
	{
		len++;
		nb /= 10;
	}
	return (len);
}