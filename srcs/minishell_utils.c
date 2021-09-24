/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 10:07:07 by hugsbord          #+#    #+#             */
/*   Updated: 2021/09/21 11:37:26 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/minishell.h"

char	*ft_lowercase(char *cmd)
{
	int		i;

	i = 0;
	while (cmd[i] != '\0')
	{
		ft_tolower(cmd[i]);
		i++;
	}
	return (cmd);
}

void	ft_free_array(char **array)
{
	int		i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		array[i] = NULL;
		i++;
	}
	free(array);
	array = NULL;
}
