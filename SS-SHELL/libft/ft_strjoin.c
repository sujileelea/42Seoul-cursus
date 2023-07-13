/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 14:54:29 by okwon             #+#    #+#             */
/*   Updated: 2022/03/10 16:22:59 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(void const *s1, void const *s2)
{
	size_t	r_len;
	size_t	check;
	char	*rslt;

	if (!s1 && !s2)
		return (0);
	else if (!s1 || !s2)
	{
		if (!s1)
			return (ft_strdup(s2));
		else
			return (ft_strdup(s1));
	}
	r_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	rslt = (char *)malloc(r_len * sizeof(char));
	if (!rslt)
		return (0);
	check = ft_strlcpy(rslt, s1, r_len);
	ft_strlcat(rslt + check, s2, r_len);
	return (rslt);
}
