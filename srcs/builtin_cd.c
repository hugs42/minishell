/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 09:58:39 by hugsbord          #+#    #+#             */
/*   Updated: 2021/05/04 18:19:56 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/minishell.h"

int		ft_builtin_cd(char *path)
{
	char		*old_pwd;
	char		*pwd;
	char		*pwd_ptr;
	char		*home;
	struct		stat f;

	home = ft_get_var("HOME");
	old_pwd = getcwd(NULL, 0);
	if ((!(path)) || (ft_strncmp(path, "~", 1) == 0 && ft_strlen(path) == 1))
	{
		if (chdir(home) < 0)
			ft_putstr_fd("bash: cd: HOME not set\n", 1);
		else if (chdir(home) == 0)
		{
			pwd = home;
			old_pwd = ft_get_var("OLDPWD");
		if (pwd != NULL && old_pwd != NULL)
			ft_strlcpy(old_pwd, pwd, ft_strlen(old_pwd) + ft_strlen(pwd));

		}
	}
//	else if (ft_strncmp(
	else if (chdir(path) == 0)
	{
		pwd = ft_get_var("PWD");
		old_pwd = ft_get_var("OLDPWD");
		if (pwd != NULL && old_pwd != NULL)
			ft_strlcpy(old_pwd, pwd, ft_strlen(old_pwd) + ft_strlen(pwd));
	}
	else if (chdir(path) < 0)
	{
		ft_putstr_fd("bash: cd: ", 1);
		ft_putstr_fd(path, 1);
		ft_putstr_fd(": No such file or directory\n", 1);
//		if (lstat(path, &f) == -1)
			
	}
//	ft_putstr_fd(pwd, 1);

		
//		new_pwd = chdir(home);
		
//	ft_update_var(path_split[1], "");
/*	if (chdir(path_split[1]) == -1)
	{
		ft_putstr_fd("Path_error\n", 1);
		return (ERROR);
	}*/
	return (SUCCESS);
}
