/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 15:46:46 by hugsbord          #+#    #+#             */
/*   Updated: 2021/11/19 10:42:04 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/stat.h>
# include <signal.h>
# include <fcntl.h>
# include <term.h>
# include <termios.h>
# include <curses.h>
# include "./../libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/time.h>
# include <sys/resource.h>
# include <dirent.h>
# include <string.h>
# include <errno.h>
# include <sys/ioctl.h>
# include <readline/readline.h>
# include <readline/history.h>

# define SUCCESS 0
# define ERROR -1
# define LEAVE -2
# define ERR_TERM_DB -20
# define ERR_TERM_TYPE -21

int			g_sig;

typedef struct s_cmd_e	t_cmd_e;

typedef struct		s_pwd
{
	char			*pwd;
	char			*old_pwd;
}					t_pwd;

typedef struct		s_cmd
{
	t_cmd_e			*first;
}					t_cmd;

struct				s_cmd_e
{
	char			*cmd;
	int				pipe;
	int				redir;
	int				quotes;
	int				dquotes;
	int				ret;
	t_cmd_e			*next;
};

typedef struct		s_data
{
	t_pwd			*pwd;
	t_cmd			*cmd_list;
	int				i;
	int				is_file;
	int				echo_n;
	int				ret;
	int				old_ret;
	char			*input;
	char			*path;
	char			**path_split;
	char			**cmd;
	char			**args;
	char			*bin;
	int				is_q;
	int				quote;
	int				in_quote;
	int				start;
	int				end;
}					t_data;

char				**g_env;

char	*ft_get_input(void);
void	ft_free_array(char **array);
int		ft_error(int error);
int		ft_parse_input(t_data *data, char **cmd, char *argv);
int		ft_builtin_cd(t_data *data, char *path);
int		ft_builtin_pwd(void);
void	ft_signal_handler(int signal);
char	*ft_get_var(char *var);
int		ft_get_absolute_path(t_data *data, char **cmd);
int		ft_is_builtin(char *cmd, t_data *data);
char	**ft_split_input(t_data *data, char *input);
int		ft_shell_loop(t_data *data, char *argv);
int		ft_execute(t_data *data, char **cmd, char **split_arg, int i);
void	ft_exec_builtin(t_data *data, char *builtin);
int		ft_exec_cmds(t_data *data, char **cmd);
void	ft_free_array(char **array);
int		ft_init_env(char **envp);
int		ft_init_struct(t_data *data);
t_cmd	*ft_init_cmd(void);
t_cmd_e	*ft_init_cmd_elem(t_cmd *cmd);
int		ft_builtin_env(void);
int		ft_find_var(char *var);
void	ft_update_var(char *key, char *value);
void	ft_builtin_exit(t_data *data);
int		ft_builtin_unset(char **key);
char	**ft_realloc_env(int var_nb);
int		ft_builtin_echo(t_data *data, char *cmd);
int		ft_builtin_export(t_data *data, char *cmd);
int		ft_init_termcaps(void);
int		ft_ctrl(void);
int		ft_errors(int error);
void	rl_replace_line(const char *s, int n);
void	rl_clear_history(void);
char	*ft_lowercase(char *cmd);
int		ft_check_q_spaces(t_data *data, char **cmd);
t_cmd_e		*ft_insert_elem(t_data *data, char **cmd);
#endif
