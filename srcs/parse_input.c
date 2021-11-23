/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 08:48:31 by hugsbord          #+#    #+#             */
/*   Updated: 2021/11/23 13:06:11 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/minishell.h"

int		ft_check_quotes(t_data *data, char *input)
{
	int i;
	int	q;
	int start;
	int end;

	i = 0;
	q = 0;
	start = 0;
	data->start = 0;
	data->end = 0;
	data->is_q = 0;
	while (input[i] != '\0')
	{
		if (input[i] == '\'' || input[i] == '\"')
		{
			data->is_q = 1;
			if (input[i] == '\'')
			{
				q++;
				data->in_quote = 1;
				i++;
				while (input[i] != '\'' && input[i] != '\0')
					i++;
				if (input[i] == '\'')
				{
					data->end = i;
					q++;
					data->in_quote = 0;
				}
			}
			else if (input[i] == '\"')
			{
				q++;
				i++;
				data->in_quote = 1;
				while (input[i] != '\"' && input[i] != '\0')
					i++;
				if (input[i] == '\"')
				{
						q++;
						data->in_quote = 0;
				}
			}
		}
		i++;
	}
	if (q % 2 == 1)
	{
		ft_putstr_fd("minishell: unexpected EOF while looking for matching quotes\n", 2);
		return (-1);
	}
	return (i);
}

char	**ft_split_input(t_data *data, char *input)
{
	char	**commands;
	char	*tmp;
	int		i;
	int		j;
	int		quotes;
	int		d_quotes;
	int open;

	i = 0;
	j = 0;
	quotes = 0;
	commands = NULL;
	tmp = NULL;
	commands = ft_split(input, '\n');
	open = 0;
	if (ft_check_quotes(data, input) == -1)
		return (NULL);
//	commands = ft_split(input, ';');
//	ft_strtrim(commands[i], ";");
	i = 0;
	while (commands[i] != NULL)
	{
//		ft_putstr_fd(">>>", 1);
//		ft_putstr_fd(commands[i], 1);
//		ft_putstr_fd("\n", 1);
//		tmp = ft_strtrim(commands[i], "\"");
		tmp = ft_strtrim(commands[i], "+");
		free(commands[i]);
		commands[i] = ft_strdup(tmp);
//		ft_putstr_fd("#",1);
//		ft_putstr_fd(commands[i],1);
//		ft_putstr_fd("#\n",1);
		free(tmp);
		i++;
	}
	commands[i] = NULL;
	return (commands);
}

int		ft_is_builtin(char *cmd, t_data *data)
{
	int		i;
	char	**split_cmd;

	i = 0;
	if (data->is_q == 0)
		split_cmd = ft_split(cmd, ' ');
	else if (data->is_q == 1)
		split_cmd = ft_split(cmd, '\"');
	char *builtin[] = {"pwd", "cd", "env", "export", "unset", "echo", "exit", NULL};
	while (builtin[i])
	{
		if (ft_strncmp(builtin[i], split_cmd[0], ft_strlen(builtin[i])) == 0)
		{
			if ((ft_strlen(builtin[i]) == ft_strlen(split_cmd[0])))
			{
				ft_putstr_fd("OK",1);
				return (1);
			}
		}
		i++;
	}
	return (0);
}

int		ft_is_token(char c)
{
	if (c == '"' || c == '\\')
		return (1);
	return (0);
}

int		ft_strlen_arg_token(char *str, char c)
{
	int i;

	i = 0;
	while (str[i] && str[i] != c)
	{
		if (str[i] == '\\' && ft_is_token(str[i + 1]))
			i++;
		i++;
	}
	return (i);
}

static int	ft_strlen_arg(char *str)
{
	int i;

	i = 0;
	if (str[i] == '<' || str[i] == '>' || str[i] == '=' || str[i] == '|')
	{
		if (str[i] == '>' && str[i + 1] == '>')
			i += 2;
		else
			i += 1;
	}
	else
	{
		while (str[i] && !ft_isspace(str[i]) && str[i] != '<' &&
		str[i] != '>' && str[i] != '=' && str[i] != '|')
		{
			if (str[i] == '\'' || str[i] == '"')
			{
				i++;
				i += ft_strlen_arg_token(str + i, str[i - 1]);
				if (!(str[i]))
					return (i);
			}
			i++;
		}
		if (str[i] == '=')
			i++;
	}
	return (i);
}

int	ft_count_args(char *str)
{
	int	i;
	int count;

	i = 0;
	count = 0;
	while (ft_isspace(str[i]))
		i++;
	while (str[i])
	{
		while (ft_isspace(str[i]))
			i++;
		count++;
		i += ft_strlen_arg(str);
		while (ft_isspace(str[i]))
			i++;
	}
	return (count);
}

int		ft_parse_input(t_data *data, char **cmd, char *argv)
{
	int	i;
	int	j;
	char	**commands;

	i = 0;
	j = 0;
	int cc = 0;
//	cmd = ft_split(data->input, '\n');
	if (cmd == NULL)
		ft_shell_loop(data, argv);
	if (cmd[0] != NULL && data->input != 0)
		cmd[0] = ft_lowercase(cmd[0]);
	else if (cmd[0] == NULL)
		cmd[0] = "\0";
//	ft_putstr_fd(cmd[0], 1);
//	ft_putstr_fd("<<\n", 1);
	while (cmd[i])
	{
		cc = 0;
		j = 0;
		cc = ft_count_args(cmd[i]);
		ft_putstr_fd("->->->", 1);
		ft_putnbr_fd(cc, 1);
		ft_putstr_fd("\n", 1);
		while (cmd[i][j])
		{
			if (cmd[i][j] == '|')
			{
//				cmd = ft_split(cmd[i], '|');
			}
			else if (cmd[i][j] == '<' || cmd[i][j] == '>')
			{
				
			}
			j++;
		}
		i++;
	}
//	ft_insert_elem(data, cmd);
	return (0);
}
