/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebena <arebena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 02:38:29 by arebena           #+#    #+#             */
/*   Updated: 2019/11/01 09:56:59 by arebena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct termios	t_termios;

typedef struct		s_cmd
{
	char			*input;
	int				input_len;
}					t_cmd;

typedef struct		s_shell
{
	t_termios		origin_t;
	t_cmd			cmd;
	char			**env;
	char			**path;
	char			action;
	char			*prompt;
}					t_shell;

#endif
