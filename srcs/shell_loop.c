/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 11:11:44 by hugsbord          #+#    #+#             */
/*   Updated: 2021/11/18 11:13:12 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/minishell.h"

int	ft_shell_loop(t_data *data, char *argv)
{
	int		i;
	char	**cmd = NULL;
	char	**split_arg = NULL;
	char	*str;

	ft_ctrl();
	while (42)
	{
		i = 0;
		data->input = readline("\033[1;36mminishell-42$>\033[0m ");
		data->old_ret = data->ret;
		data->ret = 0;
		if (ft_strlen(data->input) != 0)
			add_history(data->input);
		cmd = ft_split_input(data, data->input);
		ft_parse_input(data, cmd, argv);
		while (cmd[i] != NULL && ft_strlen(cmd[i]) != 0)
		{
			split_arg = ft_split(cmd[i], ' ');
			ft_execute(data, cmd, split_arg, i);
			i++;
		}
		cmd = NULL;
		data->input = NULL;
	}
	free(data->input);
	return (0);
}
