/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 17:22:27 by sujilee           #+#    #+#             */
/*   Updated: 2022/01/20 14:22:34 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	pa(t_carrier *carrier, t_stack **a, t_stack **b)
{
	t_stack *b_top;
	t_stack *a_second;

	if (*b != 0)
	{
		b_top = *b;
		*b = b_top->next != 0 ? b_top->next : 0;
		a_second = *a;
		*a = b_top;
		b_top->next = a_second;
	}
}

void	pb(t_carrier *carrier, t_stack **a, t_stack **b)
{
	t_stack *a_top;
	t_stack *b_second;

	a_top = *a;
	*a = a_top->next != 0 ? a_top->next : 0;
	b_second = *b;
	*b = a_top;
	a_top->next = b_second;
}

void	ra(t_stack **a)
{
	t_stack *top;
	t_stack *second;
	t_stack *bottom;

	top = *a;
	if (top->next != 0)
	{
		second = top->next;
		bottom = top->next;
		while (bottom->next != 0)
			bottom = bottom->next;
		bottom->next = top;
		top->next = 0;
		*a = second;
	}
}

void	rb(t_stack **b)  
{
	t_stack *top;
	t_stack *second;
	t_stack *bottom;

	top = *b;
	if (top != 0 && top->next != 0)
	{
		second = top->next;
		bottom = top->next;
		while (bottom->next != 0)
			bottom = bottom->next;
		bottom->next = top;
		top->next = 0;
		*b = second;
	}
}

void	rra(t_stack **a)
{
	t_stack *top;
	t_stack *pre_bottom;
	t_stack *bottom;

	top = *a;
	if (top->next != 0)
	{
		bottom = top;
		while ((bottom->next)->next != 0)
			bottom = bottom->next;
		pre_bottom = bottom;
		bottom = bottom->next;
		pre_bottom->next = 0;
		*a = bottom;
		bottom->next = top;
	}
}


void	rrb(t_stack **b)
{
	t_stack *top;
	t_stack *pre_bottom;
	t_stack *bottom;

	top = *b;
	if (top != 0 && top->next != 0)
	{
		bottom = top;
		while ((bottom->next)->next != 0)
			bottom = bottom->next;
		pre_bottom = bottom;
		bottom = bottom->next;
		pre_bottom->next = 0;
		*b = bottom;
		bottom->next = top;
	}
}

void	sa(t_stack **a)
{
	t_stack *p;
	t_stack *top;
	t_stack *second;

	second = *a;
	if (second->next != 0)
	{
		top = second->next;
		p = top->next;
		*a = top;
		top->next = second;
		second->next = p;
	}
		write(1, "sa\n", 3);
}

void	sb(t_stack **b)
{
	t_stack *p;
	t_stack *top;
	t_stack *second;

	second = *b;
	if (second != 0 && second->next != 0)
	{
		top = second->next;
		p = top->next;
		*b = top;
		top->next = second;
		second->next = p;
	}
		write(1, "sb\n", 3);
}