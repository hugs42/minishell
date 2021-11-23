/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_absolute_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 09:53:47 by hugsbord          #+#    #+#             */
/*   Updated: 2021/11/18 12:59:52 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/minishell.h"

char	**ft_update_tab(t_data *data, char **new_cmd, int l, int count)
{
	int i;
	int l_tmp;
	int nb;
	char **tmp_cmd;

	i = 0;
	nb = 0;
	tmp_cmd = NULL;
	l_tmp = l;
	l++;
	ft_putnbr_fd(44444, 1);
	tmp_cmd = (char **)ft_calloc(count + 1, sizeof(char *));
	while (new_cmd[i])
	{
		tmp_cmd[i] = ft_strdup(new_cmd[i]);
		i++;
	}
//	i = 0;
	while (data->cmd[l])
	{
		tmp_cmd[i] = ft_strdup(data->cmd[l]);
//		free(data->cmd[l]);
//		data->cmd[l] = NULL;
//		data->cmd[l] = ft_strdup(new_cmd[i]);
		l++;
		i++;
	}
	int z = 0;
	while (tmp_cmd[z])
	{
		ft_putstr_fd("@@@", 1);
		ft_putstr_fd(tmp_cmd[z], 1);
		ft_putstr_fd("\n", 1);
		z++;
	}
	z = 0;
	while (data->cmd[l_tmp])
	{
		free(data->cmd[l_tmp]);
		data->cmd[l_tmp] = NULL;
		data->cmd[l_tmp] = ft_strdup(tmp_cmd[z]);
		l_tmp++;
	}
//	ft_putnbr_fd(i, 1);
	return (0);
}


char	**ft_check_tab_spaces(t_data *data, char *cmd, int l)
{
	int i;
	int count;
	char **new_cmd;

	i = 0;
	count = 0;
	new_cmd = NULL;
	while (cmd[i])
	{
		if (cmd[i] == '-' && cmd[i + 1] != ' ')
			count++;
		i++;
	}
	if (count > 1)
		new_cmd = ft_split(cmd, ' ');
		int z = 0;
	if (count > 1)
	{
	while (new_cmd[z])
	{
		ft_putstr_fd("XX", 1);
		ft_putstr_fd(new_cmd[z], 1);
		ft_putstr_fd("\n", 1);
		z++;
	}
	}
	if (count > 1)
		ft_update_tab(data, new_cmd, l, count);
	return (new_cmd);
}


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
	char		**cmd_tmp;

	i = 0;
	path_split = NULL;
	cmd_split = NULL;
	cmd_tmp = NULL;
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
//		ft_putstr_fd("*l*", 1);
		while (data->cmd[l])
		{
			if (!(ft_strchr(data->cmd[l], '\"')))
			{
				cmd_tmp = ft_check_tab_spaces(data, data->cmd[l], l);
//				ft_update_tab(data, cmd_tmp, l);
			}
			data->cmd[l] = ft_strtrim(data->cmd[l], " ");
			data->cmd[l] = ft_strtrim(data->cmd[l], "\"");
//			ft_check_tab_spaces(data->cmd[l]);
//			if (ft_strchr(data->cmd[l], ' ') && ft_strchr(data->cmd[l], '-'))
//				cmd_tmp = ft_split(cmd[l], ' ');
//			ft_putstr_fd("XX", 1);
//			ft_putstr_fd(cmd_tmp[l], 1);
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
//	while (data->cmd[j])
//	{
//		ft_putstr_fd(">>",1);
//		ft_putstr_fd(data->cmd[j], 1);
//		ft_putstr_fd("\n",1);
//		j++;
//	}
//	ft_putstr_fd("$$", 1);
//	ft_putstr_fd(cmd[0], 1);
	if (data->is_file == 1)
		return (1);
//	ft_putstr_fd("000",1);
	return (0);
}
