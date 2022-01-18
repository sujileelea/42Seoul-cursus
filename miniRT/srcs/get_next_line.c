/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 14:37:43 by sujilee           #+#    #+#             */
/*   Updated: 2021/05/31 14:39:55 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

int		buf_check(char *buf)
{
	while (*buf)
	{
		if (*buf == '\n')
			return (1);
		buf++;
	}
	return (0);
}

void	ft_strdel(char **as)
{
	if (as)
	{
		free(*as);
		*as = 0;
	}
	return ;
}

int		get_line(char **str, char **line)
{
	int		i;
	char	*temp;

	i = 0;
	while ((*str)[i] != '\n' && (*str)[i] != '\0')
		i++;
	if ((*str)[i] == '\n')
	{
		if (i == 0)
			*line = ft_strdup("");
		else
			*line = ft_substr(*str, 0, i);
		temp = ft_strdup(&(*str)[i + 1]);
		free(*str);
		*(str) = temp;
		if ((*str)[0] == '\0')
			ft_strdel(str);
	}
	else
	{
		*line = ft_strdup(*str);
		ft_strdel(str);
		return (0);
	}
	return (1);
}

int		result(int len, int fd, char **str, char **line)
{
	if (len < 0)
		return (-1);
	else if (len == 0 && str[fd] == 0)
	{
		ft_strdel(&str[fd]);
		*line = ft_strdup("");
		return (0);
	}
	else
		return (get_line(&str[fd], line));
}

int		get_next_line(int fd, char **line)
{
	int			len;
	char		*temp;
	static char	*str[OPEN_MAX];
	char		*buf;

	if (fd < 0 || line == 0 || BUFFER_SIZE == 0 ||
			!(buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while ((len = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[len] = '\0';
		if (str[fd] == 0)
			str[fd] = ft_strdup(buf);
		else
		{
			temp = ft_strjoin(str[fd], buf);
			free(str[fd]);
			str[fd] = temp;
		}
		if (buf_check(buf))
			break ;
	}
	free(buf);
	buf = 0;
	return (result(len, fd, str, line));
}
