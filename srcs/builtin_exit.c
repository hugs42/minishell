/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 14:25:59 by hugsbord          #+#    #+#             */
/*   Updated: 2021/09/15 12:07:01 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/minishell.h"

void	ft_free_all(t_data *data)
{
	int i;

	i = 0;
	if (g_env[i])
	{
		while (g_env[i])
		{
			free(g_env[i]);
			i++;
		}
	}
}

void	ft_builtin_exit(t_data *data)
{
	
//	ft_free_all(data);
	ft_putstr_fd("exit\n", 1);
	exit(0);
}
