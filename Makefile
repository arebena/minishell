# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arebena <arebena@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/12/08 22:06:46 by arebena           #+#    #+#              #
#    Updated: 2019/11/01 08:37:50 by arebena          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRC =	GNL/get_next_line.c\
		built_in/setenv.c\
		built_in/unsetenv.c\
		minishell.c\
		raw_mode.c\
		command.c\
		built_in.c\
		input_modif.c\
		keypress_hook.c\
		keypress_handler.c\
		render.c\
		tools.c\
		debug.c\

SRCS =	$(addprefix srcs/,$(SRC))
SRCO =	$(addprefix obj/, $(notdir $(SRC:.c=.o)))

FLG =	-Wall -Wextra -Werror
LIBS =	-L libft/ -lft
LIBFT=	libft
HEADS =	-I libft/srcs/ -I srcs/GNL/ -I includes/

$(NAME):
	@echo "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
	@make --no-print-directory -C $(LIBFT)
	@echo  "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
	@echo "Creating MINISHELL Object files..."
	@gcc $(FLG) $(HEADS) -c $(SRCS)
	@mkdir -p obj
	@mv $(notdir $(SRCO)) obj
	@echo "Object files successfully compiled"
	@echo "Creating MINISHELL..."
	@gcc $(FLG) -o $(NAME) $(SRCO) $(LIBS)
	@chmod 755 $(NAME)
	@echo  "  ====== MINISHELL created ======"
	@echo  "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"

all:$(NAME)

Mclean:
	@rm -rf obj
	@echo "|| MINISHELL object files deleted"

Fclean:Mclean
	@rm -rf $(NAME)
	@echo "|| MINISHELL deleted"
	@make --no-print-directory -C $(LIBFT) fclean

clean:
	@rm -rf obj
	@echo "|| MINISHELL object files deleted"

fclean:clean
	@rm -rf $(NAME)
	@echo "|| MINISHELL deleted"

re: fclean all

rec: fclean all
	@rm -rf obj
	@echo "|| MINISHELL object files deleted"

RE: Fclean all
