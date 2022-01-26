/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 22:03:26 by sujilee           #+#    #+#             */
/*   Updated: 2022/01/24 22:05:14 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max(int old, int new)
{
	int	max;

	max = old;
	if (old < new)
		max = new;
	return (max);
}

int	find_min(int old, int new)
{
	int	min;

	min = old;
	if (old > new)
		min = new;
	return (min);
}

void	find_three(t_carrier *carrier, t_stack **a)
{
	t_stack	*p;

	if (carrier->argc != 3)
	{
		carrier->max = -2147483648;
		carrier->min = 2147483647;
		p = *a;
		while (p)
		{
			carrier->max = find_max(p->data, carrier->max);
			carrier->min = find_min(p->data, carrier->min);
			p = p->next;
		}
	}
}
