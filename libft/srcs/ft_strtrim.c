/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebena <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 19:13:44 by arebena           #+#    #+#             */
/*   Updated: 2016/09/21 19:03:11 by arebena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	int		beg;
	int		end;

	beg = 0;
	if (!s)
		return (NULL);
	end = ft_strlen(s) - 1;
	if (s[0] == 0)
		return (str = ft_strdup(""));
	while ((s[beg] == ' ' || s[beg] == '\n' || s[beg] == '\t') && s[beg])
		beg++;
	while ((s[end] == ' ' || s[end] == '\n' || s[end] == '\t') && end >= 0)
		end--;
	if (beg == 0 && end == (int)(ft_strlen(s) - 1))
		return (str = ft_strdup(s));
	else if (s[beg] == 0)
		return (str = ft_strdup(""));
	if (!(str = ft_strsub(s, (unsigned int)beg, (end - beg) + 1)))
		return (NULL);
	return (str);
}
