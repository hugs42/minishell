/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 10:24:27 by hugsbord          #+#    #+#             */
/*   Updated: 2021/05/04 11:31:00 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/minishell.h"

int		ft_init_struct(t_data *data)
{
	data = ft_calloc(1, sizeof(data));
	data->i = 0;
	data->is_file = 0;
	data->input = NULL;
	data->path = NULL;
	data->path_split = NULL;
	data->bin = NULL;
	return (SUCCESS);
}

int		ft_init_env(char **envp)
{
	int		i;

	i = 0;
	while (envp[i])
		i++;
	if (!(g_env = (char **)ft_calloc(i + 1, sizeof(char *))))
		return (ERROR);
	i = 0;
	while (envp[i])
	{
		g_env[i] = ft_strdup(envp[i]);
		i++;
	}
	return (SUCCESS);
}
