/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 16:19:51 by sujilee           #+#    #+#             */
/*   Updated: 2021/01/10 16:19:56 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		ft_strlen(char *str)
{
	int		i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		no_newline(char *str)
{
	int		i;

	if (!str)
		return (1);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}

char	*ft_strjoin_custom(char *save, char *buff)
{
	int		s;
	int		b;
	int		i;
	int		j;
	char	*dest;

	s = ft_strlen(save);
	b = ft_strlen(buff);
	if (!(dest = (char *)malloc(sizeof(char) * (s + b + 1))))
		return (0);
	i = 0;
	while (i < s)
	{
		dest[i] = save[i];
		i++;
	}
	j = 0;
	while (j < b)
	{
		dest[i + j] = buff[j];
		j++;
	}
	dest[i + j] = '\0';
	free(save);
	return (dest);
}
