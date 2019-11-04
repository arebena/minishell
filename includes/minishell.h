/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebena <arebena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 02:29:44 by arebena           #+#    #+#             */
/*   Updated: 2019/11/01 11:17:49 by arebena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h> // BEWARE
# include <errno.h> // BEWARE

# include <termios.h>
# include <signal.h>
# include <dirent.h>
# include <wait.h>
# include "libft.h"
# include "get_next_line.h"
# include "struct.h"
# include "param.h"
# include "define.h"


void		clear_screen(t_shell *sh);
void		render_prompt(t_shell *sh);
void		render_input(t_shell *sh);
void		update_input(t_shell *sh);
void		print_input(unsigned char c);

void		reset_input(t_shell *sh);
void		resize_input(t_cmd *cmd);

void		command_error(char *msg, char *file);
void		die(const char *s);
int			get_cursor_position(int *rows, int *cols);

void		command_exec(t_shell *sh);
void		enable_raw_mode(t_termios *orig_termios);
void		disable_raw_mode(unsigned long int sig);

int			built_in(t_shell *sh, char **built_in);
void		ft_setenv(t_shell *sh, char **built_in);
void		ft_unsetenv(t_shell *sh, char **built_in);
int			env_cmp(char *n_env, char *ex_env);


int			is_ctrl_key(char key);
int			key_read(char *k);
void		key_loop(t_shell *sh);
void		process_char_key(t_shell *sh, char c);
void		process_ctrl_key(t_shell *sh, char k);

#endif
