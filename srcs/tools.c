/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebena <arebena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 03:54:14 by arebena           #+#    #+#             */
/*   Updated: 2019/11/01 08:17:09 by arebena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	command_error(char *msg, char *file)
{
	ft_putstr("minishell: ");
	ft_putstr(msg);
	ft_putstr(": ");
	ft_putstr(file);
	ft_putstr("\n");
}

void	die(const char *s)
{
	disable_raw_mode(0);
	if (s)
	{
		ft_putstr(s);
		ft_putstr("\n");
		exit(1);
	}
	else
		exit(0);
}

int		get_cursor_position(int *rows, int *cols)
{
	unsigned int	i;
	char			buf[32];

	i = -1;
	if (write(STDOUT_FILENO, "\x1b[6n", 4) != 4)
		return (-1);
	while (++i < sizeof(buf) - 1)
		if (read(STDIN_FILENO, &buf[i], 1) != 1 || buf[i] == 'R')
			break;
	buf[i] = '\0';
	if (buf[0] != '\x1b' || buf[1] != '[')
		return (-1);
	i = 0;
	*rows = ft_atoi(&buf[2]);
	while (buf[i++])
		if (buf[i] == ';')
			*cols = ft_atoi(&buf[i + 1]);
	return (0);
}
