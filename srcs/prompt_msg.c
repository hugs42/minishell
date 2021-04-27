/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_msg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 09:01:12 by hugsbord          #+#    #+#             */
/*   Updated: 2021/04/27 09:15:50 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/minishell.h"

int		ft_prompt_msg(void)
{
	char	buff[4096 + 1];
	char	*cwd_tmp;
	char	*cwd;

	cwd_tmp = getcwd(buff, 4096);
	ft_putstr_fd(cwd_tmp, 1);
	return (0);
}
