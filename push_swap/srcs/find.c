/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 22:03:26 by sujilee           #+#    #+#             */
/*   Updated: 2022/01/28 11:47:01 by sujilee          ###   ########.fr       */
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
	t_stack	*curr;

	if (carrier->argc != 3)
	{
		carrier->max = -2147483648;
		carrier->min = 2147483647;
		curr = *a;
		while (curr)
		{
			carrier->max = find_max(curr->data, carrier->max);
			carrier->min = find_min(curr->data, carrier->min);
			curr = curr->next;
		}
	}
}
