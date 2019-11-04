/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebena <arebena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 02:13:11 by arebena           #+#    #+#             */
/*   Updated: 2019/11/01 11:40:32 by arebena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**get_path(char **env)
{
	int		i;

	i = -1;
	while (env[++i])
		if (ft_strnequ(env[i], "PATH=", 5))
			return (ft_strsplit(&(env[i][5]), ':'));
	return (NULL);
}

void	free_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	sh_init(t_shell *sh, char **environ)
{
	sh->action = NONE;
	sh->env = ft_tabdup(environ);
	sh->path = get_path(sh->env);
	// ft_putsbtab(sh->path);
	sh->prompt = ft_strdup("$> ");
	sh->cmd.input = NULL;
	enable_raw_mode(&(sh->origin_t));
	disable_raw_mode((unsigned long int)&(sh->origin_t));
	signal(SIGSEGV, (void(*)())disable_raw_mode);
	signal(SIGABRT, (void(*)())disable_raw_mode);
}

int		main(void)
{
	t_shell		sh;
	extern char	**environ;

	// ft_putsbtab(environ);
	sh_init(&sh, environ);
	while (sh.action != QUIT)
	{
		render_prompt(&sh);
		key_loop(&sh);
		if (sh.action == ENTER)
		{
			ft_putstr("\n");
			command_exec(&sh);
		}
		else
			ft_putstr("\n");

 	}
	disable_raw_mode(0);
	exit (0);
}
