/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 12:36:44 by hugsbord          #+#    #+#             */
/*   Updated: 2021/05/05 18:36:24 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/minishell.h"

int		ft_find_var(char *var)
{
	int		i;
	int		var_nb;
	int		len;
	char	**tmp;

	i = 0;
	var_nb = 0;
	len = ft_strlen(var);
	while (g_env[i])
	{
		tmp = ft_split(g_env[i], '=');
		if (ft_strncmp(tmp[0], var, len) == 0)
			return (var_nb);
		var_nb++;
		i++;
	}
	return (-1);
}

char	*ft_get_var(char *var)
{
	int		i;
	int		len;
	char	**tmp;

	i = 0;
	len = ft_strlen(var);
	while (g_env[i])
	{
		tmp = ft_split(g_env[i], '=');
		if (ft_strncmp(tmp[0], var, len) == 0)
			return (tmp[1]);
		i++;
	}
	return (var);
}

void	ft_update_var(char *key, char *value)
{
	int		i;
	char	**tmp;
	int		var_nb;

	i = 0;
	var_nb = ft_find_var(key);
	if (g_env[var_nb])
	{
		tmp = ft_split(g_env[var_nb], ' ');
		free(tmp[1]);
		free(g_env[var_nb]);
		tmp[1] = ft_strdup(value);
		key = ft_strjoin(key, "=");
		g_env[var_nb] = ft_strjoin(key, tmp[1]);
	}
}
