/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_modif.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebena <arebena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 08:11:30 by arebena           #+#    #+#             */
/*   Updated: 2019/11/01 09:30:36 by arebena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	reset_input(t_shell *sh)
{
	sh->action = NONE;
	if (sh->cmd.input)
		free(sh->cmd.input);
	sh->cmd.input = ft_strnew(BUFFER_SIZE + 1);
	sh->cmd.input = ft_memset(sh->cmd.input, '\0', BUFFER_SIZE + 1);
	sh->cmd.input_len = 0;
}

void	resize_input(t_cmd *cmd)
{
	int		prev_input_size;
	int		new_input_size;
	char	*new_input;

	prev_input_size = ft_strlen(cmd->input);
	if (cmd->input_len >= prev_input_size)
	{
		new_input_size = prev_input_size + BUFFER_SIZE;
		new_input = ft_strnew(new_input_size + 1);
		new_input = ft_memset(new_input, '\0', new_input_size + 1);
		new_input = ft_strcpy(new_input, cmd->input);
		free(cmd->input);
		cmd->input = new_input;
	}
}
