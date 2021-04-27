# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/26 15:37:01 by hugsbord          #+#    #+#              #
#    Updated: 2021/04/27 16:51:19 by hugsbord         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRCS =	./srcs/main.c \
		./srcs/prompt_msg.c \

INC = -I ./includes

FLAGS = -Wall -Wextra -Werror

LIB_DIR = -L ./libft
LIBFT = ./libft/libft.a

OBJ = $(SRCS:.c=.o)

%.o: %.c
	@clang $(INC) -o $@ -c $<

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\033[36m"
	@echo "                             :::      ::::::::"
	@echo "                           :+:      :+:    :+:"
	@echo "    Project:             +:+ +:+         +:+"
	@echo "    MINISHELL          +#+  +:+       +#+"
	@echo "                     +#+#+#+#+#+   +#+"
	@echo "                           #+#    #+#"
	@echo "                          ###   ########.fr\033[0m"
	@echo "\033[0m"
	@echo "\033[33m>> Libft compilation\033[0m"
	@make -C libft
	@echo "\033[33m>> Minishell compilation\033[0m"
	@clang $(FLAGS) $(INC) -o $(NAME) $(OBJ) $(LIBFT)
	@echo "\033[32mMinishell correctly compilated\033[0m"

clean: $(OBJ)
	@echo "\033[33m>> Cleaning objects (.obj)\033[0m"
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
