#include <stdlib.h>
#include <stdio.h>

char *make_string(int count, char c)
{
	int i;
	char *result;

	i = 0;
	result = (char *)malloc(sizeof(char) * count);
	while (i < count)
	{
		result[i] = c;
		i++;
	}
	return (result);
}

int	main(void)
{
	char *str;

	str = make_string(10, '0');
	printf("%s\n", str);
	return (0);
}
