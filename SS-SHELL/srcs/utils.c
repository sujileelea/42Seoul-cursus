/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sean <sean@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 16:23:18 by okwon             #+#    #+#             */
/*   Updated: 2022/03/19 22:59:31 by sean             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_glob	g_glob;

void	dfree(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
}

void	difree(int **darr)
{
	int	i;

	i = -1;
	while (darr[++i])
		free(darr[i]);
	free(darr);
}

int	dlen(char **darr)
{
	int	i;

	i = 0;
	while (darr[i])
		++i;
	return (i);
}

void	prompt(int flag)
{
	if (flag == 0)
		write(1, "SS-SHELL$ ", 10);
	else if (flag == 1)
	{
		write(1, "\nSS-SHELL$ ", 11);
		g_glob.cflag = 0;
	}
	else if (flag == 3)
	{
		g_glob.cflag = 0;
		write(1, "Quit: 3\n", 8);
	}
	else if (flag == 2)
	{
		g_glob.cflag = 0;
		write(1, "\n", 1);
	}
}
