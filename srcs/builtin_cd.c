/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 09:58:39 by hugsbord          #+#    #+#             */
/*   Updated: 2021/05/05 18:48:53 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/minishell.h"

void	ft_builtin_cd_err(t_data *data, char *path)
{
	struct stat f;

	if (stat(path, &f) == -1)
	{
		ft_putstr_fd("bash: cd: ", 2);
		ft_putstr_fd(path, 2);
		ft_putstr_fd(": No such file or directory\n", 2);
	}
	else if (!(f.st_mode & S_IXUSR))
	{
		ft_putstr_fd("bash: cd: \n", 2);
		ft_putstr_fd(path, 2);
		ft_putstr_fd(": Permission denied\n", 2);
	}
	else
	{
		ft_putstr_fd("bash: cd: \n", 2);
		ft_putstr_fd(path, 2);
		ft_putstr_fd(": Not a directory\n", 2);
	}
}

void	ft_builtin_cd_last(t_data *data, char *pwd)
{
	if (chdir(ft_get_var("OLDPWD")) == 0)
	{
		ft_update_var("PWD", pwd);
		ft_update_var("OLDPWD", data->pwd->old_pwd);
	}
}

void	ft_builtin_cd_home(t_data *data, char *home, char *pwd)
{
	if (chdir(home) < 0)
		ft_putstr_fd("bash: cd: HOME not set\n", 1);
	else if (chdir(home) == 0)
	{
		pwd = home;
		ft_update_var("PWD", pwd);
		ft_update_var("OLDPWD", data->pwd->old_pwd);
	}
}

int		ft_builtin_cd(t_data *data, char *path)
{
	char		*pwd;
	char		*home;

	home = ft_get_var("HOME");
	pwd = getcwd(NULL, 0);
	if ((!(path)) || (ft_strncmp(path, "~", 1) == 0 && ft_strlen(path) == 1) ||
	(ft_strncmp(path, "--", 2) == 0 && ft_strlen(path) == 2))
		ft_builtin_cd_home(data, home, pwd);
	else if (ft_strncmp(path, "-", 1) == 0 && ft_strlen(path) == 1)
		ft_builtin_cd_last(data, pwd);
	else if (chdir(path) == 0)
	{
		ft_update_var("PWD", pwd);
		ft_update_var("OLDPWD", data->pwd->old_pwd);
	}
	else if (chdir(path) < 0)
		ft_builtin_cd_err(data, path);
	return (SUCCESS);
}
