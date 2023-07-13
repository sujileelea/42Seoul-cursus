/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sean <sean@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 14:21:45 by sean              #+#    #+#             */
/*   Updated: 2022/03/19 19:58:07 by sean             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_glob	g_glob;

int	single_quotes(char **new_input, char *input, int i, t_cmd *cmd)
{
	int		j;
	int		len;
	char	*tmp;

	g_glob.quote = 1;
	len = 0;
	j = i + 1;
	while (input[++i] && input[i] != '\'')
		len++;
	if (input[i] == '\0')
		print_error("single quotes error\n", 1, cmd);
	if (g_glob.exit_status == 1)
		return (0);
	tmp = ft_substr(input, j, len);
	if (!ft_strncmp(*new_input, "", 1))
		free(*new_input);
	*new_input = ft_strjoin(*new_input, tmp);
	free(tmp);
	return (len + 1);
}

char	*handle_quotes3(char **new_input)
{
	g_glob.exit_status = 0;
	if (ft_strncmp(*new_input, "", ft_strlen(*new_input)))
		free(*new_input);
	return (ft_strdup(""));
}

char	*handle_quotes2(char *input, t_cmd *cmd)
{
	int		i;
	char	*new_input;

	i = -1;
	new_input = ft_strdup("");
	while (input[++i])
	{
		if (input[i] == '"')
			i += double_quotes(&new_input, input, i, cmd);
		if (g_glob.exit_status == 1 && g_glob.quote)
			break ;
		if (input[i] == '\'')
			i += single_quotes(&new_input, input, i, cmd);
		if (g_glob.exit_status == 1 && g_glob.quote)
			break ;
		if (input[i] && input[i] != '"' && input[i] != '\'')
			i += not_quotes(&new_input, input, i, cmd);
	}
	if (ft_strncmp(new_input, "exit", ft_strlen("exit")) && \
	g_glob.exit_status == 1 && g_glob.quote == 1)
		return (handle_quotes3(&new_input));
	else
		return (new_input);
}

char	*handle_quotes(char *input, t_cmd *cmd, int process)
{
	int				i;
	int				len;
	char			*new_input;
	char			**input_split;

	if (!input)
		return (input);
	i = -1;
	input_split = ft_split(input, ' ');
	if (!ft_strncmp(cmd->cmd, "echo", ft_strlen("echo")))
		process = 0;
	if (process == 1 && \
	(!ft_strchr(cmd->cmd, '"' || !ft_strchr(cmd->cmd, '\''))))
	{
		free(input_split);
		return (ft_strdup(input));
	}
	new_input = handle_quotes2(input, cmd);
	return (new_input);
}
