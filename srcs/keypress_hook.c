/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress_hook.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebena <arebena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 08:14:23 by arebena           #+#    #+#             */
/*   Updated: 2019/11/01 09:51:14 by arebena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		is_ctrl_key(char key)
{
	if ((key >= 0 && key < 32) || key == BACKSPACE)
		return (1);
	return (0);
}

int		key_read(char *k)
{
	int		nread;

	while ((nread = read(STDIN_FILENO, k, 1)) != 1)
		if (nread == -1)
			die("read");
	return (nread);
}

void	key_loop(t_shell *sh)
{
	char	key;

	reset_input(sh);
	while (sh->action != QUIT && sh->action != ENTER)
	{
		key_read(&key);
		// print_input((unsigned char)key);
		if (is_ctrl_key(key))
			process_ctrl_key(sh, key);
		else
			process_char_key(sh, key);
	}
}
