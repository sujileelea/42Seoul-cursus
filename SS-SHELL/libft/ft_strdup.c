/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okwon <okwon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 14:53:46 by okwon             #+#    #+#             */
/*   Updated: 2021/06/14 20:33:20 by okwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const void *s)
{
	char	*s1;
	char	*dupstr;
	size_t	s_len;

	s1 = (char *)s;
	s_len = ft_strlen(s1);
	dupstr = (char *)malloc(sizeof(char) * (s_len + 1));
	if (!dupstr)
		return (0);
	ft_strlcpy(dupstr, s1, (s_len + 1));
	return (dupstr);
}
