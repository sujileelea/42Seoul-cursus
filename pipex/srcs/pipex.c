/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 09:13:59 by sujilee           #+#    #+#             */
/*   Updated: 2022/02/14 12:45:42 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"


//파이프 뒤
void	second_part(t_pipe *mypipe, char **argv, char **envp)
{
	t_exec	exec;

	close(mypipe->pipe_fd[1]);

	//
	//outfile이 없으면 그냥 만들면 되니까. 0664 : Chmod시 644로 
	exec.fd = open(argv[4], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (exec.fd < 0)
		print_error(mypipe, argv[4], ": No such file or directory\n");
	//cmd2 작업
	exec.cmd_split = ft_split(argv[3], ' ');
	exec.cmd_path = make_path(argv[3], envp);
	//파이프입구를 표준입력(0)에 복제
	dup2(mypipe->pipe_fd[0], STDIN_FILENO);
	//exec.fd(outfile)를 표준출력(1)에 복제
	dup2(exec.fd, STDOUT_FILENO);
	if (ft_strncmp(exec.cmd_path, "", 1) != 0)
	{
		//execve()로 cmd2를 실행. 그럼 위에 dup2로 만든 경로로 outfile에 결과가 담김
		//경로 : exec.cmd_path 명령어 : exec.cmd_split
		exec.status = execve(exec.cmd_path, exec.cmd_split, envp);
		if (exec.status == -1)
			print_error(mypipe, "", "execute error\n");
	}
	else
		print_error(mypipe, argv[3], ": command not found\n");
	//만약 프로세스가 살아있으면 안되니까 exit(0)
	exit(0);
}

//파이프 앞
void	first_part(t_pipe *mypipe, char **argv, char **envp)
{
	t_exec	exec;

	//쓰기를 안하고 받기만 하겠다. 입력이 들어오는 입구 close
	close(mypipe->pipe_fd[0]);
	//인자로 들어온 첫 path를 open하고 그 fd값을 exec.fd에 할당
	exec.fd = open(argv[1], O_RDONLY);
		if (exec.fd < 0)
		print_error(mypipe, argv[1], " : No such file or directory");
	//공백을 구분자로 해서 명령어를 이중배열에 옵션까지 담아놓음
	exec.cmd_split = ft_split(argv[2], ' ');
	exec.cmd_path = make_path(argv[2], envp);
	
	//exec.fd(즉, infile)를 표준입력(0)에 복제
	dup2(exec.fd, STDIN_FILENO);
	//mypipe의 출구를 표준출력(1)에 복제
	dup2(mypipe->pipe_fd[1], STDOUT_FILENO);
	

	// 명령어 앞의 경로를 갖고 있으면
	if (ft_strncmp(exec.cmd_path, "", 1) != 0)
	{
		//execve로 exec.cmd_path의 파일을 실행시킨다.
		//실행 -> 명령어를 실행시키는 새 프로세스가 생김
		exec.status = execve(exec.cmd_path, exec.cmd_split, envp);
		//실패시 오류 출력
		if (exec.status == -1)
			print_error(mypipe, "", " : execute error\n");
	}
	//커맨드가 제대로 안들어왔으면 오류 출력
	else
		print_error(mypipe, argv[2], " : command not found\n");
}

void	fork_execute(t_pipe	*mypipe, char **argv, char **envp)
{
	//fork로 자식 프로세스 생성 & 반환.
	//파이프 입구에 해당 자식의 pid를 넣는다?
	mypipe->pid[0] = fork();
	//입구 포크 실패 시
	if (mypipe->pid[0] < 0)
		print_error(mypipe, "", "pid[0] fork error\n");
	//mypipe 입구가 자식이면
	else if (mypipe->pid[0] == 0)
		first_part(mypipe, argv, envp);
	//출구 포크 실패 시
	if (mypipe->pid[1] < 0)
		print_error(mypipe, "", "pid[1]] fork error\n");
	//mypipe 출구가 자식이면
	else if (mypipe->pid[1] == 0)
		second_part(mypipe, argv, envp);
}

void	init_pipe(t_pipe *mypipe)
{
	mypipe->write_fd = 0;
	mypipe->pid[0] = 0;
	mypipe->pid[1] = 0;
	mypipe->status = 0;
	// pipe를 만들어준다.
	pipe(mypipe->pipe_fd);

}

int	main(int argc, char **argv, char **envp)
{
	t_pipe	mypipe;
	
	if (argc != 5)
		//에러 출력. 리턴
		print_error("", "argument error\n", &mypipe);
	//mypipe 초기화
	init_pipe(&mypipe);
	//pipex 동작, 파싱 함수
	fork_execute(&mypipe, argv, envp);
	//입구 닫기. pipe()도 fd를 배정받기 때문에 사용후 fd를 닫아줘야함
	close(mypipe.pipe_fd[0]);
	//출구 닫기. 
	close(mypipe.pipe_fd[1]);
	//wait함수를 쓰는 이유 : 자식 프로세스가 좀비 프로세스가 되는 것 방지
	//부모 프로세스가 자식 프로세스의 exeve()전에 종료되는 것 방지
	//파이프 입구를 감시하면서 끝날때까지 대기함.
	waitpid(mypipe.pid[0], &(mypipe.status), 0);
	//파이프 출구를 감시하면서 끝날때까지 대기함.
	waitpid(mypipe.pid[1], &(mypipe.status), 0);
	return (0);
}