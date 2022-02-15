#include "../includes/pipex.h"

int	ft_strncmp(const char *ptr1, const char *ptr2, int count)
{
	int				i;
	unsigned char	*array1;
	unsigned char	*array2;

	array1 = (unsigned char *)ptr1;
	array2 = (unsigned char *)ptr2;
	i = 0;
	if (count == 0)
		return (0);
	while (i < count)
	{
		if (array1[i] != array2[i])
		{
			if (array1[i] > array2[i])
				return (1);
			else
				return (-1);
		}
		if (array1[i] == '\0' && array2[i] == '\0')
			return (0);
		i++;
	}
	return (0);
}
