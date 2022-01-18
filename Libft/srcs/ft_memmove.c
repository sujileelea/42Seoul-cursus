/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 20:43:43 by sujilee           #+#    #+#             */
/*   Updated: 2020/10/15 22:36:09 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src,
		size_t len)
{
	unsigned char	*dest;
	unsigned char	*org;
	size_t			i;

	dest = (unsigned char *)dst;
	org = (unsigned char *)src;
	i = 0;
	if (src == dst)
		return (0);
	if (src > dst)
		while (i < len)
		{
			dest[i] = org[i];
			i++;
		}
	else
		while (len)
		{
			dest[len - 1] = org[len - 1];
			len--;
		}
	return (dst);
}
