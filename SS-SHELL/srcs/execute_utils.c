/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sean <sean@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 20:22:04 by sean              #+#    #+#             */
/*   Updated: 2022/03/19 21:44:01 by sean             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_glob	g_glob;

int	make_path2(t_exec **exec)
{
	char		*tmp;
	int			i;
	struct stat	status;

	i = -1;
	while (((*exec)->env_path)[++i])
	{
		tmp = ft_strjoin(((*exec)->env_path)[i], "/");
		(*exec)->path = ft_strjoin(tmp, ((*exec)->split_cmd)[0]);
		if (stat((*exec)->path, &status) == 0)
			return (1);
		free((*exec)->path);
		free(tmp);
	}
	return (0);
}

int	make_path(t_exec *exec, t_cmd *cmd)
{
	struct stat	status;

	if (g_glob.quote == 1 && !exec->split_cmd[0])
		return (1);
	if (!exec->split_cmd[0] || !ft_strncmp(exec->split_cmd[0], "	", 1))
		return (0);
	if (ft_strncmp(exec->split_cmd[0], "/bin", 4) == 0)
	{
		exec->path = ft_strdup(exec->split_cmd[0]);
		if (stat(exec->path, &status) == 0)
			return (0);
	}
	if (make_path2(&exec))
		return (0);
	if (dlen(exec->env_path) == 0)
	{
		write(1, exec->split_cmd[0], ft_strlen(exec->split_cmd[0]));
		print_error("%s: No such file or directory\n", 1, cmd);
		printf("%s: No such file or directory\n", exec->split_cmd[0]);
		if (ft_strncmp(exec->split_cmd[0], \
		"cat", ft_strlen(exec->split_cmd[0])))
			printf("\n");
		return (0);
	}
	return (1);
}

void	make_token2(t_cmd **cmd, char *input, int i, int j)
{	
	t_string	str;

	str.one = ft_substr(input, 0, (i - j));
	(*cmd)->cmd = ft_strtrim(str.one, " ");
	if (!(*cmd)->cmd)
		(*cmd)->cmd = ft_strdup("");
	str.two = ft_substr(input, (i - j), j);
	(*cmd)->redir = ft_strtrim(str.two, " ");
	if (!(*cmd)->redir)
		(*cmd)->redir = ft_strdup("");
	str.three = ft_substr(input, i, ft_strlen(input) - i);
	(*cmd)->file = ft_strtrim(str.three, " ");
	if (!(*cmd)->file)
		(*cmd)->file = ft_strdup("");
	free(str.one);
	free(str.two);
	free(str.three);
}

int	make_token(t_cmd *cmd, char *input, int flag)
{
	int		i;
	int		j;
	char	delimeter;

	i = -1;
	j = 0;
	while (input[++i])
	{
		if (input[i] == '"')
			i = quote_detec_loop(input, '"', i);
		if (input[i] == '\'')
			i = quote_detec_loop(input, '\'', i);
		while (ft_strchr("><", input[i]))
		{
			i++;
			j++;
		}
		if (j != 0)
			break ;
		if (flag == 1 && i != 0 && input[i - 1] == ' ' && input[i] != ' ')
			break ;
	}
	make_token2(&cmd, input, i, j);
	return (i);
}

char	**get_argv(char **split, char *file)
{
	char	**ret;
	int		l;
	int		i;

	l = 0;
	while (split[l])
		++l;
	ret = (char **)malloc(sizeof(char *) * (l + 1));
	i = 0;
	ret[i] = file;
	while (split[++i])
		ret[i] = split[i];
	ret[i] = 0;
	return (ret);
}
