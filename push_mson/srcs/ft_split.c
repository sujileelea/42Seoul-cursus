/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 20:14:36 by mson              #+#    #+#             */
/*   Updated: 2022/01/14 12:37:36 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		ft_check(char s, char c)
{
	if (s == c)
		return (1);
	return (0);
}

static int		ft_size(const char *str, char c)
{
	int size;
	int index;

	size = 0;
	index = 0;
	while (str[index])
	{
		while (str[index] && ft_check(str[index], c))
			index++;
		if (str[index] && !ft_check(str[index], c))
		{
			while (str[index] && !ft_check(str[index], c))
				index++;
			size++;
		}
	}
	return (size);
}

static char		*ft_input(const char *str, char c)
{
	int		index;
	int		count;
	char	*input;

	index = 0;
	count = 0;
	while (str[count] && !ft_check(str[count], c))
		count++;
	if (!(input = (char *)malloc(sizeof(char) * (count + 1))))
		return (NULL);
	while (str[index] && !ft_check(str[index], c))
	{
		input[index] = str[index];
		index++;
	}
	input[index] = 0;
	return (input);
}

static char		**free_all(char **result, int index)
{
	while (index-- >= 0)
		free((void *)result[index]);
	free(result);
	return (NULL);
}

char			**ft_split(char const *s, char c)
{
	char	**result;
	int		index;

	if (!s)
		return (NULL);
	if (!(result = (char **)malloc(sizeof(char *) * (ft_size(s, c) + 1))))
		return (NULL);
	index = 0;
	while (*s)
	{
		while (*s && ft_check(*s, c))
			s++;
		if (*s && !ft_check(*s, c))
		{
			result[index] = ft_input(s, c);
			if (!result[index])
				return (free_all(result, index));
			while (*s && !ft_check(*s, c))
				s++;
			index++;
		}
	}
	result[index] = 0;
	return (result);
}
