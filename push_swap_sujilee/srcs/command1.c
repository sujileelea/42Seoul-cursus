/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 19:43:52 by sujilee           #+#    #+#             */
/*   Updated: 2022/01/27 13:57:38 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*b_head;
	t_stack	*a_head;

	if (*b != 0)
	{
		b_head = *b;
		if (b_head->next != 0)
			*b = b_head->next;
		else
			*b = 0;
		a_head = *a;
		*a = b_head;
		b_head->next = a_head;
	}
	write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b)
{
	t_stack	*a_head;
	t_stack	*b_second;

	a_head = *a;
	if (a_head->next != 0)
		*a = a_head->next;
	else
		*a = 0;
	b_second = *b;
	*b = a_head;
	a_head->next = b_second;
	write(1, "pb\n", 3);
}

void	sa(t_stack **a, char is_ss)
{
	t_stack	*p;
	t_stack	*top;
	t_stack	*second;

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
	t_stack	*p;
	t_stack	*top;
	t_stack	*second;

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
