/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_bmpfile_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 03:19:11 by joockim           #+#    #+#             */
/*   Updated: 2021/05/27 19:11:04 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int		get_file_name(char *name)
{
	int	i;
	int	path;

	i = 0;
	path = 0;
	while (name[i])
		if (name[i++] == '/')
			path++;
	i = 0;
	while (path && name[i])
		if (name[i++] == '/')
			path--;
	return (i);
}

int		get_sub_len(char *name)
{
	int	i;

	i = 0;
	while (name[i] && name[i] != '.')
		i++;
	return (i);
}
