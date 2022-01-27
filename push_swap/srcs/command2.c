/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 13:43:51 by sujilee           #+#    #+#             */
/*   Updated: 2022/01/27 13:57:05 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **a, char is_rr)
{
	t_stack	*top;
	t_stack	*second;
	t_stack	*bottom;

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
	t_stack	*top;
	t_stack	*second;
	t_stack	*bottom;

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
	t_stack	*top;
	t_stack	*pre_bottom;
	t_stack	*bottom;

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
	t_stack	*top;
	t_stack	*pre_bottom;
	t_stack	*bottom;

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
