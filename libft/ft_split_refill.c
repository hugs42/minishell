/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_refill.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 10:59:36 by hugsbord          #+#    #+#             */
/*   Updated: 2021/09/24 19:43:52 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_nb_words_2(char const *s, char c)
{
	size_t	counter;
	size_t	i;

	i = 0;
	counter = 0;
	while (i < ft_strlen(s))
	{
		if (i == 0 && s[i] != c)
			counter++;
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			counter++;
		i++;
	}
	return (counter);
}

static char		**ft_add_2(char const *s, char c, char **tab)
{
	size_t		i;
	size_t		start;
	size_t		index;
	int			count;

	index = 0;
	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			i++;
			count++;
		}
		else if (s[i] != c)
		{
			if (count % 2 == 1)
			{
				start = i - 1;
			}
			else
				start = i;
			while (s[i] && s[i] != c)
				i++;
			if (count % 2 == 1)
				tab[index] = ft_substr(s, start, i - start + 1);
			else
				tab[index] = ft_substr(s, start, i - start);
			index++;
			tab[index] = NULL;
		}
	}
	tab[index] = 0;
	return (tab);
}

char			**ft_realloc_tab(char **tab, int tab_nb)
{
	int		i;
	char	**new_tab = NULL;

	i = 0;
//	tab_nb = 30;
	ft_putnbr_fd(tab_nb, 1);
	new_tab = (char **)ft_calloc(tab_nb + 1, sizeof(char *));
	while (tab[i] && i < tab_nb)
	{
		new_tab[i] = ft_strdup(tab[i]);
		free(tab[i]);
		i++;
	}
	return (new_tab);
}

char			**ft_remove_empty(char **tab)
{
	int i;
	int j;
	int space;
	int tmp;
	int len = 0;

	i = 0;
	space = 0;
	tmp = 0;
	while(tab[len])
		len++;
	while (tab[i])
	{
		j = 0;
		space = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == ' ' || tab[i][j] == '\"')
			{
				space++;
			}
			j++;
		}
		if (space == j)
		{
			ft_putstr_fd("JACK",1);
			len--;
			tmp = i;
			free(tab[tmp]);
			tab[tmp] = NULL;
			while (tab[tmp + 1])
			{
				tab[tmp] = ft_strdup(tab[tmp + 1]);
				free(tab[tmp + 1]);
				tmp++;
			}
			tab[len] = NULL;
			free(tab[len]);
//			tab = ft_realloc_tab(tab, tmp);
		}
		i++;
//			tab = ft_realloc_tab(tab, i);
	}
	while (tab[i])
	{
		ft_putstr_fd("+++", 1);
		ft_putstr_fd(tab[i], 1);
		ft_putstr_fd("\n", 1);
		i++;
	}
	return (tab);
}

char			**ft_split_refill(char const *s, char c)
{
	char	**tab;
	char	*tmp;

	tmp = ft_strdup(s);
	if (s == NULL)
		return (NULL);
	if (!(tab = (char**)malloc(sizeof(char*) * (ft_nb_words_2(s, c) + 1))))
		return (NULL);
	ft_bzero(tab, (ft_nb_words_2(s, c) + 1));
	tab = ft_add_2(s, c, tab);
	tab = ft_remove_empty(tab);
	int i = 0;
	while (tab[i])
	{
//		ft_putstr_fd("+++", 1);
//		ft_putstr_fd(tab[i], 1);
//		ft_putstr_fd("\n", 1);
		i++;
	}
	return (tab);
}
