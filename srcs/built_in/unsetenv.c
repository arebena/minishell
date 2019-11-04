
#include "minishell.h"

void	unset_env_row(t_shell *sh, int spot)
{
	int		i;
	int		e;
	char	**n_env;

	i = 0;
	while (sh->env[i])
		i++;
	n_env = (char **)malloc(sizeof(char *) * (i));
	i = 0;
	e = 0;
	while (sh->env[i])
	{
		if (i == spot)
			free(sh->env[i]);
		else
			n_env[e++] = sh->env[i];
		i++;
	}
	n_env[e] = NULL;
	free(sh->env);
	sh->env = n_env;
}

void	try_to_unset(t_shell *sh, char *built_in)
{
	int		i;

	i = 0;
	while (sh->env[i])
	{
		if (env_cmp(built_in, sh->env[i]))
			unset_env_row(sh, i);
		i++;
	}
}

void	ft_unsetenv(t_shell *sh, char **built_in)
{
	int		i;

	i = 1;
	if (!(built_in[i]))
		command_error("not enough arguments", "unsetenv");
	while (built_in[i])
	{
		try_to_unset(sh, built_in[i]);
		i++;
	}
}
