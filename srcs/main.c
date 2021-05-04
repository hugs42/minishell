/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 15:46:15 by hugsbord          #+#    #+#             */
/*   Updated: 2021/05/04 11:41:38 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/minishell.h"

char	*ft_get_var(char *var)
{
	int		i;
	int		j;
	int		len;
	char	**tmp;

	i = 0;
	len = ft_strlen(var);
	while (g_env[i])
	{
		tmp = ft_split(g_env[i], '=');
		if (ft_strncmp(tmp[0], var, len) == 0)
			return (tmp[1]);
		i++;
	}
	return (var);
}

char	**ft_split_input(char *input)
{
	char	**commands;
	char	*tmp;
	int		i;

	i = 0;
	commands = ft_split(input, ';');
	while (commands[i] != NULL)
	{
		tmp = ft_strtrim(commands[i], " ");
		free(commands[i]);
		commands[i] = ft_strdup(tmp);
		free(tmp);
		i++;
	}
	return (commands);
}

int		ft_is_builtin(char *cmd)
{
	int i;

	i = 0;
	char *valid_cmd[] = {"pwd", "cd", "env", "ls", "echo", "exit" , NULL};
	while (valid_cmd[i])
	{
		if (ft_strncmp(valid_cmd[i], cmd, ft_strlen(valid_cmd[i])) == 0)
		{
			if ((ft_strlen(valid_cmd[i]) == ft_strlen(cmd)))
				return (SUCCESS);
		}
		i++;
	}
	return (0);
}

int		ft_shell_loop(t_data *data)
{
	int		i;
	char	**cmd = NULL;

	ft_prompt_msg(data->input);
	while (get_next_line(0, &data->input) > 0)
	{
		i = 0;
		cmd = ft_split_input(data->input);
		if (cmd[0] == NULL)
			cmd[0] = "\0";
		while (cmd[i])
		{

			if (ft_is_builtin(cmd[i]) == SUCCESS)
				ft_exec_builtin(cmd[i]);
			else if (ft_strncmp(cmd[i], "\0", 1) != 0)
			{
				if (ft_get_absolute_path(data, cmd) == SUCCESS)
				{
					ft_exec_cmds(cmd);
				}
			}
			else if (ft_strncmp(cmd[i], "\0", 1) != 0)
			{
				ft_putstr_fd("minishell: command not found: ", 1);
				ft_putstr_fd(cmd[i], 1);
				ft_putchar_fd('\n', 1);
			}
			i++;
		}
		cmd = NULL;
		data->input = NULL;
		ft_prompt_msg(data->input);
//		ft_free_array(cmd);
	}
	free(data->input);
	return (0);
}

int		main(int argc, char **argv, char **envp)
{
	t_data		data;
	int			status;
	char		*input;

	(void)argc;
	(void)argv;
	status = 1;
	ft_init_struct(&data);
	ft_init_env(envp);
	ft_shell_loop(&data);
/*	while (get_next_line(0, &input) > 0)
	{
		ft_putstr_fd(input, 1);
		ft_parse_input(input);
	}
	free(input);
	while (42)
	{
		ft_prompt_msg();
		signal(SIGINT, ft_signal_handler);
	}*/
	return (0);
}
