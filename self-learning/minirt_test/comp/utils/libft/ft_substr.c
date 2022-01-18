/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 20:18:35 by sujilee           #+#    #+#             */
/*   Updated: 2020/11/17 17:50:15 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t n)
{
	char	*result;
	size_t	i;
	size_t	s_size;

	if (!s)
		return (0);
	s_size = ft_strlen(s);
	result = (char *)malloc(sizeof(char) * (n + 1));
	if (!result)
		return (0);
	i = 0;
	if (start < s_size)
	{
		while (i < n)
		{
			result[i] = s[start + i];
			i++;
		}
	}
	result[i] = '\0';
	return (result);
}
