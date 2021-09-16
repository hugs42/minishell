/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 08:48:31 by hugsbord          #+#    #+#             */
/*   Updated: 2021/09/16 18:03:33 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/minishell.h"

int		ft_check_quotes(char **commands, int open, int j)
{
	int		i;
	int		quotes;

	i = 0;
	quotes = 0;
	while (commands[i] != NULL)
	{
		if (ft_strchr(commands[i], '\''))
		{
			while (commands[i][j] != '\0')
			{
				if (commands[i][j] == '\'')
					quotes++;
				j++;
			}
		}
		i++;
	}
	return (0);
}

int		ft_check_dquotes(t_data *data, char **commands, int open, int j)
{
	int i;
	int dquotes;

	i = 0;
	dquotes = 0;
	open = 1;
	while (commands[i] != NULL)
	{
		if (ft_strchr(commands[i], '\"'))
		{
			while (commands[i][j] != '\0')
			{
				if (commands[i][j] == '\"')
					dquotes++;
				j++;
			}
		}
		i++;
	}
	return (0);
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
	j = ft_check_quotes(commands, open, j);
	j = ft_check_dquotes(data,commands, open, j);
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
	if (data->quote % 2 == 1)
	{
		ft_putstr_fd("minishell: unexpected EOf while looking for matching quotes\n", 2);
		return (NULL);
	}
	else
		ft_strtrim(commands[i], "\n");
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
