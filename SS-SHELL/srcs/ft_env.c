/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sean <sean@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 21:20:36 by seolryeong        #+#    #+#             */
/*   Updated: 2022/03/15 20:23:02 by sean             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_glob	g_glob;

void	ft_env(t_data *data)
{
	char	**split;
	int		i;

	i = -1;
	while ((g_glob.envp)[++i])
	{
		if (ft_strchr(g_glob.envp[i], '='))
			printf("%s\n", (g_glob.envp)[i]);
	}
}
