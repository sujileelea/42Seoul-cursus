/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 20:09:36 by sujilee           #+#    #+#             */
/*   Updated: 2020/10/08 22:07:59 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*arr;
	unsigned char	ch;

	i = 0;
	arr = (unsigned char *)s;
	ch = c;
	while (i < n)
	{
		if (arr[i] == ch)
			return (&arr[i]);
		i++;
	}
	return (0);
}
