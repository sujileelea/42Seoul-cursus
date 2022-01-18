/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 21:10:07 by sujilee           #+#    #+#             */
/*   Updated: 2020/11/03 22:16:32 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int		ft_nbrlen(int n)
{
	int	nbrlen;

	nbrlen = 0;
	if (n <= 0)
	{
		nbrlen += 1;
		n *= -1;
	}
	while (n)
	{
		n = n / 10;
		nbrlen++;
	}
	return (nbrlen);
}

char	*ft_itoa(int n)
{
	char	*result;
	size_t	len;

	len = ft_nbrlen(n);
	if (!(result = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	result[len] = '\0';
	if (n < 0)
	{
		result[0] = '-';
		while (len - 1)
		{
			result[len - 1] = '0' - n % 10;
			n /= 10;
			len--;
		}
	}
	else
		while (len >= 1)
		{
			result[len - 1] = n % 10 + '0';
			n /= 10;
			len--;
		}
	return (result);
}
