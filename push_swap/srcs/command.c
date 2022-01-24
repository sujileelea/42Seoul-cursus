/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 19:43:52 by sujilee           #+#    #+#             */
/*   Updated: 2022/01/24 19:49:39 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack **a, t_stack **b)
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
	write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b)
{
	t_stack *a_top;
	t_stack *b_second;

	a_top = *a;
	*a = a_top->next != 0 ? a_top->next : 0;
	b_second = *b;
	*b = a_top;
	a_top->next = b_second;
	write(1, "pb\n", 3);
}

void	sa(t_stack **a, char is_ss)
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
	if (is_ss == 0)
		write(1, "sa\n", 3);
}

void	sb(t_stack **b, char is_ss)
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
	if (is_ss == 0)
		write(1, "sb\n", 3);
	else
		write(1, "ss\n", 3);
}


void	ra(t_stack **a, char is_rr)
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
	if (is_rr == 0)
		write(1, "ra\n", 3);
}

void	rb(t_stack **b, char is_rr)
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
	if (is_rr == 0)
		write(1, "rb\n", 3);
	else
		write(1, "rr\n", 3);
}

void	rra(t_stack **a, char is_rrr)
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
	if (is_rrr == 0)
		write(1, "rra\n", 4);
}

void	rrb(t_stack **b, char is_rrr)
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
	if (is_rrr == 0)
		write(1, "rrb\n", 4);
	else
		write(1, "rrr\n", 4);
}