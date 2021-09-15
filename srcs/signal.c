/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 08:25:28 by hugsbord          #+#    #+#             */
/*   Updated: 2021/09/15 10:38:38 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "./../includes/minishell.h"

void	ft_signal_handler(int signal)
{
	if (signal == SIGINT && g_sig == 0)
	{
		rl_replace_line("", 0);
		ft_putchar_fd('\n', 1);
		rl_on_new_line();
		rl_redisplay();
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
