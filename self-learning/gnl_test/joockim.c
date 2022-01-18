#include "get_next_line.h"

int	buf_check(char *buf)
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

int	get_line(char **str, char **line)
{


}
int	result(int len, int fd, char **str, char **line)
{}
int	get_next_line(int fd, char **line)
{
	int		len;
	char		*temp;
	static char	*str[OPEN_MAX];
	char		*buf;

	if (fd < 0 || line == 0 || BUFFER_SIZE == 0 ||
			!(buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + !))))
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
			break;
	}
	free(buf);
	buf = 0;
	return (result(len, fd, str, line));
}
