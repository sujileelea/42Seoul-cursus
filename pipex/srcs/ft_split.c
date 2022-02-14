#include "../includes/pipex.h"

static char	**free_arr(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (0);
}

static int	revise_str(char *str, char c)
{
	int		cnt;
	size_t	i;
	size_t	j;

	cnt = 0;
	i = 0;
	j = i - 1;
	while (str[i])
	{
		if (str[i] == c)
		{
			str[i] = 0;
			if (i > j + 1)
				++cnt;
			j = i;
		}
		++i;
	}
	if (str[i - 1])
		++cnt;
	return (cnt);
}

static char	**fill_arr(char *str, int cnt)
{
	char	**rslt;
	size_t	i;
	int		fill;

	rslt = (char **)malloc(sizeof(char *) * (cnt + 1));
	if (!rslt)
		return (0);
	i = 0;
	fill = 0;
	while (fill < cnt)
	{
		if (str[i])
		{
			rslt[fill] = ft_strdup(str + i);
			if (!rslt[fill])
				return (free_arr(rslt));
			i += ft_strlen(rslt[fill]);
			++fill;
		}
		++i;
	}
	rslt[cnt] = 0;
	return (rslt);
}

char	**ft_split(char const *s, char c)
{
	char	**rslt;
	char	*str;
	int		cnt;

	str = ft_strdup(s);
	if (!s || !str)
		return (0);
	if (ft_strlen(str) < 1)
	{
		free(str);
		rslt = malloc(sizeof(char *));
		if (!rslt)
			return (0);
		rslt[0] = 0;
		return (rslt);
	}
	cnt = revise_str(str, c);
	rslt = fill_arr(str, cnt);
	free(str);
	return (rslt);
}
