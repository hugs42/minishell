/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_msg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 09:01:12 by hugsbord          #+#    #+#             */
/*   Updated: 2021/04/29 12:43:28 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/minishell.h"

void	ft_prompt_msg(char *input)
{
	char	buff[4096 + 1];
	char	*cwd_tmp;
	char	*cwd;

	cwd_tmp = getcwd(buff, 4096);
	ft_putstr_fd(cwd_tmp, 1);
	ft_putstr_fd(" $> ", 1);
	ft_putstr_fd(input, 1);
}
