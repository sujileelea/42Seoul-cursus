/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 17:35:02 by okwon             #+#    #+#             */
/*   Updated: 2022/03/10 16:23:20 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_len(long long n)
{
	size_t		l;

	l = 1;
	if (n < 0)
	{
		n *= -1;
		l += 1;
	}
	while (n >= 10)
	{
		n /= 10;
		++l;
	}
	return (l);
}

char	*ft_itoa(int n)
{
	long long	lln;
	int			l;
	char		*r;

	if (!n)
		return (r = ft_strdup("0"));
	l = get_len((long long)n);
	r = (char *)malloc((l + 1) * sizeof(char));
	if (!r)
		return (0);
	r[l] = 0;
	if (n < 0)
		lln = (long long)n * -1;
	else
		lln = (long long)n;
	while (--l)
	{
		r[l] = lln % 10 + '0';
		lln /= 10;
	}
	if (n < 0)
		r[0] = '-';
	else
		r[0] = lln % 10 + '0';
	return (r);
}
