# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/26 15:37:01 by hugsbord          #+#    #+#              #
#    Updated: 2021/09/15 14:35:58 by hugsbord         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRCS =	./srcs/main.c \
		./srcs/error.c \
		./srcs/parse_input.c \
		./srcs/get_absolute_path.c \
		./srcs/env_var.c \
		./srcs/execute.c \
		./srcs/builtin_env.c \
		./srcs/builtin_cd.c \
		./srcs/builtin_pwd.c \
		./srcs/builtin_unset.c \
		./srcs/builtin_exit.c \
		./srcs/init.c \
		./srcs/minishell_utils.c \
		./srcs/builtin_echo.c \
		./srcs/builtin_export.c \
		./srcs/signal.c

INC = -I ./includes -I/usr/local/opt/readline/include

FLAGS = -Wall -Wextra -Werror -lncurses

LIB_DIR = -L ./libft
LIBS = ./libft/libft.a $(READLINE)# $(TERMCAPS)
READLINE = -lreadline -L/usr/local/opt/readline/lib
#TERMCAPS = -ltermcap

OBJ = $(SRCS:.c=.o)

%.o: %.c
	@clang $(INC) -o $@ -c $<

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\033[96m"
	@echo "                            :::      ::::::::"
	@echo "                          :+:      :+:    :+:"
	@echo "    42_cursus:          +:+ +:+         +:+"
	@echo "    MINISHELL         +#+  +:+       +#+"
	@echo "                    +#+#+#+#+#+   +#+"
	@echo "                          #+#    #+#"
	@echo "                         ###   ########.fr\033[0m"
	@echo "\033[0m"
	@echo "\033[93m>> Libft compilation\033[0m"
	@make -C libft
	@echo "\033[93m>> Minishell compilation\033[0m"
	@clang $(FLAGS) $(INC) $(OBJ) $(LIBS) -o $(NAME)
	@echo "\033[92mMinishell correctly compilated\033[0m"

clean: $(OBJ)
	@echo "\033[93m>> Cleaning objects (.obj)\033[0m"
	@make $@ -C libft
	@rm -f $(OBJ)

fclean: clean
	@make $@ -C libft
	@rm -f $(NAME)

re:
	@make fclean
	@make all

bonus: $(NAME)

.PHONY: all, clean, fclean, re, bonus
