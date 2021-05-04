/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_absolute_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 09:53:47 by hugsbord          #+#    #+#             */
/*   Updated: 2021/05/04 10:49:56 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/minishell.h"

int		ft_get_absolute_path(t_data *data, char **cmd)
{
	int			i;
	char		*path;
	char		**path_split;
	char		*bin;
	struct		stat f;

	i = 0;
	data->is_file = 0;
	path = ft_get_var("PATH");
	if (path == NULL)
		path = ft_strdup("/bin:/usr/local/bin:/usr/bin:/bin:/usr/local/sbin");
	if (cmd[0][0] != '/' && strncmp(cmd[0], "./", 2) != 0)
	{
		path_split = ft_split(path, ':');
		free(path);
		path = NULL;
		while (path_split[i])
		{
			bin = (char *)ft_calloc(ft_strlen(path_split[i]) + 1 +
			ft_strlen(cmd[0]) + 1, sizeof(char));
			ft_strlcat(bin, path_split[i], ft_strlen(bin) + ft_strlen(path_split[i]) + 1);
			ft_strlcat(bin, "/", ft_strlen(bin) + 2);
			ft_strlcat(bin, cmd[0], ft_strlen(bin) + ft_strlen(cmd[0]) + 1);
			if (stat(bin, &f) == 0)
			{
				data->is_file = 1;
				break;
			}
			free(bin);
			bin = NULL;
			i++;
		}
		ft_free_array(path_split);
		free(cmd[0]);
		cmd[0] = bin;
	}
	else
	{
		free(path);
		path = NULL;
	}
	if (data->is_file == 1)
		return (SUCCESS);
	else
		return (0);
}
