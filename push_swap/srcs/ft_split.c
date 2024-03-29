/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 20:07:19 by sujilee           #+#    #+#             */
/*   Updated: 2022/01/27 19:30:48 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	get_word_num(char const *s, char c)
{
	size_t	num;

	num = 0;
	while (*s != 0)
	{
		if (*s != c && *s != 0)
		{
			num++;
			while (*s != c && *s != 0)
				s++;
		}
		else if (*s != 0)
			s++;
	}
	return (num);
}

static void	split_cpy(char *arr, char *p, char const *s)
{
	while (p < s)
		*arr++ = *p++;
	*arr = 0;
}

static void	free_arr(char **arr, size_t i)
{
	size_t	j;

	j = 0;
	while (j < i)
	{
		free(arr[j]);
		j++;
	}
	free(arr);
	arr = 0;
}

static void	do_split(char **arr, char const *s, char c, size_t i)
{
	char	*p;

	if (*s == 0)
		return ;
	while (*s != 0)
	{
		if (*s != c && *s != 0)
		{
			p = (char *)s;
			while (*s != c && *s != 0)
				s++;
			arr[i] = (char *)malloc(sizeof(char *) * (s - p + 1));
			if (!arr[i])
			{
				free_arr(arr, i);
				return ;
			}
			split_cpy(arr[i], p, s);
			i++;
		}
		else if (*s != 0)
			s++;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	num;

	if (s == 0)
		return ((void *)0);
	num = get_word_num(s, c);
	if (num == 0)
		return ((void *)0);
	arr = (char **)malloc(sizeof(char *) * (num + 1));
	if (arr == 0)
		return ((void *)0);
	arr[num] = 0;
	do_split(arr, s, c, 0);
	return (arr);
}
