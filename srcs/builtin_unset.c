/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 19:07:32 by hugsbord          #+#    #+#             */
/*   Updated: 2021/05/10 14:37:51 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/minishell.h"

int		ft_builtin_unset(char **key)
{
	int i;
	int var_nb;

	i = 1;
	var_nb = 0;
	if (!(key[i]))
		return (0);
	while (key[i])
	{
		var_nb = ft_find_var(key[i]);
		if (var_nb == -1)
		{
			while (var_nb == -1)
			{
				i++;
				if (!(key[i]))
					return (0);
				var_nb = ft_find_var(key[i]);
			}
		}
		if (g_env[var_nb])
		{
			free(g_env[var_nb]);
			g_env[var_nb] = NULL;
			while (g_env[var_nb + 1])
			{
				g_env[var_nb] = ft_strdup(g_env[var_nb + 1]);
				free(g_env[var_nb + 1]);
				var_nb++;
			}
		}
		i++;
		g_env = ft_realloc_env(var_nb);
	}
	return (SUCCESS);
}
