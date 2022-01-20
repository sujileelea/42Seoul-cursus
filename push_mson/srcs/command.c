/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 17:22:27 by sujilee           #+#    #+#             */
/*   Updated: 2022/01/20 13:42:58 by sujilee          ###   ########.fr       */
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
	write(1, "pa\n", 3);
	return ;
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
	write(1, "pb\n", 3);
	return ;
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
	// t_stack *head;
	// t_stack *headNext;
	// t_stack *tail;
	
	// if (!a)
	// 	exit(1);
	// head = *a;
	// if (head->next)
	// {
	// 	headNext = head->next;
	// 	tail = head->prev;

	// 	*a = headNext;
	// 	tail->next = head;
	// 	head->prev = tail;
	// 	head->next = 0;
	// }
	// write(1, "ra\n", 3);
	// return ;
}

void	rb(t_stack **b)  
{
	t_stack *head;
	t_stack *headNext;
	
	if (!b)
		exit(1);
	head = *b;
	if (head->next)
	{
		headNext = head->next;
		*b = headNext;
		head->prev->next = head;
		head->next = 0;
	}
	write(1, "rb\n", 3);
	return ;
}

void	rra(t_stack **a)
{
	t_stack *head;
	t_stack *tail;

	if (!a)
		exit(1);
	head = *a;
	if (head->next)
	{	
		tail = head->prev;
		tail->prev->next = 0;
		*a = tail;
		tail->next = head;
		
	}
	write(1, "rra\n", 3);
	return ;
}

void	rrb(t_stack **b)
{
	t_stack *head;
	t_stack *tail;

	if (!b)
		exit(1);
	head = *b;
	if (head->next)
	{	
		tail = head->prev;
		tail->prev->next = 0;
		*b = tail;
		tail->next = head;
	}
	write(1, "rrb\n", 3);
	return ;
}

void	sa(t_stack **a)
{
	t_stack *head;
	t_stack *headNextNext;
	t_stack *headNext;
	t_stack *tail;
	head = *a;
	if (head->next != 0)
	{
		tail = head->prev;
		headNext = head->next;
		headNextNext = headNext->next;
		*a = headNext;
		headNext->next = head;
		head->prev = headNext;
		head->next = headNextNext;
		headNextNext->prev = head;
		headNext->prev = tail;
	}
	write(1, "sa\n", 3);
	return ;
}

void	sb(t_stack **b)
{
	t_stack *head;
	t_stack *headNextNext;
	t_stack *headNext;
	t_stack *tail;

	head = *b;
	if (head->next != 0)
	{
		tail = head->prev;
		headNext = head->next;
		headNextNext = headNext->next;
		*b = headNext;
		headNext->next = head;
		head->prev = headNext;
		head->next = headNextNext;
		headNextNext->prev = head;
		headNext->prev = tail;
	}
	write(1, "sb\n", 3);
	return ;
}