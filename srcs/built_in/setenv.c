
#include "minishell.h"

int		add_env_row(t_shell *sh)
{
	int		i;
	char	**n_env;

	i = 0;
	while (sh->env[i])
		i++;
	n_env = (char **)malloc(sizeof(char *) * (i + 2));
	i = 0;
	while (sh->env[i])
	{
		n_env[i] = sh->env[i];
		i++;
	}
	n_env[i] = NULL;
	n_env[i + 1] = NULL;
	free(sh->env);
	sh->env = n_env;
	return (i);
}

void	modify_env(t_shell *sh, char **built_in, int spot)
{
	sh->env[spot] = ft_strdup(built_in[1]);
	sh->env[spot] = ft_strmcat(sh->env[spot], "=");
	if (built_in[2])
		sh->env[spot] = ft_strmcat(sh->env[spot], built_in[2]);
}

int		existing_row(t_shell *sh, char **built_in)
{
	int		i;

	i = 0;
	while (sh->env[i])
	{
		if (env_cmp(built_in[1], sh->env[i]))
		{
			free(sh->env[i]);
			modify_env(sh, built_in, i);
			return (TRUE);
		}
		i++;
	}
	return (FALSE);
}

void	ft_setenv(t_shell *sh, char **built_in)
{
	int		spot;

	if (!(built_in[1]))
		ft_putsbtab(sh->env);
	else if (!(existing_row(sh, built_in)))
	{
		spot = add_env_row(sh);
		modify_env(sh, built_in, spot);
	}
}
