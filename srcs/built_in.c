/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebena <arebena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 02:29:44 by arebena           #+#    #+#             */
/*   Updated: 2019/11/01 11:17:49 by arebena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		env_cmp(char *n_env, char *ex_env)
{
	int		i;

	i = 0;
	while (n_env[i] && ex_env[i])
	{
		if (n_env[i] != ex_env[i])
			return (FALSE);
		i++;
	}
	if (!(n_env[i]) && ex_env[i] && ex_env[i] == '=')
		return (TRUE);
	else
		return (FALSE);
}

int		built_in(t_shell *sh, char **built_in)
{
	if (ft_strcmp(built_in[0], "exit") == 0)
		die(NULL);
	else if (ft_strcmp(built_in[0], "env") == 0)
		ft_putsbtab(sh->env);
	else if (ft_strcmp(built_in[0], "setenv") == 0)
		ft_setenv(sh, built_in);
	else if (ft_strcmp(built_in[0], "unsetenv") == 0)
		ft_unsetenv(sh, built_in);
	else
		return (FALSE);

	(void)sh;
	return (TRUE);
}
