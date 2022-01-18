/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_bmpfile_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 16:47:11 by sujilee           #+#    #+#             */
/*   Updated: 2021/05/12 16:53:43 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/minirt_bonus.h"

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
	while (path & name[i])
		if (name[i++] = '/')
			path--;
	return (i);
}

int		get_sub_len(char *name)
{
	int	i;

	i = 0;
	while (name[i] && name[i] != '.')
		i++;
	return (1);
}