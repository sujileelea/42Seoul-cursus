/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sean <sean@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 16:21:58 by sean              #+#    #+#             */
/*   Updated: 2022/03/19 22:42:18 by sean             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_glob	g_glob;

void	ft_pipe_split2(char *cmd, int *i, int *start, char ***split_cmd)
{
	t_string	str;

	if (cmd[*i] == '\'' || cmd[*i] == '"')
		*i = quote_detec_loop(cmd, cmd[*i], *i);
	if (cmd[*i] == '|')
	{
		str.one = ft_substr(cmd, *start, *i - *start);
		*split_cmd = ft_addonestring(*split_cmd, str.one);
		*start = *i + 1;
		free(str.one);
	}
}

char	**ft_pipe_split(char *cmd)
{
	int			start;
	int			i;
	char		**split_cmd;
	t_string	str;

	split_cmd = (char **)malloc(sizeof(char *) * 1);
	split_cmd[0] = NULL;
	start = 0;
	i = -1;
	while (cmd[++i])
		ft_pipe_split2(cmd, &i, &start, &split_cmd);
	if (start != i)
	{
		str.two = ft_substr(cmd, start, i);
		split_cmd = ft_addonestring(split_cmd, str.two);
		free(str.two);
	}
	return (split_cmd);
}
