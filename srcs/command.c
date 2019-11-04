/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebena <arebena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 08:36:48 by arebena           #+#    #+#             */
/*   Updated: 2019/11/01 11:42:53 by arebena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute(t_shell *sh, char *path, char **argv)
{
	pid_t		pid;
	pid_t		c_pid;
	int			status;

	disable_raw_mode(0);
	c_pid = fork();
	if (c_pid == 0)
		execve(path, argv, sh->env);
	else if (c_pid > 0)
	{
		if( (pid = wait(&status)) < 0)
      		exit(1);
	}
	enable_raw_mode(&(sh->origin_t));
}

void	find_the_exec(t_shell *sh, char **command)
{
	int				i;
	DIR				*dirp;
	struct dirent	*dp;
	char			*exec;

	i = 0;
	while (sh->path[i]) {
		// printf("For %s\r\n", sh->path[i]);
		if (!(access(sh->path[i], F_OK | X_OK)))
		{
			if ((dirp = opendir(sh->path[i])))
				while ((dp = readdir(dirp)) != NULL) {
					if (ft_strlen(command[0]) == ft_strlen(dp->d_name)
					&& ft_strcmp(command[0], dp->d_name) == 0)
					{
						exec = ft_strnew(ft_strlen(sh->path[i]) + ft_strlen(command[0]) + 2);
						ft_strcpy(exec, sh->path[i]);
						if (sh->path[i][ft_strlen(sh->path[i]) - 1] != '/')
							ft_strcat(exec, "/");
						ft_strcat(exec, command[0]);
						// printf("--| exec: [%s]\n", exec);
						if (access(exec, F_OK | X_OK))
							command_error("permission non accordée", command[0]);
						else
							execute(sh, exec, command);
						free(exec);
						(void)closedir(dirp);
						return ;
					}
				}
			(void)closedir(dirp);
		}
		i++;
	}
	command_error("command not found", command[0]);
	(void)exec;
}

void	free_command(char ***to_free)
{
	int		i;
	int		e;

	i = 0;
	while (to_free[i])
	{
		e = 0;
		while (to_free[i][e])
		{
			free(to_free[i][e]);
			to_free[i][e] = NULL;
			e++;
		}
		free(to_free[i]);
		to_free[i] = NULL;
		i++;
	}
	free(to_free);
	to_free = NULL;
}

char***	command_parse(char *input)
{
	char	***command_chain;
	char	**new_command;
	int		i;

	i = 0;
	new_command = ft_strsplit(input, ';');
	while (new_command[i])
		i++;
	command_chain = (char ***)malloc(sizeof(char**) * (i + 1));
	i = 0;
	while (new_command[i])
	{
		command_chain[i] = ft_strsplit(new_command[i], ' ');
		free(new_command[i]);
		i++;
	}
	free(new_command);
	command_chain[i] = NULL;
	return (command_chain);
}

void	command_exec(t_shell *sh)
{
	char	***command_chain;
	int		i;

	i = 0;
	command_chain = command_parse(sh->cmd.input);
	while (command_chain[i])
	{
		if (built_in(sh, command_chain[i]) == FALSE)
			find_the_exec(sh, command_chain[i]);
		i++;
	}
	free_command(command_chain);
	(void)sh;
}
