/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okwon <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 14:55:18 by okwon             #+#    #+#             */
/*   Updated: 2022/03/10 16:19:26 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	s_len;
	size_t	i;

	if (!src)
		return (0);
	s_len = ft_strlen(src);
	if (!dst || !dstsize)
		return (s_len);
	i = 0;
	while (i < s_len && i + 1 < dstsize)
	{
		dst[i] = src[i];
		++i;
	}
	dst[i] = 0;
	return (s_len);
}
