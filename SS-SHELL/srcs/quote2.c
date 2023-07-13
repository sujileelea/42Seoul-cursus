/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 14:21:45 by sean              #+#    #+#             */
/*   Updated: 2022/03/20 18:04:41 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_glob	g_glob;

char	*not_quotes2(int i, char *input, char **new_input, t_cmd *cmd)
{
	int			j;
	int			len;
	char		*tmp;
	t_string	str;

	len = 1;
	j = i;
	while (input[++i] && input[i] != ' ' && input[i] != '"' && \
	input[i] != '\'' && input[i] != '$')
		len++;
	if (input[i - len] == '$')
	{
		str.four = ft_substr(input, j, len);
		tmp = ft_strjoin(*new_input, dollar(0, str.four, cmd));
		if (input[i - len + 1] == '?')
			len = 2;
		free(str.four);
	}
	else
	{
		str.five = ft_substr(input, j, len);
		tmp = ft_strjoin(*new_input, str.five);
		free(str.five);
	}
	return (ft_strdup(tmp));
}

int	not_quotes(char **new_input, char *input, int i, t_cmd *cmd)
{
	int			j;
	int			start;
	int			len;
	char		*tmp;
	t_string	str;

	len = 1;
	start = i;
	while (input[++i] && input[i] != ' ' && input[i] != '"' && \
	input[i] != '\'' && input[i] != '$')
		len++;
	tmp = not_quotes2(start, input, new_input, cmd);
	if (input[i - len] == '$' && input[i - len + 1] == '?')
		len = 2;
	if (!ft_strncmp(*new_input, "", ft_strlen(*new_input)))
		free(*new_input);
	*new_input = ft_strdup(tmp);
	if (!tmp)
		free(tmp);
	return (len - 1);
}

int	double_quotes(char **new_input, char *input, int i, t_cmd *cmd)
{
	int		j;
	int		len;
	char	*tmp;
	char	*tmp2;

	g_glob.quote = 1;
	len = 0;
	j = i + 1;
	while (input[++i] && input[i] != '"')
		len++;
	if (input[i] == '\0')
		print_error("double quotes error\n", 1, cmd);
	if (g_glob.exit_status == 1)
		return (0);
	tmp = ft_substr(input, j, len);
	tmp2 = double_quotes2(tmp, cmd);
	if (!ft_strncmp(*new_input, "", 1))
		free(*new_input);
	*new_input = ft_strjoin(*new_input, tmp2);
	free(tmp);
	return (len + 1);
}

char	*double_quotes2(char *tmp, t_cmd *cmd)
{
	int			i;
	int			j;
	t_string	str;

	i = -1;
	while (tmp[++i])
	{
		if (tmp[i] == '$')
		{
			j = 1;
			while (tmp[++i] && tmp[i] != ' ' && tmp[i] != '$' && \
			tmp[i] != '\'' && tmp[i] != '?')
				j++;
			str.one = ft_substr(tmp, 0, i - j);
			str.mid = dollar(0, ft_substr(tmp, i - j, j), cmd);
			str.two = ft_substr(tmp, i, ft_strlen(tmp));
			if (tmp)
				free(tmp);
			tmp = ft_strjoin(ft_strjoin(str.one, str.mid), str.two);
			i = ft_strlen(str.one) + ft_strlen(str.mid) - 1;
			free(str.two);
		}
	}
	free(str.one);
	return (tmp);
}
