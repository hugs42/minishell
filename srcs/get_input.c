/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 19:54:40 by hugsbord          #+#    #+#             */
/*   Updated: 2021/04/28 19:59:52 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/minishell.h"

char	*get_input(void)
{
	char	*input;

	if (get_next_line(0, &input) < 1)
		ft_error(LEAVE);
	return (input);
}
