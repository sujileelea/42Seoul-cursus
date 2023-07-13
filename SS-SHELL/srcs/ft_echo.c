/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sean <sean@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 19:31:04 by sean              #+#    #+#             */
/*   Updated: 2022/03/19 19:23:03 by sean             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_glob	g_glob;

void	echo_option(char **split, int *i, int *option)
{
	int		j;

	j = 1;
	if (split[*i] != NULL)
	{
		while (split[*i][0] == '-')
		{
			while (split[*i][j] && split[*i][j] == 'n')
				j++;
			if (ft_strlen(split[*i]) == j)
				*option = 1;
			else
				break ;
			(*i)++;
		}
	}
}

void	ft_echo(t_cmd *cmd, t_exec exec, t_data *data)
{
	int		i;
	int		option;
	char	**split;

	i = 1;
	option = 0;
	split = ft_split(cmd->cmd, ' ');
	echo_option(split, &i, &option);
	while (i < ft_sstrlen(split))
	{
		printf("%s", split[i]);
		i++;
		if (i != ft_sstrlen(split))
			printf(" ");
	}
	if (option == 0)
		printf("\n");
}
