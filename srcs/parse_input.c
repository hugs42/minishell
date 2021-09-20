/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 08:48:31 by hugsbord          #+#    #+#             */
/*   Updated: 2021/09/20 18:18:35 by hugsbord         ###   ########.fr       */
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
	while (input[i] != '\0')
	{
		if (input[i] == '\'' || input[i] == '\"')
		{
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
//	ft_putstr_fd("|",1);
//	ft_putnbr_fd(q, 1);
//	ft_putstr_fd("|",1);
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
/*	while (commands[i] != NULL)
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
	}*/
//	if (data->quote % 2 == 1)
//	{
//		ft_putstr_fd("minishell: unexpected EOf while looking for matching quotes\n", 2);
//		return (NULL);
//	}
//	else
	ft_strtrim(commands[i], ";");
	i = 0;
	while (commands[i] != NULL)
	{
//		tmp = ft_strtrim(commands[i], "\"");
		tmp = ft_strtrim(commands[i], " ");
		free(commands[i]);
		commands[i] = ft_strdup(tmp);
//		ft_putstr_fd("#",1);
//		ft_putstr_fd(commands[i],1);
//		ft_putstr_fd("\n",1);
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

int		ft_parse_input(char *input)
{
	int		i;
	char	**commands;

	i = 0;
	while (input[i] != '\0')
	{
		if (ft_isspace(input[i]))
			i++;
		else
			commands = ft_split(input, ';');
		i++;
	}
//	printf("|%s|", *commands);
	return (0);
}
