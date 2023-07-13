/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 14:57:13 by okwon             #+#    #+#             */
/*   Updated: 2022/02/25 19:24:28 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, int n)
{
	unsigned char	*uc_s1;
	unsigned char	*uc_s2;
	int				i;

	uc_s1 = (unsigned char *)s1;
	uc_s2 = (unsigned char *)s2;
	i = 0;
	while (i < n && uc_s1[i] && uc_s2[i])
	{
		if (uc_s1[i] != uc_s2[i])
			return (uc_s1[i] - uc_s2[i]);
		++i;
	}
	if (i == n)
		return (0);
	return (uc_s1[i] - uc_s2[i]);
}
