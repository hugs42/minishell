/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 10:03:10 by hugsbord          #+#    #+#             */
/*   Updated: 2021/06/10 07:38:01 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/minishell.h"

void	ft_exec_builtin(t_data *data, char *builtin)
{
	char	**split_cmd;

	split_cmd = ft_split(builtin, ' ');
	if (ft_strncmp(split_cmd[0], "cd", 2) == 0)
	{
		data->pwd->old_pwd = getcwd(NULL, 0);
		data->ret = ft_builtin_cd(data, split_cmd[1]);
	}
	else if (ft_strncmp(builtin, "pwd", 3) == 0)
		data-> ret = ft_builtin_pwd();
	else if (ft_strncmp(builtin, "env", 3) == 0)
		data->ret = ft_builtin_env();
	else if (ft_strncmp(builtin, "unset", 5) == 0)
		data->ret = ft_builtin_unset(split_cmd);
	else if (ft_strncmp(builtin, "exit", 3) == 0)
		ft_builtin_exit(data);
	else if (ft_strncmp(builtin, "echo", 4) == 0)
		data->ret = ft_builtin_echo(data, builtin);
	else if (ft_strncmp(builtin, "export", 6) == 0)
		data->ret = ft_builtin_export(data, builtin);
}

int		ft_exec_cmds(t_data *data, char **cmd)
{
	int		status;
	pid_t	pid_father;
	char	*run;
	int		exit_status;

	exit_status = 0;
	run = NULL;
	status = 0;
	pid_father = 0;
	pid_father = fork();
	run = ft_strdup(cmd[0]);
	if (pid_father == -1)
		return (-1);
	else if (pid_father > 0)
	{
		waitpid(pid_father, &status, 0);
		exit_status = WEXITSTATUS(status);
		kill(pid_father, SIGTERM);
	}
	else if (pid_father == 0)
	{
		if (execve(run, cmd, g_env) == -1)
			return (1);
	}
	data->ret = exit_status;
	return (SUCCESS);
}
