/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 15:46:46 by hugsbord          #+#    #+#             */
/*   Updated: 2021/04/30 08:41:21 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include "./../libft/libft.h"
#include "./get_next_line.h"

# define SUCCESS 1
# define ERROR -1
# define LEAVE -2

void	ft_prompt_msg(char *input);
char	*ft_get_input(void);
int		ft_error(int error);
int		ft_parse_input(char *input);
void	ft_signal_handler(int signal);

#endif
