/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_msg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 09:01:12 by hugsbord          #+#    #+#             */
/*   Updated: 2021/09/15 01:07:46 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/minishell.h"

char	*ft_prompt_msg2(t_data *data)
{
	char buff[9000];
	int ret;
	char *str;
	char *user;
	char *cwd;

	str = "";
	ret = data->ret;
	cwd = getcwd(buff, 9000);
	if ((ft_get_var("USER") != NULL))
		user = ft_strdup(ft_get_var("USER"));
	else
		user = ft_strdup("USER");
	str = ft_strjoin(str, "\33[93m");
	str = ft_strjoin(str, user);
	str = ft_strjoin(str, ":\33[96m ");
	str = ft_strjoin(str, cwd);
	str = ft_strjoin(str, " (");
	str = ft_strjoin(str, ft_itoa(data->ret));
	str = ft_strjoin(str, ") ");
	str = ft_strjoin(str, "$> \33[0m");
	return (str);
}

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
