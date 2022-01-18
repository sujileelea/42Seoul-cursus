/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 16:34:22 by sujilee           #+#    #+#             */
/*   Updated: 2021/05/26 16:34:25 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/get_next_line.h"

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
	*line = this_is_line(save[fd]);
	save[fd] = this_is_save(save[fd]);
	if (save[fd] == NULL)
		return (0);
	return (1);
}