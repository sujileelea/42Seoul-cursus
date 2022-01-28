/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 19:38:27 by sujilee           #+#    #+#             */
/*   Updated: 2022/01/27 14:18:28 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_split_free(char **s)
{
	int	i;

	i = -1;
	while (s[++i] != 0)
		free(s[i]);
	free(s[i]);
	free(s);
}

void	free_stack(t_stack **a_or_b)
{
	t_stack	*p;
	t_stack	*t;

	if (*a_or_b == 0)
		return ;
	p = *a_or_b;
	while (p != 0)
	{
		t = p->next;
		free(p);
		p = t;
	}
}
