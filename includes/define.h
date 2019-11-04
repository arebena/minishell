/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   def.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebena <arebena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 02:38:47 by arebena           #+#    #+#             */
/*   Updated: 2019/11/01 05:07:07 by arebena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEF_H
# define DEF_H

# define NONE 0
# define TRUE 1
# define FALSE 0
# define QUIT -1

# define ENTER 13
# define BACKSPACE 127
# define ESC_KEY 27
# define CTRL_KEY(k) ((k) & 0x1f)

# define _CURSOR_SAVE_ "\x1b[s"
# define _CURSOR_LOAD_ "\x1b[u"
# define _CURSOR_UP_ "\x1b[A"
# define _CURSOR_DOWN_ "\x1b[B"
# define _CURSOR_RIGHT_ "\x1b[C"
# define _CURSOR_LEFT_ "\x1b[D"
# define _ERASE_LINE_ "\x1b[K"

#endif
