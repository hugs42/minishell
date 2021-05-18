/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 15:46:15 by hugsbord          #+#    #+#             */
/*   Updated: 2021/05/18 12:14:55 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/minishell.h"

char	**ft_split_input(char *input)
{
	char	**commands;
	char	*tmp;
	int		i;
	int		j;
	int		quotes;

	i = 0;
	j = 0;
	quotes = 0;
	commands = NULL;
	tmp = NULL;
	commands = ft_split(input, ';');
	while (commands[i] != NULL)
	{
		if (ft_strchr(commands[i], '\"'))
		{
			while (commands[i][j] != '\0')
			{
				if (commands[i][j] == '\"')
					quotes++;
				j++;
			}
		}
		i++;
	}
	if (quotes % 2 == 1)
	{
		ft_putstr_fd("minishell: unexpected EOf while looking for matching quotes\n", 2);
		return (NULL);
	}
	else
	{
		ft_strtrim(commands[i], "\n");
	}
	i = 0;
	while (commands[i] != NULL)
	{
		tmp = ft_strtrim(commands[i], " ");
		free(commands[i]);
		commands[i] = ft_strdup(tmp);
		free(tmp);
		i++;
	}
	commands[i] = NULL;
	return (commands);
}

int		ft_is_builtin(char *cmd)
{
	int		i;
	char	**split_cmd;

	i = 0;
	split_cmd = ft_split(cmd, ' ');
	char *builtin[] = {"pwd", "cd", "env", "export", "unset", "echo", "exit", NULL};
	while (builtin[i])
	{
		if (ft_strncmp(builtin[i], split_cmd[0], ft_strlen(builtin[i])) == 0)
		{
			if ((ft_strlen(builtin[i]) == ft_strlen(split_cmd[0])))
				return (1);
		}
		i++;
	}
	return (0);
}

char	*ft_lowercase(char *cmd)
{
	int		i;

	i = 0;
	while (cmd[i] != '\0')
	{
		ft_tolower(cmd[i]);
		i++;
	}
	return (cmd);
}

int		ft_shell_loop(t_data *data, char *argv)
{
	int		i;
	int		ret_term;
	char	*term_type;
	char	**cmd = NULL;
	char	**split_arg = NULL;

	ft_prompt_msg(data, data->input);
	term_type = ft_get_var("TERM");
	ret_term = tgetent(NULL, term_type);
	ft_putstr_fd(term_type, 1);
	while (get_next_line(0, &data->input) > 0)
	{
		i = 0;
		data->old_ret = data->ret;
		data->ret = 0;
		cmd = ft_split_input(data->input);
		if (cmd[0] != NULL)
			cmd[0] = ft_lowercase(cmd[0]);
		if (cmd[0] == NULL)
			cmd[0] = "\0";
		while (cmd[i] != NULL && ft_strlen(cmd[i]) != 0)
		{
			split_arg = ft_split(cmd[i], ' ');
			 if (ft_strncmp(cmd[i], "\0", 1) != 0)
			 {
				if (ft_is_builtin(cmd[i]) == 1)
					ft_exec_builtin(data, cmd[i]);
				else if (ft_get_absolute_path(data, split_arg) == 1)
					ft_exec_cmds(data, split_arg);
				else
				{
					ft_putstr_fd("minishell: command not found: ", 2);
					ft_putstr_fd(cmd[i], 2);
					ft_putchar_fd('\n', 2);
					data->ret = (127);
				}
			}
			i++;
		}
		cmd = NULL;
		data->input = NULL;
		ft_prompt_msg(data, data->input);
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
	ft_shell_loop(&data, argv[2]);
	return (0);
}
