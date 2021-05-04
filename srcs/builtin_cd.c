/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 09:58:39 by hugsbord          #+#    #+#             */
/*   Updated: 2021/05/04 13:27:56 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/minishell.h"



int		ft_builtin_cd(char *cmd, char *arg)
{
	char	*old_pwd;
	char	*pwd;
	char	*pwd_ptr;
	char	**path_split;
	char	*home;

	home = ft_get_var("HOME");
//	path_split = ft_split(builtin, ' ');
	ft_putstr_fd(arg, 1);
//	ft_update_var(path_split[1], "");
/*	if (chdir(path_split[1]) == -1)
	{
		ft_putstr_fd("Path_error\n", 1);
		return (ERROR);
	}*/
	return (SUCCESS);
}
