#include "../includes/pipex.h"

char	**find_path(char **envp)
{
	int		i;
	char	**cmd;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH", 4) == 0)
			break ;
		i++;
	}
	cmd = ft_split(envp[i] + 5, ':');
	return (cmd);
}

char	*make_path(char	*cmd, char **envp)
{
	char	**envp_split;
	char	*cmd_path;
	char	*tmp_cmd;
	char	**exec_cmd;
	int		i;

	if (access(cmd, F_OK | X_OK) == 0)
		return (cmd);
	exec_cmd = ft_split(cmd, ' ');
	tmp_cmd = ft_strjoin("/", exec_cmd[0]);
	envp_split = find_path(envp);
	i = 0;
	while (envp_split[i])
	{
		 cmd_path = ft_strjoin(envp_split[i], tmp_cmd);
		 if (access(cmd_path, F_OK | X_OK) == 0)
			 break ;
		i++;
	}
	if (!envp_split[i])
		return ("");
	return (cmd_path);
}

void	print_promt_error(char *cmd, char *mes, t_pipe *mypipe)
{
	char	*error;

	error = ft_strjoin(cmd, mes);
	write(mypipe->write_fd, error, ft_strlen(error));
	free(error);
	exit(1);
}
