/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sean <sean@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 16:14:14 by okwon             #+#    #+#             */
/*   Updated: 2022/03/18 19:18:50 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	c_pipe(t_pipe *pip)
{
	int	ret;

	if (pip->old_flag == '|')
	{
		close(STDIN_FILENO);
		close(pip->old_fds[1]);
		dup2(pip->old_fds[0], 0);
		close(pip->old_fds[0]);
	}
	if (pip->flag == '|')
	{
		if (ft_strncmp(pip->cur_cmd, "exit", ft_strlen(pip->cur_cmd)) && \
		ft_strncmp(pip->cur_cmd, "exit", ft_strlen("exit")))
		{
			close(STDOUT_FILENO);
			close(pip->fds[0]);
			dup2(pip->fds[1], 1);
			close(pip->fds[1]);
		}
	}
}

void	p_pipe(int *old_fds, int *fds)
{
	close(fds[1]);
	close(old_fds[1]);
}
