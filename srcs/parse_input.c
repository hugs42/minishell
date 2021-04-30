/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 08:48:31 by hugsbord          #+#    #+#             */
/*   Updated: 2021/04/29 09:57:07 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/minishell.h"

int		ft_parse_input(char *input)
{
	int		i;
	char	**commands;

	i = 0;
	while (input[i] != '\0')
	{
		if (ft_isspace(input[i]))
			i++;
		else
			commands = ft_split(input, ';');
		i++;
	}
//	printf("|%s|", *commands);
	return (0);
}
