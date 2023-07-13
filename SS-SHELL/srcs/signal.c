/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sean <sean@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 16:19:08 by okwon             #+#    #+#             */
/*   Updated: 2022/03/19 20:04:15 by sean             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_glob	g_glob;

void	signal_handler2(int signo)
{
	if (g_glob.cflag == 2)
		g_glob.cflag = 3;
}

void	signal_handler(int signo)
{
	if (signo == SIGINT)
	{
		if (g_glob.cflag != 2)
		{
			g_glob.read_size = -1;
			write(0, "\n", 1);
			write(0, "SS-SHELL$ ", 10);
			g_glob.exit_status = 130;
		}
		else
		{
			g_glob.read_size = -1;
			g_glob.exit_status = 130;
		}
	}
}

int	ctrl_c_func(t_input *input)
{
	g_glob.read_size = 0;
	if (input->buf == K_UP || input->buf == DOWN)
	{
		input->nidx = 0;
		g_glob.cflag = 0;
	}
	else if ((char)input->buf == '\n')
	{
		if (ft_strncmp(input->input, "", ft_strlen(input->input)))
			free(input->input);
		g_glob.cflag = 1;
		return (1);
	}
	else
	{
		if (ft_strncmp(input->input, "", ft_strlen(input->input)))
			free(input->input);
		input->input = ft_strjoin("", "");
	}
	return (0);
}

void	ctrl_d_func(char *input, struct termios *ori_term)
{
	if (!ft_strncmp(input, "", ft_strlen(input)))
	{
		write(0, "exit\n", 5);
		tcsetattr(STDIN_FILENO, TCSANOW, ori_term);
		exit(0);
	}
}
