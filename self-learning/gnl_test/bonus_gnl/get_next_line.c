/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 15:36:19 by sujilee           #+#    #+#             */
/*   Updated: 2021/01/07 23:17:32 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*this_is_line(char *str)
{
	int			i;
	int			j;
	char		*dest;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!(dest = (char *)malloc(sizeof(char) * (i + 1))))
		return (0);
	j = 0;
	while (j < i)
	{
		dest[j] = str[j];
		j++;
	}
	dest[j] = '\0';
	return (dest);
}

char	*this_is_save(char *str)
{
	int			i;
	int			j;
	int			len;
	char		*dest;

	len = ft_strlen(str);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\0')
	{
		free(str);
		return (0);
	}
	if (!(dest = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	j = 0;
	while (str[i + 1])
	{
		dest[j++] = str[i + 1];
		i++;
	}
	dest[j] = '\0';
	free(str);
	return (dest);
}

int		get_next_line(int fd, char **line)
{
	int			i;
	char		*buff;
	static char	*save[256];

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	i = 1;
	if (!(buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while (i != 0 && no_newline(save[fd]))
	{
		if ((i = read(fd, buff, BUFFER_SIZE)) < 0)
			return (-1);
		buff[i] = '\0';
		if (!(save[fd] = ft_strjoin_custom(save[fd], buff)))
			return (-1);
	}
	free(buff);
	*line = this_is_line(&save[fd], fd);
	save[fd] = this_is_save(&save[fd], fd);
	if (save[fd] == NULL)
		return (0);
	return (1);
}
