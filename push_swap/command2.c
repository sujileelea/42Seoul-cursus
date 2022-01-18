/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 13:22:50 by sujilee           #+#    #+#             */
/*   Updated: 2021/11/11 17:41:55 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ra(t_stack **a, char is_rr, char is_checker)
{
	t_stack *top;
	t_stack *second;
	t_stack *bottom;

	top = *a;
	if (top->next)
	{
		second = top->next;
		bottom = top->next;
		while(bottom->next)
			bottom = bottom->next;
		*a = second;
		bottom->next = top;
		top->next = 0;
	}
	if (is_rr == 0 && is_checker == 0)
		write(1, "ra\n", 3);
}

void	rb(t_stack **b, char is_rr, char is_checker)
{
	t_stack *top;
	t_stack *second;
	t_stack *bottom;

	top = *a;
	if (top->next)
	{
		second = top->next;
		bottom = top->next;
		while (bottom->next)
			bottom = bottom->next;
		*a = second;
		bottom->next = top;
		top->next = 0;
	}
	if (is_rr == 0 && is_checker == 0)
		write(1, "rb\n", 3);
	else if (is_checker == 0)
		write(1, "rr\n", 3);
}

void	rra(t_stack **a, char is_rrr, char is_checker)
{
	t_stack	*top;
	t_stack *before_bottom;
	t_stack	*bottom;

	top = *a;
	if (top->next)
	{
		// bottom = top;
		// while ((bottom->next)->next != 0)
		// 	bottom = bottom->next;
		// pre_bottom = bottom;
		// bottom = bottom->next;
		// pre_bottom->next = 0;
		// *a = bottom;
		// bottom->next = top;
		
		before_bottom = top->next;
		while ((before_bottom->next)->next)
			before_bottom = before_bottom->next;
		bottom = before_bottom->next;
		*a = bottom;
		bottom->next =top;
		before_bottom->next = 0;
	}
	if (is_rrr == 0 && is_checker == 0)
		write(1, "rra\n", 4);
}

void	rrb(t_stack **b, char is_rrr, char is_checker)
{
	t_stack	*top;
	t_stack	*before_bottom;
	t_stack	*bottom;

	top = *b;
	if (top && top->next)
	{
		// bottom = top;
		// while ((bottom->next)->next != 0)
		// 	bottom = bottom->next;
		// pre_bottom = bottom;
		// bottom = bottom->next;
		// pre_bottom->next = 0;
		// *b = bottom;
		// bottom->next = top;
		
		before_bottom = top->next;
		while ((before_bottom->next)->next)
			before_bottom = before_bottom->next;
		bottom = before_bottom->next;
		*a = bottom;
		bottom->next = top;
		before_bottom->next = 0;
	}
	if (is_rrr == 0 && is_checker == 0)
		write(1, "rrb\n", 4);
	else if (is_checker == 0)
		wrtie(1, "rrr\n", 4);
}