/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 14:28:05 by okwon             #+#    #+#             */
/*   Updated: 2022/03/10 16:23:37 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(void const *s, unsigned int start, size_t len)
{
	char	*rslt;
	size_t	r_len;
	size_t	s_len;

	if (!s)
		return (0);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	s_len -= start;
	if (len > s_len)
		r_len = s_len;
	else
		r_len = len;
	++r_len;
	rslt = (char *)malloc(r_len * sizeof(char));
	if (!rslt)
		return (0);
	ft_strlcpy(rslt, s + start, r_len);
	return (rslt);
}
