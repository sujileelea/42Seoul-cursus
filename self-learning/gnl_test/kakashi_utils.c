#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	ft_strdup(const char *s1)
{
	size_t	i;
	char	*result;

	i = ft_strlen(s1);
	if (!(result = malloc(sizeof(char) * (len + 1))))
		return (0);
	len = 0;
	while (s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	int	i;


