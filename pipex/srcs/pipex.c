#include "../includes/pipex.h"

void	second_part(char **argv, char **envp, t_pipe *mypipe)
{
	t_exec	exec;

	close(mypipe->pipe_fd[1]);
	exec.fd = open(argv[4], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (exec.fd < 0)
		print_promt_error(argv[4], ": No such file or directory\n", mypipe);
	exec.cmd_split = ft_split(argv[3], ' ');
	exec.cmd_path = make_path(argv[3], envp);
	dup2(mypipe->pipe_fd[0], STDIN_FILENO);
	dup2(exec.fd, STDOUT_FILENO);
	if (ft_strncmp(exec.cmd_path, "", 1) != 0)
	{
		exec.status = execve(exec.cmd_path, exec.cmd_split, envp);
		if (exec.status == -1)
			print_promt_error("", "execute error\n", mypipe);
	}
	else
		print_promt_error(argv[3], ": command not found\n", mypipe);
	exit(0);
}

void	first_part(char **argv, char **envp, t_pipe *mypipe)
{
	t_exec	exec;

	close(mypipe->pipe_fd[0]);
	exec.fd = open(argv[1], O_RDONLY);
	if (exec.fd < 0)
		print_promt_error(argv[1], ": No such file or directory\n", mypipe);
	exec.cmd_split = ft_split(argv[2], ' ');
	exec.cmd_path = make_path(argv[2], envp);
	dup2(exec.fd, STDIN_FILENO);
	dup2(mypipe->pipe_fd[1], STDOUT_FILENO);
	if (ft_strncmp(exec.cmd_path, "", 1) != 0)
	{
		exec.status = execve(exec.cmd_path, exec.cmd_split, envp);
		if (exec.status == -1)
			print_promt_error("", "execute error\n", mypipe);
	}
	else
		print_promt_error(argv[2], ": command not found\n", mypipe);
	exit(0);
}

void	fork_execute(t_pipe	*mypipe, char **argv, char **envp)
{
	mypipe->pid[0] = fork();
	if (mypipe->pid[0] < 0)
		print_promt_error("", "pid[0] fork error\n", mypipe);
	else if (mypipe->pid[0] == 0)
		first_part(argv, envp, mypipe);
	mypipe->pid[1] = fork();
	if (mypipe->pid[1] < 0)
		print_promt_error("", "pid[1] fork error\n", mypipe);
	else if (mypipe->pid[1] == 0)
		second_part(argv, envp, mypipe);
}

void	init_mypipe(t_pipe *mypipe)
{
	mypipe->write_fd = dup(1);
	mypipe->pid[0] = 0;
	mypipe->pid[1] = 0;
	pipe(mypipe->pipe_fd);
	mypipe->status = 0;
}

int	main(int argc, char **argv, char **envp)
{
	t_pipe	mypipe;

	init_mypipe(&mypipe);
	if (argc != 5)
		print_promt_error("", "argument error\n", &mypipe);
	fork_execute(&mypipe, argv, envp);
	close(mypipe.pipe_fd[0]);
	close(mypipe.pipe_fd[1]);
	waitpid(mypipe.pid[0], &(mypipe.status), 0);
	waitpid(mypipe.pid[1], &(mypipe.status), 0);
	return (0);
}
