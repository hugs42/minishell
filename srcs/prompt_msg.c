/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_msg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 09:01:12 by hugsbord          #+#    #+#             */
/*   Updated: 2021/09/14 11:13:10 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/minishell.h"

void	ft_prompt_msg(t_data *data, char *input)
{
	char	buff[8000];
	char	*cwd;
	char	*user;
	int		ret;

	ret = data->ret;
	cwd = getcwd(buff, 4096);
	if ((ft_get_var("USER") != NULL))
		user = ft_strdup(ft_get_var("USER"));
	else
		user = ft_strdup("USER");
	ft_putstr_fd("\33[93m", 1);
	ft_putstr_fd(user, 1);
	ft_putstr_fd(":\33[96m ", 1);
	ft_putstr_fd(cwd, 1);
	ft_putstr_fd(" (", 1);
	ft_putnbr_fd(ret, 1);
	ft_putstr_fd(")", 1);
	ft_putstr_fd(" $> \33[0m", 1);
	ft_putstr_fd(input, 1);
	free(user);
}
