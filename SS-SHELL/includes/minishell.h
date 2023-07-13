/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sean <sean@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 16:15:49 by sean              #+#    #+#             */
/*   Updated: 2022/03/19 22:45:22 by sean             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define DEL 127
# define LEFT 4479771
# define RIGHT 4414235
# define K_UP 4283163
# define DOWN 4348699

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
# include <fcntl.h>
# include <limits.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <sys/ioctl.h>
# include <dirent.h>
# include <termcap.h>
# include <term.h>
# include <curses.h>
# include <termios.h>
# include <errno.h>
# include <string.h>
# include "../libft/libft.h"
# include "command.h"

typedef struct s_glob
{
	int		read_size;
	int		exit_status;
	int		cflag;
	int		quote;
	char	**envp;
}				t_glob;

typedef struct s_exec
{
	char	**env_path;
	char	**split_cmd;
	char	*path;
}				t_exec;

typedef struct	s_string
{
	char	*one;
	char	*two;
	char	*three;
	char	*four;
	char	*five;
	char	*new;
	char	*mid;
}				t_string;

typedef struct s_pipe
{
	char		*ori_cmd_line;
	char		*cur_cmd;
	int			flag;
	int			old_flag;
	int			*fds;
	int			*old_fds;
	int			pipe_count;
}				t_pipe;

typedef struct s_cmd
{
	char	*cmd;
	char	*redir;
	char	*next_redir;
	char	*file;
	char	*cur_file;
	int		std_in;
	int		std_out;
	int		pipe_count;
	char	*heredoc_str;
	char	**cmd_arg;
}				t_cmd;

typedef struct s_input
{
	int			cflag;
	int			buf;
	char		*tmp;
	char		*input;
	int			nidx;
	char		*his_input;
	t_list		*log;
}				t_input;

typedef struct s_term
{
	struct termios	term1;
	struct termios	ori_term;
	char			*cm;
	char			*ce;
	int				r;
	int				c;
}				t_term;

typedef struct s_data
{
	char		**cmd;
	char		**envp;
	t_term		term;
	t_input		input;
}				t_data;

/******************************************************************************/
/**                                signal.c                                  **/
/******************************************************************************/

void	signal_handler(int signo);
void	signal_handler2(int signo);
int		ctrl_c_func(t_input *input);
void	ctrl_d_func(char *input, struct termios *ori_term);

/******************************************************************************/
/**                                 term.c                                   **/
/******************************************************************************/

int		nbr_length(int n);
void	get_cursor_position(int *col, int *row);
int		putchar_tc(int tc);
void	delete_end(char **input);
void	term_init(struct termios *term1, struct termios *ori_term);

/******************************************************************************/
/**                               cmd_utils.c                                **/
/******************************************************************************/

int		builtin_cmd_check(t_data *data, char *cmd);
int		**fds_set(int row);
void	set_pipe_fds(int i, int stack, t_pipe *pip, int **fds);
void	cmd_init(char ***cmd);

/******************************************************************************/
/**                              utils_string.c                              **/
/******************************************************************************/

int		ft_sstrlen(char **strstr);
char	**ft_sstrdup(char **origin);
char	**ft_addonestring(char **origin, char *addline);

/******************************************************************************/
/**                              heredoc.c                                   **/
/******************************************************************************/

void	ft_here_echo(void);
void	do_here(char *cur_cmd, t_cmd *cmd);

/******************************************************************************/
/**                                 cmd1.c                                   **/
/******************************************************************************/

int		choose_process(int size, char *cmd);
void	execute(t_data *data, t_pipe *pip, int row);
char	**ft_pipe_split(char *cmd);
void	p_func(char **cmd_split, char *cmd_line, int **fds, t_data *data);
void	handle_process(char *cmd_split, int **fds, t_data *data);
void	cmd_handler(char **cmd_split, char *cmd_line, t_data *data);

/******************************************************************************/
/**                             ft_pipe_split.c                              **/
/******************************************************************************/

char	**ft_pipe_split(char *cmd);
void	ft_pipe_split2(char *cmd, int *i, int *start, char ***split_cmd);

/******************************************************************************/
/**                                utils.c	                                 **/
/******************************************************************************/

void	dfree(char **str);
void	difree(int **darr);
int		dlen(char **darr);
void	prompt(int flag);

/******************************************************************************/
/**                                input.c                                   **/
/******************************************************************************/

char	*print_history(t_term *term, t_input *input);
int		input_handler(t_input *input);
void	case_not_newline(t_input *input, char *tmp);
int		key_else(t_data *data, t_input *input);
char	*input_recive(t_data *data);

/******************************************************************************/
/**                                pipe.c                                    **/
/******************************************************************************/

void	c_pipe(t_pipe *pip);
void	p_pipe(int *old_fds, int *fds);

