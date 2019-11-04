/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebena <arebena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 06:58:11 by arebena           #+#    #+#             */
/*   Updated: 2019/11/01 08:07:49 by arebena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	clear_screen(t_shell *sh) {
	write(STDOUT_FILENO, "\x1b[2J", 4);
	write(STDOUT_FILENO, "\x1b[H", 3);
	render_prompt(sh);
	render_input(sh);
}

void	render_prompt(t_shell *sh)
{
	ft_putstr(sh->prompt);
}

void	render_input(t_shell *sh)
{
	int		i;

	i = 0;
	while (sh->cmd.input[i])
		ft_putchar(sh->cmd.input[i++]);
}

void	update_input(t_shell *sh)
{
	ft_putchar(sh->cmd.input[sh->cmd.input_len - 1]);
}
