/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebena <arebena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 03:53:51 by arebena           #+#    #+#             */
/*   Updated: 2019/11/01 08:16:33 by arebena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	process_escape_key(t_shell *sh, char k)
{
	char	c;
	int		nread;

	while ((nread = read(STDIN_FILENO, &c, 1)))
		if (nread == -1)
			die("read");
	(void)sh;
	(void)k;
}

void	process_back_key(t_shell *sh)
{
	int		r;
	int		c;
	int		ret;

	sh->cmd.input_len--;
	sh->cmd.input[sh->cmd.input_len] = '\0';
	ret = get_cursor_position(&r, &c);
	write(STDOUT_FILENO, _CURSOR_LEFT_, 3);
	if (!ret && c <= 1)
	{
		write(STDOUT_FILENO, "\x1b[9999C", 7);
		write(STDOUT_FILENO, _CURSOR_UP_, 3);
	}
	write(STDOUT_FILENO, _ERASE_LINE_, 3);
}

void	process_char_key(t_shell *sh, char c)
{
	sh->cmd.input_len++;
	resize_input(&(sh->cmd));
	sh->cmd.input[sh->cmd.input_len - 1] = c;
	sh->cmd.input[sh->cmd.input_len] = '\0';
	update_input(sh);
}

void	process_ctrl_key(t_shell *sh, char k)
{
	// printf("IS_CNTRL (%d)\r\n", k);
	if (k == ENTER)
		sh->action = ENTER;
	else if (k == ESC_KEY)
		process_escape_key(sh, k);
	else if (k == BACKSPACE && sh->cmd.input_len)
		process_back_key(sh);
	else if (k == CTRL_KEY('l'))
		clear_screen(sh);
}
