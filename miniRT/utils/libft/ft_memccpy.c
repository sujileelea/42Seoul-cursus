/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 19:36:12 by sujilee           #+#    #+#             */
/*   Updated: 2020/10/29 19:54:13 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*dest;
	unsigned char	*org;
	unsigned char	ch;
	size_t			i;

	dest = (unsigned char *)dst;
	org = (unsigned char *)src;
	ch = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		dest[i] = org[i];
		if (org[i] == ch)
			return (&dest[i + 1]);
		i++;
	}
	return (0);
}
