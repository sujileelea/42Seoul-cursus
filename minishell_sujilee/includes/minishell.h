/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 16:15:49 by okwon             #+#    #+#             */
/*   Updated: 2022/02/17 21:19:47 by sujilee          ###   ########.fr       */
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

typedef struct	s_glob
{
	char	*ret;
	int		curly_bracket;
}				t_glob;

typedef struct	s_exec
{
	char    **env_path;
	char    **argv;
	char    **split_cmd;
	char	*path;
}				t_exec;

typedef struct	s_cmd
{
	char	*cmd;
	char	*redir;
	char	*next_redir;
	char	*file;
	char	*cur_file;
	int		std_in;
	int		std_out;
}				t_cmd;

typedef struct	s_pipe
{
	char		*cur_cmd;
	int			flag;
	int			old_flag;
	int			*fds;
	int			*old_fds;
}				t_pipe;

// 터미널 입력을 위한 변수를 담은 구조체
typedef struct	s_input
{
	int			cflag;	// ctrl-c 여부. 0 : ctrl-c가 잡히지 않음. 1 : ctrl-c가 잡힘
	int			buf;
	char		*tmp;
	char		*input;
	int			nidx;	// 히스토리의 노드 인덱스
	t_list		*log;
}				t_input;

// 터미널에 대한 변수를 담은 구조체
typedef struct	s_term
{
	struct termios	term1;	// minishell에서 사용할 터미널
	struct termios	ori_term;	// 원래 터미널. minishell 종료 후 해당 터미널로 복귀
	char			*cm;	// 커서 위치 이동
	char			*ce;	// 터미널에서 현재 위치한 라인 삭제
	int				r;	// 터미널의 row 위치
	int				c;	// 터미널의 column 위치
}				t_term;

// 기본적인 데이터를 저장한 구조체
typedef struct	s_data
{
	char		**cmd;	// minishell에서 사용할 cmd의 이름을 저장함.
	char		**envp;	// 환경변수를 담음
	t_term		term;
	t_input		input;
}				t_data;

/*	signal.c	*/
void	signal_handler(int signo);
int		ctrl_c_func(t_input *input);
void    ctrl_d_func(char *input, struct termios *ori_term);

/*	term.c	*/
void	term_init(struct termios *term1, struct termios *ori_term);
void	delete_end(char **input);
int		nbr_length(int n);
void	get_cursor_position(int *col, int *rows);
int		putchar_tc(int tc);

/*	cmd_utils.c	*/
void	cmd_init(char ***cmd);
int		**fds_set(int row);

/*	cmd.c	*/
void	c_func(t_data *data, t_pipe *pip);
void	execute(t_data *data, t_pipe *pip, int row); //여기 row 추가함
void	p_func(char **cmd_split, char *cmd_line,
				int row, int **fds, t_data *data);
void	cmd_handler(char **cmd_split, char *cmd_line, t_data *data);

/*	utils.c	*/
void    prompt(int flag);
void	dfree(char **str);
void	difree(int **darr);
int		dlen(char **darr);

/*	input.c	*/
char	*print_history(t_term *term, t_input *input);
int		input_handler(t_input *input);
int		key_else(t_data *data, t_input *input);
char	*input_recive(t_data *data);

/*	pipe.c	*/
void    c_pipe(int *old_fds, int *fds, int old_flag, int flag);
void    p_pipe(int *old_fds, int *fds);

/*	execute.c	*/
void    execute_input(t_data *data, t_pipe *pipe, int process);
void    print_error(char *massage, t_cmd *cmd);

/*	execute_utils.c	*/
char	**get_argv(char **split,  char *file);
int		make_token(t_cmd *cmd, char *input);
int		make_path(t_exec *exec);
void	exec_init(t_exec *exec, t_cmd *cmd);
void	exec_cmd_init(t_cmd *cmd);

/*	exceute_check.c	*/
int     builtin_cmd_check(t_data *data, char *cmd);
void    redirection_check(t_cmd *cmd);

/*	quote.c	*/
char	*handle_quotes(char *input, t_cmd *cmd);

/*	dollar.c	*/
char	*dollar(int i, char *input, t_cmd *cmd);

/*	ft_echo.c	*/
void	ft_echo(t_cmd *cmd, t_exec exec, t_data *data);

/*	ft_pwd.c	*/
void	ft_pwd(t_cmd *cmd, t_exec exec, t_data *data);

/*	ft_cd.c		*/
void	ft_cd(t_cmd *cmd, char *path, int process);

/*	ft_env.c		*/
void	ft_env(t_data *data);

/*	ft_exit.c		*/
void	ft_exit(t_data *data, int process);

/*	ft_export.c		*/
void	ft_export(t_cmd *cmd, t_data *data, int process);

#endif
