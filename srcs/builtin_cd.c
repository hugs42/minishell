/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 09:58:39 by hugsbord          #+#    #+#             */
/*   Updated: 2021/05/04 09:59:38 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/minishell.h"

int		ft_builtin_cd(char *path)
{
	char	*old_pwd;
	char	*pwd;
	char	*pwd_ptr;

	if (chdir(path) == -1)
	{
		ft_putstr_fd("Path_error\n", 1);
		return (ERROR);
	}
	return (SUCCESS);
}
