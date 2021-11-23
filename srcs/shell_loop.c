/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 11:11:44 by hugsbord          #+#    #+#             */
/*   Updated: 2021/11/19 15:57:17 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/minishell.h"

t_cmd_e		*ft_insert_elem(t_data *data, char **cmd)
{
	t_cmd_e	*new;
	t_cmd_e *tmp;
	char  **cmd_split;

	new = ft_calloc(1, sizeof(t_cmd_e));
//	cmd_split = ft_split(cmd[0], ' ');
//	new->cmd = ft_strdup(cmd_split[0]);
	tmp = data->cmd_list->first;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	return (new);
}

int	ft_shell_loop(t_data *data, char *argv)
{
	int		i;
	t_cmd	*cmd_list;
	char	**cmd = NULL;
	char	**split_arg = NULL;
	char	*str;

	ft_ctrl();
	while (42)
	{
		i = 0;
//		cmd_list = ft_init_cmd();
//		ft_init_cmd_elem(cmd_list);
//		data->cmd_list = cmd_list;
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
