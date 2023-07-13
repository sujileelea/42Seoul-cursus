/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sean <sean@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 16:17:25 by sean              #+#    #+#             */
/*   Updated: 2022/03/19 21:31:11 by sean             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_glob	g_glob;

void	ft_here_echo(void)
{
	char	r[256];
	int		fd;

	fd = open("test.txt", O_RDWR, 0644);
	while (read(fd, r, 256) > 0)
		write(STDIN_FILENO, r, ft_strlen(r));
	close(fd);
}

void	do_here(char *cur_cmd, t_cmd *cmd)
{
	char	*input;
	char	r[128];
	int		fd;
	t_data	data;

	fd = open("test.txt", O_CREAT | O_RDWR | O_TRUNC, 0644);
	while (1)
	{
		input = input_recive(&data);
		if (ft_strncmp(input, "\n", 1) && \
		 	!ft_strncmp(input, cmd->file, ft_strlen(input) - 1) && \
			 !ft_strncmp(input, cmd->file, ft_strlen(cmd->file)))
			break ;
		write(fd, input, ft_strlen(input));
		if (g_glob.cflag == 1)
		{
			write(1, "\n", 1);
			break ;
		}
	}
	if (g_glob.cflag != 1 && cmd->cmd)
		ft_here_echo();
	close(fd);
	free(input);
	fd = unlink("test.txt");
}
