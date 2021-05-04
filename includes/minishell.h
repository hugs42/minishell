/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 15:46:46 by hugsbord          #+#    #+#             */
/*   Updated: 2021/05/04 14:39:00 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <signal.h>
#include "./../libft/libft.h"
#include "./get_next_line.h"

# define SUCCESS 1
# define ERROR -1
# define LEAVE -2

typedef struct		s_data
{
	int				i;
	int				is_file;
	char			*input;
	char			*path;
	char			**path_split;
	char			*bin;
}					t_data;

typedef struct		s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}					t_env;

char				**g_env;

void	ft_prompt_msg(char *input);
char	*ft_get_input(void);
void	ft_free_array(char **array);
int		ft_error(int error);
int		ft_parse_input(char *input);
int		ft_builtin_cd(char *cmd, char *arg);
int		ft_builtin_pwd(void);
void	ft_signal_handler(int signal);
char	*ft_get_var(char *var);
int		ft_get_absolute_path(t_data *data, char **cmd);
void	ft_exec_builtin(t_data *data, char *builtin);
int		ft_exec_cmds(char **cmd);
void	ft_free_array(char **array);
int		ft_init_env(char **envp);
int		ft_init_struct(t_data *data);
void	ft_builtin_env(void);
void	ft_update_var(char *key, char *value);
void	ft_builtin_exit(t_data *data);

#endif
