/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okwon <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 14:54:48 by okwon             #+#    #+#             */
/*   Updated: 2022/03/10 16:19:13 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	d_len;
	size_t	s_len;
	size_t	i;

	d_len = ft_strlen(dst);
	s_len = ft_strlen(src);
	if (d_len > dstsize)
		return (dstsize + s_len);
	i = 0;
	while (src[i] && d_len + i + 1 < dstsize)
	{
		dst[d_len + i] = src[i];
		++i;
	}
	dst[d_len + i] = 0;
	return (d_len + s_len);
}
