/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 15:46:15 by hugsbord          #+#    #+#             */
/*   Updated: 2021/11/18 11:13:35 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/minishell.h"

int		g_sig;

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
