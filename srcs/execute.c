/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 10:03:10 by hugsbord          #+#    #+#             */
/*   Updated: 2021/05/04 10:05:33 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/minishell.h"

void	ft_exec_builtin(char *builtin)
{
	if (ft_strncmp(builtin, "cd", 2) == 0)
	{
		ft_builtin_cd(builtin);
	}
	else if (ft_strncmp(builtin, "pwd", 3) == 0)
	{
		ft_builtin_pwd();
	}
}

int		ft_exec_cmds(char **cmd)
{
	int		status;
	pid_t	pid_father;

	status = 0;
	pid_father = 0;
	pid_father = fork();
	if (pid_father == -1)
		return (-1);
	else if (pid_father > 0)
	{
		waitpid(pid_father, &status, 0);
		kill(pid_father, SIGTERM);
	}
	else if (pid_father == 0)
	{
		if (execve(cmd[0], cmd, NULL) == -1)
			return (-1);
	}
	return (SUCCESS);
}
