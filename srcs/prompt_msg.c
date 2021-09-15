/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_msg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 09:01:12 by hugsbord          #+#    #+#             */
/*   Updated: 2021/09/15 14:13:41 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/minishell.h"

char	*ft_prompt_msg(t_data *data)
{
	int ret;
	char *str;
	char *user;
	char *cwd;

	str = "";
	ret = data->ret;
	if ((ft_get_var("USER") != NULL))
		user = ft_strdup(ft_get_var("USER"));
	else
		user = ft_strdup("USER");
	str = ft_strjoin(str, "\33[93m");
	str = ft_strjoin(str, user);
	str = ft_strjoin(str, ":\33[96m");
	str = ft_strjoin(str, "(");
	str = ft_strjoin(str, ft_itoa(data->ret));
	str = ft_strjoin(str, ") ");
	str = ft_strjoin(str, "$> \33[0m");
	return (str);
}
