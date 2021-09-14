/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 08:33:37 by hugsbord          #+#    #+#             */
/*   Updated: 2021/05/18 12:54:43 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/minishell.h"

int		ft_errors(int error)
{
	if (error == ERR_TERM_DB)
		ft_putstr_fd("Could not access to the termcap database..\n", 2);
	else if (error == ERR_TERM_TYPE)
		ft_putstr_fd("Terminal type is not correctly defined in termcap database.\n", 2);
	return (0);
}