/******************************************************************************/
/**                              execute.c                                   **/
/******************************************************************************/

void	print_error(char *message, int code, t_cmd *cmd);
void	do_execute(t_cmd *cmd, t_exec *exec, t_data *data, int process);
void	execute_cmd(t_data *data, t_cmd *cmd, int process);
void	execute_input(t_data *data, t_pipe *pipe, int process);

/******************************************************************************/
/**                           execute_utils.c                                **/
/******************************************************************************/

int		make_path2(t_exec **exec);
int		make_path(t_exec *exec, t_cmd *cmd);
void	make_token2(t_cmd **cmd, char *input, int i, int j);
int		make_token(t_cmd *cmd, char *input, int flag);
char	**get_argv(char **split, char *file);

/******************************************************************************/
/**                           exceute_check.c                                **/
/******************************************************************************/

void	redirection_in(t_cmd *cmd);
void	redirection_out(t_cmd *cmd);
int		redirection_check2(t_cmd *cmd, char *input, int i);
int		redirection_heredoc(char *cur_cmd, t_cmd *cmd);
int		redirection_check(char *cur_cmd, t_cmd *cmd);

/******************************************************************************/
/**                              quote.c                                     **/
/******************************************************************************/

int		single_quotes(char **new_input, char *input, int i, t_cmd *cmd);
char	*handle_quotes3(char **new_input);
char	*double_quotes2(char *tmp, t_cmd *cmd);
int		double_quotes(char **new_input, char *input, int i, t_cmd *cmd);
char	*handle_quotes2(char *input, t_cmd *cmd);
char	*handle_quotes(char *input, t_cmd *cmd, int process);

/******************************************************************************/
/**                              quote2.c                                    **/
/******************************************************************************/

int		not_quotes(char **new_input, char *input, int i, t_cmd *cmd);
char	*not_quotes2(int i, char *input, char **new_input, t_cmd *cmd);
char	*double_quotes2(char *tmp, t_cmd *cmd);
int		double_quotes(char **new_input, char *input, int i, t_cmd *cmd);

/******************************************************************************/
/**                             dollar.c                                     **/
/******************************************************************************/

char	*ft_getenv(char *env);
char	*ft_getenv2(char *env);
char	*dollar(int i, char *input, t_cmd *cmd);

/******************************************************************************/
/**                            ft_echo.c                                     **/
/******************************************************************************/

void	echo_option(char **split, int *i, int *option);
void	ft_echo(t_cmd *cmd, t_exec exec, t_data *data);

/******************************************************************************/
/**                             ft_pwd.c                                     **/
/******************************************************************************/

void	ft_pwd(t_cmd *cmd, t_exec exec, t_data *data);

/******************************************************************************/
/**                             ft_cd.c                                      **/
/******************************************************************************/

void	ft_cd(t_cmd *cmd, char *path, int process);

/******************************************************************************/
/**                             ft_env.c                                     **/
/******************************************************************************/

void	ft_env(t_data *data);

/******************************************************************************/
/**                            ft_exit.c                                     **/
/******************************************************************************/

int		digit_check(char *cmd, int size, int process);
void	over_two_arg(char *cmd, int size, int process);
void	ft_exit(char **cmd, t_data *data, int process);

/******************************************************************************/
/**                           ft_export.c	                                 **/
/******************************************************************************/

int		check_alnum_newkey(t_cmd *cmd, char *new, char **new_key, int *new_len);
void	free_and_error(t_cmd *cmd, char *new);
int		deal_export(t_cmd *cmd, char *new);
void	print_sorted_env(char **sorted_env);
void	b_export_noarg(void);
int		ft_export_split2(int *i, t_cmd *cmd, int *start, char ***split_cmd);
void	ft_export_split(t_cmd *cmd, char ***split_cmd);
void	ft_export(t_cmd *cmd);

/******************************************************************************/
/**                            ft_unset.c                                    **/
/******************************************************************************/

int		find_remove_str(char **origin, char *remove, int len);
char	**ft_removeonestring(char **origin, char *remove, int origin_len);
int		check_alnum_remove(char *remove);
void	ft_unset(t_cmd *cmd, t_data *data);

/******************************************************************************/
/**                         execute_utils2.c                                 **/
/******************************************************************************/

void	exec_cmd_init(t_cmd *cmd, t_pipe *pip);
void	exec_init(t_exec *exec, t_cmd *cmd);
int		quote_detec_loop(char *input, char delimeter, int i);

/******************************************************************************/
/**                              main.c                                      **/
/******************************************************************************/

void	make_log(t_input *input, char *cmd_line);
void	shell_loop(t_data *data);
void	determine_prompt(void);
int		main(int ac, char **av, char **env);

#endif
