#include "../includes/pipex.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		string_len;
	char	*ptr;
	int		i;
	int		ptr_index;

	ptr_index = -1;
	i = -1;
	if (s1 == NULL)
		return (NULL);
	string_len = ft_strlen(s1);
	if (s2 != NULL)
		string_len += ft_strlen(s2);
	ptr = (char *)malloc(sizeof(char) * string_len + 1);
	if (ptr == NULL)
		return (NULL);
	while (s1[++i] != '\0')
		ptr[++ptr_index] = s1[i];
	i = -1;
	while (s2[++i] != '\0')
		ptr[++ptr_index] = s2[i];
	ptr[++ptr_index] = '\0';
	return (ptr);
}
