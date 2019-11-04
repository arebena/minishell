/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raw_mode.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebena <arebena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 07:27:33 by arebena           #+#    #+#             */
/*   Updated: 2019/11/01 08:52:54 by arebena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	disable_raw_mode(unsigned long int sig)
{
	static t_termios	*orig_termios = NULL;

	if (orig_termios == NULL)
		orig_termios = (t_termios*)sig;
	else
		if (!(tcsetattr(STDIN_FILENO, TCSAFLUSH, orig_termios)) && sig)
		{
			if (sig == SIGSEGV)
				ft_putstr("\rsegmentation fault, sorry\r\n");
			if (sig == SIGABRT)
				ft_putstr("\rAbort, sorry\r\n");
			exit (-1);
		}
}

void	enable_raw_mode(t_termios *orig_termios)
{
	t_termios	raw;

	tcgetattr(STDIN_FILENO, orig_termios);
	raw = *orig_termios;
	raw.c_cc[VMIN] = 0;
	raw.c_cc[VTIME] = 1;
	// raw.c_oflag &= ~(OPOST);
	raw.c_iflag &= ~(IXON | ICRNL);
	raw.c_lflag &= ~(ICANON | ECHO | ISIG | IEXTEN);
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}
