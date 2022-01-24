/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 19:49:53 by sujilee           #+#    #+#             */
/*   Updated: 2022/01/24 19:55:17 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	arrange_five_digits2(t_stack **a)
{
	t_stack *top;
	t_stack *second;
	t_stack *bottom;

	top = *a;
	second = top->next;
	bottom = top->next;
	while (bottom->next != 0)
		bottom = bottom->next;
	if (top->data > bottom->data && bottom->data > second->data)
		ra(a, 0);
	else if (bottom->data > top->data && top->data > second->data)
		sa(a, 0);
	else if (second->data > top->data && top->data > bottom->data)
		sa(a, 0);
	else if (top->data > second->data && second->data > bottom->data)
	{
		ra(a, 0);
		sa(a, 0);
	}
	else
	{
		rra(a, 0);
		sa(a, 0);
	}
}

void	arrange_five_digits(t_carrier *carrier, t_stack **a, t_stack **b)
{
	t_stack *p;

	carrier->pb_cnt = 0;
	while (1)
	{
		p = *a;
		if (p->data == carrier->max && (is_sorted(&p->next)) == 1)
			ra(a, 0);
		else if (*b != 0 && (is_sorted(a)) == 1)
		{
			pa(a, b);
			carrier->pb_cnt--;
		}
		else if (p->data == carrier->min || p->data == carrier->max)
		{
			pb(a, b);
			carrier->pb_cnt++;
		}
		else if (carrier->pb_cnt < 2)
			ra(a, 0);
		else
			arrange_five_digits2(a);
		if (*b == 0 && (is_sorted(a)) == 1)
			return ;
	}
}

int		is_descending(t_carrier *carrier, t_stack **a)
{
	int		before;
	t_stack *p;

	p = *a;
	if (p->data != carrier->max)
		return (0);
	before = p->data;
	p = p->next;
	while (p != 0)
	{
		if (before < p->data)
			return (0);
		before = p->data;
		p = p->next;
	}
	return (1);
}

int		sort_descending(t_carrier *carrier, t_stack **a, t_stack **b)
{
	int i;

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

void	sort_many(t_carrier *carrier, t_stack **a, t_stack **b)
{
	carrier->a_cnt = carrier->argc;
	if ((is_sorted(a)) == 1)
		return ;
	if ((is_descending(carrier, a)) == 1 && (sort_descending(carrier, a, b)) == 1)
		return ;
	while (carrier->a_cnt != 0)
	{
		a_to_b(carrier, a, b);
		if (carrier->pb_cnt == 0)
			continue ;
		b_to_a(carrier, a, b);
	}
}
