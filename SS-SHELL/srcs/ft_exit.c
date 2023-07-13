/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sean <sean@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 21:37:48 by seolryeong        #+#    #+#             */
/*   Updated: 2022/03/17 17:43:21 by sean             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_glob	g_glob;

int	digit_check(char *cmd, int size, int process)
{
	int	i;

	i = -1;
	while (cmd[++i])
	{
		if (ft_isalpha(cmd[i]))
		{
			if (size <= 2)
			{
				if (process == 0)
					printf("exit\n");
				printf("SS-SHELL: exit: %s: numeric argument required\n", cmd);
				g_glob.exit_status = 255;
			}
			return (0);
		}	
	}
	return (1);
}

void	over_two_arg(char *cmd, int size, int process)
{
	if (digit_check(cmd, size, process))
	{
		write(1, "SS-SHELL: exit: too many arguments\n", 35);
		g_glob.exit_status = 1;
	}
	else
	{
		printf("SS-SHELL: exit: %s: numeric argument required\n", cmd);
		g_glob.exit_status = 255;
	}
}

void	ft_exit(char **cmd, t_data *data, int process)
{
	if (dlen(cmd) == 1)
	{
		g_glob.exit_status = 0;
		if (process == 0)
			printf("exit\n");
	}
	else if (dlen(cmd) == 2)
	{
		if (digit_check(cmd[1], dlen(cmd), process))
			g_glob.exit_status = ft_atoi(cmd[1]);
	}
	else if (dlen(cmd) > 2)
		over_two_arg(cmd[1], dlen(cmd), process);
	if (g_glob.exit_status != 1)
	{
		tcsetattr(STDIN_FILENO, TCSANOW, &data->term.ori_term);
		exit(g_glob.exit_status);
	}
	if (process == 0)
		g_glob.exit_status = -1;
}
