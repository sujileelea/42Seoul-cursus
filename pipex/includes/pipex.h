/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 09:15:25 by sujilee           #+#    #+#             */
/*   Updated: 2022/02/14 12:21:51 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <fcntl.h>
#include <sys/wait.h>
#include <errno.h>


//실행할 
typedef struct	s_exec {
	char	**cmd_split; //명령문 split으로 찢어서 저장할 이중배열
	char	*cmd_path; // ex) ls앞에 붙는 모든 경로를 갖고있음
	int		fd;	
	int		status;
}				t_exec;

//파이프
typedef struct	s_pipe {
	int		write_fd;
	int		pipe_fd[2];
	pid_t	pid[2];
	int		status; //실행이 잘못됐을때를 대비한 멤버

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

void	print__error(char *cmd, char *mes, t_pipe *mypipe);
char	*make_path(char	*cmd, char **envp);
char	**find_path(char **envp);

/*****************************************************/
/**                     pipex.c                     **/
/*****************************************************/
void	second_part(t_pipe *mypipe, char **argv, char **envp);
void	first_part(t_pipe *mypipe, char **argv, char **envp);
void	fork_execute(t_pipe	*mypipe, char **argv, char **envp);
void	init_mypipe(t_pipe *mypipe);
#endif
