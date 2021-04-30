/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 15:46:15 by hugsbord          #+#    #+#             */
/*   Updated: 2021/04/30 09:24:43 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/minishell.h"

void		free_array(char **array)
{
	int i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		array[i] = NULL;
		i++;
	}
	free(array);
	array = NULL;
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


int		ft_exec(char **cmd)
{
	int		status;
	pid_t	pid;

	status = 0;
	pid = 0;
	pid = fork();
	if (pid == -1)
		return (-1);
	else if (pid > 0)
	{
		waitpid(pid, &status, 0);
		kill(pid, SIGTERM);
	}
	else
	{
		if (execve(cmd[0], cmd, NULL) == -1)
			return (-1);
	}
	return (SUCCESS);
}

int		ft_is_cmd(char *cmd)
{
	int i;

	i = 0;
	char *valid_cmd[] = {"pwd", "cd", "env", "ls", NULL};
	while (valid_cmd[i])
	{
		if (ft_strncmp(valid_cmd[i], cmd, ft_strlen(valid_cmd[i])))
			return (SUCCESS);
		i++;
	}
	return (0);
}

int		ft_shell_loop(void)
{
	char *input = NULL;
	char **cmd = NULL;

	ft_prompt_msg(input);
	while (get_next_line(0, &input) > 0)
	{
		cmd = ft_split_input(input);
		if (cmd[0] == NULL)
			cmd[0] = "\0";
//		printf("%s\n", cmd[0]);
		if (ft_is_cmd(cmd[0]))
		{
			ft_exec(cmd);
//			ft_putchar_fd(' ',1);
		}
//		ft_putchar_fd('\n', 1);
//		ft_parse_input(input);
		input = NULL;
		ft_prompt_msg(input);
//		free_array(cmd);
	}
	free(input);
	return (0);
}

int		main(int argc, char **argv, char **env)
{
	int		status;
	char	*input;

	(void)argc;
	(void)argv;
	status = 1;
	ft_shell_loop();
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
