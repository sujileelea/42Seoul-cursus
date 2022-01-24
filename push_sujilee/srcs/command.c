/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 22:04:01 by sujilee           #+#    #+#             */
/*   Updated: 2022/01/22 08:01:17 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		pa(t_carrier *carrier, t_stack **a, t_stack **b)
{
	t_stack *b_head;
	t_stack *a_head;

	if (*b != 0)
	{
		b_head = *b;
		*b = b_head->next != 0 ? b_head->next : 0;
		a_head = *a;
		*a = b_head;
		b_head->next = a_head;
	}
	write(1, "pa\n", 3);
}

void		pb(t_carrier *carrier, t_stack **a, t_stack **b)
{
	t_stack *a_head;
	t_stack *b_head;

	a_head = *a;
	*a = a_head->next != 0 ? a_head->next : 0;
	b_head = *b;
	*b = a_head;
	a_head->next = b_head;
	write(1, "pb\n", 3);
}

void		ra(t_stack **a)
{
	t_stack *head;
	t_stack *headNext;
	t_stack *tail;

	head = *a;
	if (head->next != 0)
	{
		headNext = head->next;
		tail = head->prev;

		tail->next = head;
		head->next = 0;
		*a = headNext;
	}
		write(1, "ra\n", 3);
}

void		rb(t_stack **b)
{
	t_stack *head;
	t_stack *headNext;
	t_stack *tail;

	head = *b;
	if (head != 0 && head->next != 0)
	{
		headNext = head->next;
		tail = head->prev;

		tail->next = head;
		head->next = 0;
		*b = headNext;
	}
		write(1, "rb\n", 3);

}

void		rra(t_stack **a)
{
	t_stack *head;
	t_stack *prevTail;
	t_stack *tail;

	head = *a;
	if (head->next != 0)
	{
		tail = head->prev;
		prevTail = tail->prev;
		
		prevTail->next = 0;
		*a = tail;
		tail->next = head;
		head->prev = tail;
	}
		write(1, "rra\n", 4);
}

void		rrb(t_stack **b)
{
	t_stack *head;
	t_stack *prevTail;
	t_stack *tail;

	head = *b;
	if (head != 0 && head->next != 0)
	{
		tail = head->prev;
		prevTail = tail->prev;

		prevTail->next = 0;
		*b = tail;
		tail->next = head;
		head->prev = tail;
	}
		write(1, "rrb\n", 4);

}

void		sa(t_stack **a)
{
	t_stack *head;
	t_stack *headNext;
	t_stack *headNextNext;

	head = *a;
	if (head->next != 0)
	{
		headNext = head->next;
		headNextNext = headNext->next;
		*a = headNext;
		headNext->next = head;
		head->next = headNextNext;
	}
		write(1, "sa\n", 3);
}

void		sb(t_stack **b)
{
	t_stack *head;
	t_stack *headNext;
	t_stack *headNextNext;

	head = *b;
	if (head != 0 && head->next != 0)
	{
		headNext = head->next;
		headNextNext = headNext->next;
		*b = headNext;
		headNext->next = head;
		head->next = headNextNext;
	}
		write(1, "sb\n", 3);
}
