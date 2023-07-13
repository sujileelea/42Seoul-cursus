/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 11:01:58 by sujilee           #+#    #+#             */
/*   Updated: 2022/03/14 17:48:32 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_glob	g_glob;

int	find_remove_str(char **origin, char *remove, int len)
{
	int		i;
	int		r_len;

	r_len = (int)ft_strlen(remove);
	i = 0;
	while (i < len)
	{
		if (!ft_strncmp(origin[i], remove, r_len)
			&& (origin[i][r_len] == '\0' || origin[i][r_len] == '='))
			return (i);
		i++;
	}
	return (-1);
}

char	**ft_removeonestring(char **origin, char *remove, int origin_len)
{
	char	**new;
	int		i;
	int		newi;
	int		flag;

	flag = find_remove_str(origin, remove, origin_len);
	if (flag != -1)
		new = (char **)malloc(sizeof(char *) * (origin_len));
	else
		return (origin);
	i = -1;
	newi = 0;
	while (++i < origin_len)
	{
		if (i != flag)
			new[newi++] = ft_strdup(origin[i]);
	}
	new[newi] = 0;
	dfree(origin);
	return (new);
}

int	check_alnum_remove(char *remove)
{
	int	i;

	i = -1;
	while (++i < (int)ft_strlen(remove))
	{
		if (!(ft_isalnum(remove[i]) || remove[i] == '_'))
			return (1);
	}
	return (0);
}

void	ft_unset(t_cmd *cmd, t_data *data)
{
	int		i;
	char	***env;
	char	**split;

	env = &g_glob.envp;
	split = ft_split(cmd->cmd, ' ');
	i = 1;
	while (i < ft_sstrlen(split))
	{
		if (check_alnum_remove(split[i]) == 1)
		{
			print_error("minishell: unset: \'", -1, cmd);
			print_error(split[i], -1, cmd);
			print_error("\': not a valid identifier\n", -1, cmd);
		}
		else
			*env = ft_removeonestring(*env, split[i], ft_sstrlen(*env));
		i++;
	}
}
