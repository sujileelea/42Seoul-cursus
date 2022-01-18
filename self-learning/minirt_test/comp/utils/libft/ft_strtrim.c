/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 21:09:08 by sujilee           #+#    #+#             */
/*   Updated: 2020/10/31 17:25:57 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		front_index(const char *s1, const char *set)
{
	int		i;

	i = 0;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	return (i);
}

static int		back_index(const char *s1, const char *set)
{
	int		i;

	i = ft_strlen(s1) - 1;
	while (i >= 0 && ft_strchr(set, s1[i]))
		i--;
	return (i);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	size_t	front;
	size_t	back;
	char	*result;

	if (!s1 || !set)
		return (0);
	front = front_index(s1, set);
	back = back_index(s1, set);
	if (front == ft_strlen(s1))
	{
		result = (char *)malloc(sizeof(char) * 1);
		result[0] = '\0';
		return (result);
	}
	else if (!(result = (char *)malloc(sizeof(char) * (back - front + 2))))
		return (0);
	ft_strlcpy(result, s1 + front, back - front + 2);
	return (result);
}
