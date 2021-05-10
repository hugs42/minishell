/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_absolute_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 09:53:47 by hugsbord          #+#    #+#             */
/*   Updated: 2021/05/10 12:43:03 by hugsbord         ###   ########.fr       */
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
		return (SUCCESS);
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
	if (data->path == NULL)
		data->path = ft_strdup("/bin:/usr/local/bin:/usr/bin:/bin:/usr/local/sbin");
	if (cmd[0][0] != '/' && strncmp(cmd[0], "./", 2) != 0)
	{
		path_split = ft_split(data->path, ':');
		free(data->path);
		data->path = NULL;
		while (path_split[i])
		{
			if (ft_find_bin(data, i, cmd, path_split) == SUCCESS)
				break ;
			free(data->bin);
			data->bin = NULL;
			i++;
		}
		if (data->is_file == 1)
		{
			free(cmd[0]);
			cmd[0] = data->bin;
		}
	}
	else
	{
		free(data->path);
		data->path = NULL;
	}
	if (data->is_file == 1)
		return (SUCCESS);
	return (0);
}
