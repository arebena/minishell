/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnbr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebena <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 21:30:22 by arebena           #+#    #+#             */
/*   Updated: 2015/01/07 21:30:58 by arebena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isnbr(char *str)
{
	if (str[0] == '-' || str[0] == '+')
		if (str[1] >= '0' && str[1] <= '9')
			return (2);
	if (str[0] >= '0' && str[0] <= '9')
		return (1);
	else
		return (0);
}