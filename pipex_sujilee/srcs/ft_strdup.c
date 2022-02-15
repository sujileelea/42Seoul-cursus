#include "../includes/pipex.h"

int	ft_strlen(const char *ptr)
{
	int	i;

	i = 0;
	while (ptr[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *ptr)
{
	char	*ptr2;
	int		len;
	int		i;

	len = ft_strlen(ptr);
	ptr2 = (char *)malloc(sizeof(char) * len + 1);
	if (ptr2 == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ptr2[i] = ptr[i];
		i++;
	}
	ptr2[i] = '\0';
	return (ptr2);
}
