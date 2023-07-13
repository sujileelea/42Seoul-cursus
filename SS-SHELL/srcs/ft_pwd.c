/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 14:47:37 by seolryeong        #+#    #+#             */
/*   Updated: 2022/03/07 13:51:49 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_pwd(t_cmd *cmd, t_exec exec, t_data *data)
{
	char	*pwd;

	pwd = getcwd(0, 255);
	printf("%s\n", pwd);
	free(pwd);
}
