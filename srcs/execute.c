/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 10:03:10 by hugsbord          #+#    #+#             */
/*   Updated: 2021/09/24 19:53:49 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/minishell.h"

void	ft_exec_builtin(t_data *data, char *builtin)
{
	char	**split_cmd;

	if (data->is_q == 1)
		split_cmd = ft_split(builtin, '\"');
	else if (data->is_q == 0)
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

int		ft_check_q_spaces(t_data *data, char **cmd)
{
	int i = 0;
	int j = 0;
	int q = 0;
	int in_q = 0;

	while (cmd[i])
	{
		j = 0;
		data->is_q = 0;
		while (cmd[i][j])
		{
			if (cmd[i][j] == '\'' || cmd[i][j] == '\"')
			{
				data->is_q = 1;
				while (cmd[i][j] != '\'' || cmd[i][j] != '\"')
					j++;
			}
			j++;
		}
		if (data->is_q == 0)
			cmd[i] = ft_strtrim(cmd[i], " ");
		ft_putstr_fd(data->cmd[i], 1);
		ft_putchar_fd('\n',1);
		i++;
	}
	
	return (0);
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
//	ft_check_q_spaces(data, cmd);
//	int i = 0;
//	cmd = ft_split(cmd[0], ' ');
//	while (data->cmd[i])
//	{
//		ft_putchar_fd('H',1);
//		ft_putchar_fd('#',1);
//		ft_putstr_fd(data->cmd[i], 1);
//		ft_putchar_fd('\n',1);
//		i++;
//	}
//	if (data->is_q == 1)
//		cmd = ft_split(cmd[0], '\"');
//	else if (data->is_q == 0)
//		cmd = ft_split(cmd[0], ' ');
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

int		ft_execute(t_data *data, char **cmd, char **split_arg, int i)
{
	 if (ft_strncmp(cmd[i], "\0", 1) != 0)
	 {
//		cmd[0] = ft_strtrim(cmd[0], "\"");
//		cmd[0] = ft_strtrim(cmd[0], "\'");
//		ft_putstr_fd("%", 1);
//		ft_putstr_fd(cmd[0], 1);
//		ft_putstr_fd("%", 1);
		if (ft_is_builtin(cmd[i], data) == 1)
			ft_exec_builtin(data, cmd[i]);
		else if (ft_get_absolute_path(data, cmd) == 1)
		{
			ft_putstr_fd("OKK", 1);
//			cmd[0] = data->bin;
//			ft_putstr_fd("||", 1);
//			ft_putstr_fd(cmd[1], 1);
			ft_putstr_fd("||", 1);
			ft_exec_cmds(data, data->cmd);
		}
		else if ((ft_strncmp(cmd[i], "history -c", 10) == 0)
			&& (ft_strlen(cmd[i]) == 10))
			rl_clear_history();
		else
		{
			ft_putstr_fd("minishell: command not found: ", 2);
			ft_putstr_fd(cmd[i], 2);
			ft_putchar_fd('\n', 2);
			data->ret = (127);
		}
	}
	return (0);
}
