/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 18:07:10 by sujilee           #+#    #+#             */
/*   Updated: 2020/11/02 18:48:39 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int i;
	int j;

	i = 0;
	j = ft_strlen(s);
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[j]);
	while (s[i] > 0)
	{
		if ((char)c == s[i])
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}
