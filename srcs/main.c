/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 15:46:15 by hugsbord          #+#    #+#             */
/*   Updated: 2021/04/27 09:16:01 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/minishell.h"

int		main(int argc, char **argv, char **env)
{
	ft_prompt_msg();
	while (42)
	{
//		get_next_line(0);
		ft_putstr_fd("", 1);
	}
	return (0);
}
