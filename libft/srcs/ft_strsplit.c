/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebena <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 23:17:07 by arebena           #+#    #+#             */
/*   Updated: 2016/09/21 19:02:16 by arebena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	w_len(char *src, char c)
{
	int len;

	len = 0;
	while (src[len] != c && src[len])
		len++;
	return (len);
}

static int	w_count(char *str, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			i = (i + w_len(&(str[i]), c)) - 1;
			count++;
		}
		i++;
	}
	return (count);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		i2;
	char	**tab;

	i = -1;
	tab = NULL;
	i2 = 0;
	if (s == NULL)
		return (NULL);
	if (!(tab = (char **)malloc(sizeof(char *) * (w_count((char *)s, c) + 1))))
		return (NULL);
	while (s[++i] != 0)
		if (s[i] != c)
		{
			tab[i2] = ft_strndup((char *)&(s[i]), w_len((char *)&(s[i]), c));
			i = (i + w_len((char *)&(s[i]), c)) - 1;
			i2++;
		}
	tab[i2] = NULL;
	return (tab);
}
