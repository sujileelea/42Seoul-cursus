/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 17:19:47 by sujilee           #+#    #+#             */
/*   Updated: 2020/11/02 18:42:35 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t d;
	size_t s;
	size_t i;

	d = ft_strlen(dst);
	s = ft_strlen(src);
	if (!src)
		return (0);
	if (dstsize == 0)
		return (s);
	if (d >= dstsize)
		return (dstsize + s);
	i = 0;
	while (src[i] && d + i < dstsize - 1)
	{
		dst[d + i] = src[i];
		i++;
	}
	dst[d + i] = '\0';
	return (d + s);
}
