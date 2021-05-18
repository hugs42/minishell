/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 14:25:32 by hugsbord          #+#    #+#             */
/*   Updated: 2021/05/17 19:20:53 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/minishell.h"

int		ft_strjoin_quotes(char **cmd, int open_br, int close_br)
{
	ft_putstr_fd("§§", 1);
	cmd[open_br] = ft_strtrim(cmd[open_br], "\"");
	if (open_br != close_br)
		cmd[open_br] = ft_strjoin(cmd[open_br], cmd[close_br]);
	return (SUCCESS);
}

int		ft_is_quotes(char **cmd)
{
	int		i;
	int		j;
	int		br;
	int		open_br;
	int		close_br;

	i = 1;
	j = 0;
	br = 0;
	open_br = 0;
	close_br = 0;
	while (cmd[i] != NULL)
	{
//		ft_putstr_fd(cmd[i],1);
//		ft_putstr_fd("##\n", 1);
		while (cmd[i][j] != '\0')
		{
//			ft_putchar_fd(cmd[i][j], 1);
//			ft_putchar_fd('#', 1);
			if (cmd[i][j] == '\"')
			{
				br++;
				if (br % 2 == 1)
					open_br = i;
				else if (br % 2 == 0)
					close_br = i;
			}
			j++;
		}
		i++;
//		ft_putnbr_fd(br, 1);
//		ft_putchar_fd(' ',1);
//		ft_putnbr_fd(close_br, 1);
//		if (br > 0 && br % 2 == 0)// && open_br > 0 && close_br > 0)
//			ft_strjoin_brackets(cmd, open_br, close_br);
	}
//	if (br % 2 != 0)
//		return (ERROR);
//	else
//		ft_manage_brackets(cmd);
	return (SUCCESS);
}

int		ft_is_dollar(t_data *data, char **cmd, int i, int j)
{
	char	*tmp;

	tmp = NULL;
	if (cmd[i][j] == '$' && cmd[i][j + 1] == '?')
	{
		tmp = ft_strdup(cmd[i]);
		tmp = ft_substr(tmp, j + 2, ft_strlen(tmp));
		cmd[i] = ft_substr(cmd[i], 0, j);
		cmd[i] = ft_strjoin(cmd[i], ft_itoa(data->old_ret));
		if (tmp != NULL)
			cmd[i] = ft_strjoin(cmd[i], tmp);
	}
	else if (cmd[i][j] == '$' && cmd[i][j + 1] != '\0' && cmd[i][j + 1] != '='
	&& cmd[i][j + 1] != '%' && cmd[i][j + 1] != '^' && cmd[i][j + 1] != ','
	&& cmd[i][j + 1] != '.') 
	{
		tmp = ft_strdup(cmd[i]);
		tmp = ft_substr(tmp, j + 1, ft_strlen(tmp));
		cmd[i] = ft_substr(cmd[i], 0, j);
//		ft_putstr_fd("|", 1);
//		ft_putstr_fd(tmp, 1);
//		ft_putstr_fd("|", 1);
		if (ft_find_var(tmp) != -1)
		{
			cmd[i] = ft_strjoin(cmd[i], ft_get_var(tmp));
		}
//			ft_putstr_fd(ft_get_var(tmp), 1)ch
	}
	return (0);
}

int		ft_builtin_echo(t_data *data, char *builtin)
{
	int		i;
	int		j;
	int		br;
	int		count;
	char	**cmd;

	i = 1;
	j = 0;
	br = 0;
	count = 1;
	while (builtin[j] != '\0')
	{
		if (builtin[j] == '\"' || builtin[j] == '\'')
			br++;
		j++;
	}
	if (br == 0)
		cmd = ft_split(builtin, ' ');
	while (cmd[count])
		count++;
//	ft_putstr_fd("$$",1);
//	ft_putstr_fd(cmd[2],1);
//	ft_putstr_fd("$$\n",1);
	if (ft_strncmp(cmd[1], "-n", 2) == 0 && ft_strlen(cmd[1]) == 2)
	{
		data->echo_n = 1;
		count--;
		i++;
	}
	if (ft_is_quotes(cmd) == ERROR)
		return (ERROR);
	while (cmd[i] != NULL)
	{
		if (ft_strncmp(cmd[i], "#", 1) == 0)
			break ;
		j = 0;
		while (cmd[i][j] != '\0')
		{
			if (cmd[i][j] == '$')
			{
				ft_is_dollar(data, cmd, i, j);
			}
			j++;
		}
//		if (ft_strncmp(cmd[i], "$?", 2) == 0)
//		{
//			ft_putnbr_fd(data->old_ret, 1);
//			ft_substr(cmd[i], 0, 2);
//		}
		ft_putstr_fd(cmd[i], 1);
		if (count > 2 && cmd[i + 1] != NULL)
			ft_putchar_fd(' ', 1);
		i++;
	}
	if (data->echo_n == 0)
		ft_putchar_fd('\n', 1);
	data->echo_n = 0;
	return (SUCCESS);
}
