/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 15:22:54 by okwon             #+#    #+#             */
/*   Updated: 2022/03/10 16:20:03 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_start(char const *s1, char const *set)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(s1) && ft_strchr(set, s1[i]))
		++i;
	return (i);
}

static size_t	get_end(char const *s1, char const *set)
{
	size_t	i;

	i = ft_strlen(s1) - 1;
	while (i > 0 && ft_strchr(set, s1[i]))
		--i;
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	s;
	size_t	e;
	size_t	rl;
	char	*rslt;

	if (!s1)
		return (0);
	if (!set)
		return (ft_strdup(s1));
	s = get_start(s1, set);
	e = get_end(s1, set);
	if (s > e)
		return (ft_strdup(""));
	rl = e - s + 2;
	rslt = (char *)malloc(rl * sizeof(char));
	if (!rslt)
		return (0);
	ft_strlcpy(rslt, s1 + s, rl);
	return (rslt);
}
