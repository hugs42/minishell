/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 10:24:27 by hugsbord          #+#    #+#             */
/*   Updated: 2021/09/22 23:00:31 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/minishell.h"

int		ft_init_struct_pwd(t_data *data)
{
	data->pwd = ft_calloc(1, sizeof(t_pwd));
	data->pwd->pwd = NULL;
	data->pwd->old_pwd = NULL;
	return (SUCCESS);
}

int		ft_init_struct(t_data *data)
{
	ft_init_struct_pwd(data);
	data->i = 0;
	data->is_file = 0;
	data->echo_n = 0;
	data->ret = 0;
	data->old_ret = 0;
	data->input = NULL;
	data->path = NULL;
	data->path_split = NULL;
	data->bin = NULL;
	data->is_q = 0;
	data->quote = 0;
	data->in_quote = 0;
	data->start = 0;
	data->end = 0;
	data->cmd = NULL;
	return (SUCCESS);
}

int		ft_init_env(char **envp)
{
	int		i;
	int		shlvl;

	i = 0;
	shlvl = 0;
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
	shlvl = ft_atoi(ft_get_var("SHLVL"));
	shlvl++;
	ft_update_var("SHLVL", ft_itoa(shlvl));
	return (SUCCESS);
}
