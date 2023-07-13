/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sean <sean@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 15:30:35 by seolryeong        #+#    #+#             */
/*   Updated: 2022/03/15 16:48:27 by sean             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_glob	g_glob;

void	ft_cd(t_cmd *cmd, char *path, int process)
{
	struct stat	status;

	if (!ft_strncmp(cmd->cmd, "cd", ft_strlen(cmd->cmd)))
	{
		chdir(ft_getenv("HOME"));
		return ;
	}
	if (stat(path, &status) == 0)
	{
		if (cmd->pipe_count == 1)
			chdir(path);
	}
	else
	{
		printf("no such file or directory\n");
		g_glob.exit_status = -1;
	}
}
