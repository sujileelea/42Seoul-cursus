#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int i;

	if (!str)
		return (0)
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	no_newline(char *str)
{
	int i;

	if (str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] != '\n')
			return (1);
	}
	return (0);
}

char	*ft_strjoin_custom(char *save, char *buff)
{
	int s;
	int b;
	int i;
	int j;
	char *dest;

	s = ft_strlen(save);
	b = ft_strlen(buff);
	if (!(dest = (char *)malloc(sizeof(char) * (s + b + 1))))
		return (0);
	i = 0;
	while (i < s)
	{
		dest[i] = str[i];
		i++;
	}
	j = 0;
	while (j < b)
	{
		dest[j] = buff[j];
		i++;
	}
	dest[i + j] = '\0';
	free(save);
	return (dest);
}
