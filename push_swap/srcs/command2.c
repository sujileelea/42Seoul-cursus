/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 13:43:51 by sujilee           #+#    #+#             */
/*   Updated: 2022/01/28 13:31:58 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **a, char is_rr)
{
	t_stack	*head;
	t_stack	*headNext;
	t_stack	*tail;

	head = *a;
	if (head->next != 0)
	{
		headNext = head->next;
		tail = head->next;
		while (tail->next != 0)
			tail = tail->next;
		tail->next = head;
		head->next = 0;
		*a = headNext;
	}
	if (is_rr == 0)
		write(1, "ra\n", 3);
}

void	rb(t_stack **b, char is_rr)
{
	t_stack	*head;
	t_stack	*second;
	t_stack	*bottom;

	head = *b;
	if (head != 0 && head->next != 0)
	{
		second = head->next;
		bottom = head->next;
		while (bottom->next != 0)
			bottom = bottom->next;
		bottom->next = head;
		head->next = 0;
		*b = second;
	}
	if (is_rr == 0)
		write(1, "rb\n", 3);
	else
		write(1, "rr\n", 3);
}

void	rra(t_stack **a, char is_rrr)
{
	t_stack	*head;
	t_stack	*prevTail;
	t_stack	*tail;

	head = *a;
	if (head->next != 0)
	{
		tail = head;
		while ((tail->next)->next != 0)
			tail = tail->next;
		prevTail = tail;
		tail = tail->next;
		prevTail->next = 0;
		*a = tail;
		tail->next = head;
	}
	if (is_rrr == 0)
		write(1, "rra\n", 4);
}

void	rrb(t_stack **b, char is_rrr)
{
	t_stack	*head;
	t_stack	*prevTail;
	t_stack	*tail;

	head = *b;
	if (head != 0 && head->next != 0)
	{
		tail = head;
		while ((tail->next)->next != 0)
			tail = tail->next;
		prevTail = tail;
		tail = tail->next;
		prevTail->next = 0;
		*b = tail;
		tail->next = head;
	}
	if (is_rrr == 0)
		write(1, "rrb\n", 4);
	else
		write(1, "rrr\n", 4);
}
