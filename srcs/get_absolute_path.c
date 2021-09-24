/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_absolute_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 09:53:47 by hugsbord          #+#    #+#             */
/*   Updated: 2021/09/24 17:21:29 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/minishell.h"

int		ft_find_bin(t_data *data, int i, char **cmd, char **path_split)
{
	struct stat f;

	data->is_file = 0;
	data->bin = (char *)ft_calloc(ft_strlen(path_split[i]) + 1 +
	ft_strlen(cmd[0]) + 1, sizeof(char));
	ft_strlcat(data->bin, path_split[i], ft_strlen(data->bin) +
	ft_strlen(path_split[i]) + 1);
	ft_strlcat(data->bin, "/", ft_strlen(data->bin) + 2);
	ft_strlcat(data->bin, cmd[0], ft_strlen(data->bin) + ft_strlen(cmd[0]) + 1);
	if (stat(data->bin, &f) == 0)
	{
		data->is_file = 1;
		return (1);
	}
	return (0);
}

int		ft_get_absolute_path(t_data *data, char **cmd)
{
	int			i;
	char		**path_split;
	char		**cmd_split;

	i = 0;
	path_split = NULL;
	cmd_split = NULL;
	data->path = ft_get_var("PATH");
	int j = 0;
	int k = 0;
	int l = 0;
	if (data->is_q == 1)
	{
//		data->cmd[0] = ft_strtrim(cmd[0], " ");
		ft_putstr_fd("*k*", 1);
		while (cmd[k])
		{
			ft_putstr_fd(cmd[k], 1);
			ft_putstr_fd("\n", 1);
			k++;
		}
		data->cmd = ft_split_refill(cmd[0], '\"');
//		data->cmd[1] = ft_strtrim(cmd[1], " ");
//		data->cmd = ft_split(cmd[0], ' ');
		ft_putstr_fd("*l*", 1);
		while (data->cmd[l])
		{
			data->cmd[l] = ft_strtrim(data->cmd[l], " ");
//			ft_putstr_fd(data->cmd[l], 1);
//			ft_putstr_fd("\n", 1);
			l++;
		}
//		data->cmd[0] = ft_strtrim(cmd[0], " ");
//		ft_check_q_spaces(data, cmd);
	}
	else if (data->is_q == 0)
		data->cmd = ft_split(cmd[0], ' ');
//	ft_putstr_fd("3", 1);
//	ft_putstr_fd(cmd[0], 1);
//	ft_putstr_fd("3", 1);
	if (data->path == NULL)
		data->path = ft_strdup("/bin:/usr/local/bin:/usr/bin:/bin:/usr/local/sbin");
	if (cmd[0][0] != '/' && strncmp(cmd[0], "./", 2) != 0)
	{
		path_split = ft_split(data->path, ':');
		free(data->path);
		data->path = NULL;
		while (path_split[i])
		{
			if (ft_find_bin(data, i, data->cmd, path_split) == 1)
				break ;
			free(data->bin);
			data->bin = NULL;
			i++;
		}
		if (data->is_file == 1)
		{
			free(cmd[0]);
			data->cmd[0] = data->bin;
		}
	}
	else
	{
		free(data->path);
		data->path = NULL;
	}
	while (data->cmd[j])
	{
		ft_putstr_fd(">>",1);
		ft_putstr_fd(data->cmd[j], 1);
		ft_putstr_fd("\n",1);
		j++;
	}
//	ft_putstr_fd("$$", 1);
//	ft_putstr_fd(cmd[0], 1);
	if (data->is_file == 1)
		return (1);
//	ft_putstr_fd("000",1);
	return (0);
}
