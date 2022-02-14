/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 09:55:21 by sujilee           #+#    #+#             */
/*   Updated: 2022/02/14 10:40:53 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	print_error( t_pipe *mypipe, char *cmd, char *mess)
{
	char *error;

	//error : "커맨드 + message"
	error = ft_strjoin(cmd, mess);
	//파이프의 출력fd(아마 표준출력)에 에러 출력
	write(mypipe->write_fd, error, ft_strlen(error));
	free(error);
	exit(1);
}

//환경변수 쥬르르 나올때 그 PATH 찾는 건가?
char	**find_path(char **envp)
{
	int	i;
	char	**cmd;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH", 4) == 0)
			break ;
		i++;
		// : 를 구분자로 cmd에 담기게됨
		cmd = ft_split(envp[i] + 5, ':');
		return (cmd);
	}
}

char	*make_path(char *cmd, char **envp)
{
	char	**envp_split;
	char	*cmd_path; //커맨드가 적용될 대상
	char	*temp_cmd;
	char	**exec_cmd; //적용될 커맨드
	int		i;

	//access()로 cmd에 대해 확인한다.
	//파일 주소 : cmd, 체크할 것 : 파일존재 | 실행 가능
	//파일이 존재하고 실행이 가능하면 cmd 반환
	if (access(cmd, F_OK | X_OK) == 0)
		return (cmd);
	//스플릿을 사용해 공백을 기준으로 커맨드를 저장
	exec_cmd = ft_split(cmd, ' ');

//

	//strjoin으로 "/커맨드" 를 만듦
	temp_cmd = ft_strjoin("/", exec_cmd[0]);
	envp_split = find_path(envp);
	i = 0;
	while (envp_split[i])
	{	
		//cmd의 타겟 = "경로/커맨드"
		cmd_path = ft_strjoin(envp_split[i], temp_cmd);
		if (access(cmd_path, F_OK | X_OK) == 0)
			break;
		i++;
	}
	//더 이상 내용물이 없으면 즉, 명령어가 없으면 빈 문자열 반환!
	//"command not found"
	if (!envp_split[i])
		return ("");
	return (cmd_path);

}
