/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcaps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 12:28:09 by hugsbord          #+#    #+#             */
/*   Updated: 2021/05/26 15:20:56 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/minishell.h"

int		ft_init_termcaps(void)
{
	int		ret;
	char	*term_type;

	term_type = ft_get_var("TERM");
	if (term_type == NULL)
		term_type = ft_strdup("xterm");
	ret = tgetent(NULL, term_type);
	if (ret == -1)
		ft_errors(ERR_TERM_DB);
	else if (ret == 0)
		ft_errors(ERR_TERM_TYPE);
	return (SUCCESS);
}
