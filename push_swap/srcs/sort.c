/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 19:49:53 by sujilee           #+#    #+#             */
/*   Updated: 2022/01/28 11:28:43 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_descending(t_carrier *carrier, t_stack **a)
{
	int		before;
	t_stack	*curr;

	curr = *a;
	if (curr->data != carrier->max)
		return (0);
	before = curr->data;
	curr = curr->next;
	while (curr != 0)
	{
		if (before < curr->data)
			return (0);
		before = curr->data;
		curr = curr->next;
	}
	return (1);
}

int	sort_descending(t_carrier *carrier, t_stack **a, t_stack **b)
{
	int	i;

	i = carrier->argc;
	pb(a, b);
	while (--i > 0)
	{
		pb(a, b);
		rb(b, 0);
	}
	i = carrier->argc;
	while (i-- > 0)
		pa(a, b);
	return (1);
}

void	sort_three(t_carrier *carrier, t_stack **a)
{
	int		before;
	t_stack	*curr;

	find_three(carrier, a);
	curr = *a;
	before = curr->data;
	curr = curr->next;
	if ((before == carrier->min && curr->data == carrier->max)
		|| (before == carrier->max && curr->data != carrier->min)
		|| (before != carrier->max && curr->data == carrier->min))
		sa(a, 0);
	curr = *a;
	before = curr->data;
	curr = curr->next;
	if (before == carrier->max && curr->data == carrier->min)
		ra(a, 0);
	else if (before != carrier->min && curr->data == carrier->max)
		rra(a, 0);
	return ;
}

void	sort_five(t_carrier *carrier, t_stack **a, t_stack **b)
{
	t_stack	*curr;

	while (carrier->argc--)
	{
		curr = *a;
		if (curr->data == carrier->max || curr->data == carrier->min)
			pb(a, b);
		else
			ra(a, 0);
	}
	sort_three(carrier, a);
	if ((*b)->data < (*b)->next->data)
		sb(b, 0);
	pa(a, b);
	ra(a, 0);
	pa(a, b);
	return ;
}

void	sort_many(t_carrier *carrier, t_stack **a, t_stack **b)
{
	carrier->a_cnt = carrier->argc;
	if ((is_sorted(a)) == 1)
		return ;
	if ((is_descending(carrier, a)) == 1
		&& (sort_descending(carrier, a, b)) == 1)
		return ;
	while (carrier->a_cnt != 0)
	{
		a_to_b(carrier, a, b);
		if (carrier->pb_cnt == 0)
			continue ;
		b_to_a(carrier, a, b);
	}
}
