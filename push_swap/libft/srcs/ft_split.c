/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 17:50:36 by sujilee           #+#    #+#             */
/*   Updated: 2020/11/20 19:44:00 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_countblock(const char *str, char c)
{
	int i;
	int block;

	block = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] && str[i] != c)
		{
			block++;
			while (str[i] && str[i] != c)
				i++;
		}
		else if (str[i] == c)
			i++;
	}
	return (block);
}

static int		ft_blocklen(const char *str, char c)
{
	int		i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

static void		free_all(char **result)
{
	int		i;

	i = 0;
	while (result[i])
	{
		free(result[i]);
		i++;
	}
}

static void		fill_block(char const *s, char c, char **result)
{
	int			i;
	int			j;

	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		j = 0;
		if (*s && *s != c)
		{
			if (!(result[i] = (char *)malloc(sizeof(char)
							* (ft_blocklen(s, c) + 1))))
				return (free_all(result));
			while (*s && *s != c)
			{
				result[i][j] = (char)*s;
				j++;
				s++;
			}
			result[i][j] = '\0';
			i++;
		}
	}
}

char			**ft_split(char const *s, char c)
{
	char		**result;
	size_t		n;

	if (!s)
		return (NULL);
	n = ft_countblock(s, c);
	if (!(result = (char **)malloc(sizeof(char *)
					* (n + 1))))
		return (0);
	result[n] = 0;
	fill_block(s, c, result);
	return (result);
}
