/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 16:43:22 by sujilee           #+#    #+#             */
/*   Updated: 2020/10/09 17:31:32 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*arr;
	unsigned char	ch;

	i = 0;
	arr = b;
	ch = c;
	while (i < len)
	{
		arr[i] = ch;
		i++;
	}
	return (b);
}
