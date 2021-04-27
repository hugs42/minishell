# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/26 15:37:01 by hugsbord          #+#    #+#              #
#    Updated: 2021/04/27 09:33:42 by hugsbord         ###   ########.fr        #
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
	@make -C libft
	@clang $(FLAGS) $(INC) -o $(NAME) $(OBJ) $(LIBFT)

clean: $(OBJ)
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
