/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sean <sean@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 21:17:39 by sean              #+#    #+#             */
/*   Updated: 2022/03/19 21:48:05 by sean             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	redirection_in(t_cmd *cmd)
{
	struct stat	status;
	int			fd;

	if (stat(cmd->cur_file, &status) == -1)
		print_error("no such file or directory\n", 1, cmd);
	fd = open(cmd->cur_file, O_RDONLY);
	dup2(fd, 0);
	close(fd);
}

void	redirection_out(t_cmd *cmd)
{
	int	fd;

	if (!ft_strncmp(cmd->redir, ">", ft_strlen(cmd->redir)))
		fd = open(cmd->cur_file, O_RDWR | O_CREAT | O_TRUNC, 0644);
	else if (!ft_strncmp(cmd->redir, ">>", ft_strlen(cmd->redir)))
		fd = open(cmd->cur_file, O_RDWR | O_CREAT | O_APPEND, 0644);
	else
		print_error("syntax error near unexpected token\n", 2, cmd);
	dup2(fd, 1);
	close(fd);
}

int	redirection_check2(t_cmd *cmd, char *input, int i)
{
	t_cmd	tmp;
	int		ret;
	char	*tmp2;

	ret = make_token(&tmp, input, 1);
	cmd->cur_file = handle_quotes(tmp.cmd, cmd, 0);
	cmd->next_redir = tmp.redir;
	if (ft_strlen(cmd->next_redir) == 0 || input[ret] != ' ')
		return (ret - 1);
	else
		return (ret);
}

int	redirection_heredoc(char *cur_cmd, t_cmd *cmd)
{
	char	*temp;

	printf("heredoc\n");
	cmd->heredoc_str = ft_strjoin(cmd->cmd, " ");
	temp = ft_strjoin(cmd->heredoc_str, cmd->redir);
	cmd->heredoc_str = ft_strjoin(temp, " ");
	free(temp);
	temp = ft_strjoin(cmd->heredoc_str, cmd->file);
	cmd->heredoc_str = ft_strjoin(temp, "\n");
	free(temp);
	if (!ft_strncmp(cmd->redir, "<<", ft_strlen(cmd->redir)))
	{
		if (!cmd->cmd || !ft_strncmp(cmd->cmd, "cat", ft_strlen(cmd->cmd)))
			do_here(cur_cmd, cmd);
	}
	return (1);
}

int	redirection_check(char *cur_cmd, t_cmd *cmd)
{
	int	fd;
	int	i;
	int	ret;

	i = -1;
	ret = 0;
	while ((cmd->file)[++i])
	{
		i += redirection_check2(cmd, &(cmd->file)[i], i);
		if (ft_strlen(cmd->redir) != 0)
		{
			if (!ft_strncmp(cmd->redir, "<", ft_strlen(cmd->redir)))
				redirection_in(cmd);
			else if (!ft_strncmp(cmd->redir, "<<", ft_strlen(cmd->redir)))
				ret = redirection_heredoc(cur_cmd, cmd);
			else
				redirection_out(cmd);
		}
		else
			cmd->cmd_arg = ft_addonestring(cmd->cmd_arg, cmd->cur_file);
		free(cmd->redir);
		cmd->redir = cmd->next_redir;
	}
	return (ret);
}
