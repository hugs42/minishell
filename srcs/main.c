/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 15:46:15 by hugsbord          #+#    #+#             */
/*   Updated: 2021/09/15 10:46:11 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/minishell.h"

int		g_sig;

int	ft_shell_loop(t_data *data, char *argv)
{
	int		i;
	char	**cmd = NULL;
	char	**split_arg = NULL;
	char	*str;

	str = ft_prompt_msg2(data);
	while (42)
	{
		str = ft_prompt_msg2(data);
		data->input = readline(str);
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
			ft_execute(data, cmd, split_arg, i);
			i++;
		}
		cmd = NULL;
		data->input = NULL;
	}
	free(data->input);
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_data		data;
	int			status;
	char		*input;

	(void)argc;
	(void)argv;
	status = 1;
	signal(SIGINT, ft_signal_handler);
	signal(SIGQUIT, ft_signal_handler);
	ft_init_struct(&data);
	ft_init_env(envp);
	ft_init_termcaps();
	ft_shell_loop(&data, argv[2]);
	return (0);
}
