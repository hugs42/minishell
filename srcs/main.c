/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 15:46:15 by hugsbord          #+#    #+#             */
/*   Updated: 2021/09/24 12:15:39 by hugsbord         ###   ########.fr       */
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

	ft_ctrl();
	while (42)
	{
		i = 0;
		data->input = readline("minishell-42$> ");
		data->old_ret = data->ret;
		data->ret = 0;
		if (ft_strlen(data->input) != 0)
			add_history(data->input);
		cmd = ft_split_input(data, data->input);
		if (cmd == NULL)
			ft_shell_loop(data, argv);
		if (cmd[0] != NULL && data->input != 0)
			cmd[0] = ft_lowercase(cmd[0]);
		else if (cmd[0] == NULL)
			cmd[0] = "\0";
//		if (ft_lexer == ERROR)
//			return (ERROR);
//		ft_strtrim(cmd[0], "\'");
//		ft_putstr_fd("@",1);
//		ft_putstr_fd(cmd[0], 1);
//		ft_putstr_fd("@\n",1);
		while (cmd[i] != NULL && ft_strlen(cmd[i]) != 0)
		{
			split_arg = ft_split(cmd[i], ' ');
//			ft_strtrim(split_arg[0], "\'");
//			ft_putstr_fd("@",1);
//			ft_putstr_fd(split_arg[i], 1);
//			ft_putstr_fd("@\n",1);
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

//	(void)argc;
//	(void)argv;
	status = 1;
//	ft_ctrl();
//	if (argc >= 3 && !ft_strncmp(argv[1], "-c", 3))
//	{
		ft_init_struct(&data);
		ft_init_env(envp);
//		ft_init_termcaps();
		ft_shell_loop(&data, argv[2]);
//	}
	return (0);
}
