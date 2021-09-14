/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 08:25:28 by hugsbord          #+#    #+#             */
/*   Updated: 2021/09/14 11:41:17 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/minishell.h"
#include <signal.h>
#include <stdio.h>
#include <readline/readline.h>	
#include <readline/history.h>
void	ft_signal_handler(int signal)
{
	if (signal == SIGINT)
	{
//		rl_redisplay();
//		rl_replace_line("", 0);

//		rl_replace_line("", 0);

//		ft_putstr_fd("\n", 1);
//		ft_putstr_fd("Ctrl C\n",1);
		g_sig = 1;
		
	}
	else if (signal == SIGQUIT)
	{
//		ft_putstr_fd("luls", 1);
//		exit(0);
	}
	else if (signal == SIGTSTP)
	{
		ft_putstr_fd("Ctrl C\n",1);
	}
}

int		ft_ctrl(void)
{
	if (signal(SIGINT, ft_signal_handler) == SIG_ERR)
		exit(0);
	if (signal(SIGQUIT, ft_signal_handler) == SIG_ERR)
		exit(0);
	if (signal(SIGTSTP, ft_signal_handler) == SIG_ERR)
		exit(0);
	return (0);
}
