/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sean <sean@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 14:43:02 by sujilee           #+#    #+#             */
/*   Updated: 2022/03/18 17:28:42 by sean             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_sstrlen(char **strstr)
{
	int		len;

	len = 0;
	if (!strstr)
		return (0);
	while (strstr[len] != NULL)
		++len;
	return (len);
}

char	**ft_sstrdup(char **origin)
{
	int		i;
	int		env_len;
	char	**new_env;

	if (!origin)
		return (NULL);
	env_len = ft_sstrlen(origin);
	new_env = (char **)malloc(sizeof(char *) * (env_len + 1));
	i = -1;
	while (++i < env_len)
		new_env[i] = ft_strdup(origin[i]);
	new_env[i] = NULL;
	return (new_env);
}

char	**ft_addonestring(char **origin, char *addline)
{
	char	**new;
	int		idxlen;
	int		i;

	idxlen = 0;
	while (origin[idxlen])
		idxlen++;
	new = (char **)malloc(sizeof(char *) * (idxlen + 2));
	i = -1;
	while (++i < idxlen)
		new[i] = ft_strdup(origin[i]);
	new[idxlen] = ft_strdup(addline);
	new[idxlen + 1] = NULL;
	idxlen = 0;
	dfree(origin);
	origin = 0;
	return (new);
}
