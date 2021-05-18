/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 12:21:46 by hugsbord          #+#    #+#             */
/*   Updated: 2021/05/17 11:44:22 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/minishell.h"

int		ft_builtin_env(void)
{
	int		i;

	i = 0;
	while (g_env[i])
	{
		ft_putstr_fd(g_env[i], 1);
		ft_putchar_fd('\n', 1);
		i++;
	}
	return (SUCCESS);
}
