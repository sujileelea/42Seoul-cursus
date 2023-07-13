/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sean <sean@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 14:02:49 by okwon             #+#    #+#             */
/*   Updated: 2022/03/19 18:53:15 by sean             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	builtin_cmd_check(t_data *data, char *cmd)
{
	int	i;

	i = -1;
	if (!cmd)
		return (0);
	while (++i < CMD_NUM)
		if (!ft_strncmp(cmd, data->cmd[i], ft_strlen(cmd)) && \
		!ft_strncmp(cmd, data->cmd[i], ft_strlen(data->cmd[i])))
			return (1);
	return (0);
}

int	**fds_set(int row)
{
	int	i;
	int	**fds;

	fds = (int **)malloc(sizeof(int *) * (row + 1));
	fds[row] = 0;
	while (--row >= 0)
		fds[row] = (int *)malloc(sizeof(int) * 2);
	return (fds);
}

void	set_pipe_fds(int i, int stack, t_pipe *pip, int **fds)
{
	if (i > 0)
		pip->old_fds = fds[i - 1];
	else
		pip->old_fds = fds[0];
	pip->fds = fds[i];
	if (stack < ft_strlen(pip->ori_cmd_line))
		pip->flag = pip->ori_cmd_line[stack];
	else
		pip->flag = 0;
}

void	cmd_init(char ***cmd)
{
	int	i;

	*cmd = (char **)malloc(sizeof(char *) * (CMD_NUM + 1));
	i = -1;
	(*cmd)[++i] = ft_strdup(CMD_ECHO);
	(*cmd)[++i] = ft_strdup(CMD_CD);
	(*cmd)[++i] = ft_strdup(CMD_PWD);
	(*cmd)[++i] = ft_strdup(CMD_EXPORT);
	(*cmd)[++i] = ft_strdup(CMD_UNSET);
	(*cmd)[++i] = ft_strdup(CMD_ENV);
	(*cmd)[++i] = ft_strdup(CMD_EXIT);
	(*cmd)[++i] = 0;
}
