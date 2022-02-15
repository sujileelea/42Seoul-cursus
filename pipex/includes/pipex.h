#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <errno.h>

typedef struct s_exec {
	char	**cmd_split;
	char	*cmd_path;
	int		fd;
	int		status;
}				t_exec;

typedef struct s_pipe {
	int		write_fd;
	int		pipe_fd[2];
	pid_t	pid[2];
	int		status;
}				t_pipe;

/*****************************************************/
/**                  ft_strdup.c                    **/
/*****************************************************/

char	*ft_strdup(const char *ptr);
int		ft_strlen(const char *ptr);

/*****************************************************/
/**                   ft_split.c                     **/
/*****************************************************/

char	**ft_split(char const *s, char c);

/*****************************************************/
/**                  ft_strjoin.c                   **/
/*****************************************************/

char	*ft_strjoin(char const *s1, char const *s2);

/*****************************************************/
/**                  ft_strncmp.c                   **/
/*****************************************************/

int		ft_strncmp(const char *ptr1, const char *ptr2, int count);

/*****************************************************/
/**                     utils.c                     **/
/*****************************************************/

void	print_promt_error(char *cmd, char *mes, t_pipe *mypipe);
char	*make_path(char	*cmd, char **envp);
char	**find_path(char **envp);

/*****************************************************/
/**                     pipex.c                     **/
/*****************************************************/
void	second_part(char **argv, char **envp, t_pipe *mypipe);
void	first_part(char **argv, char **envp, t_pipe *mypipe);
void	fork_execute(t_pipe	*mypipe, char **argv, char **envp);
void	init_mypipe(t_pipe *mypipe);
#endif

