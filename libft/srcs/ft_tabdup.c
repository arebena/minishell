/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebena <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/02 15:44:01 by arebena           #+#    #+#             */
/*   Updated: 2016/09/21 19:03:42 by arebena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_tabdup(char **tab)
{
	int		i;
	char	**new_tab;

	i = 0;
	if (tab && *tab)
		while (tab[i])
			i++;
	else
		return (NULL);
	new_tab = (char **)malloc(sizeof(char *) * (i + 1));
	i = -1;
	while (tab[++i])
		new_tab[i] = ft_strdup(tab[i]);
	new_tab[i] = NULL;
	return (new_tab);
}
