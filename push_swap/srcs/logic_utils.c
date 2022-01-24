/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 19:56:11 by sujilee           #+#    #+#             */
/*   Updated: 2022/01/24 20:04:14 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		get_pivot(t_stack **p, int num)
{
	int		max;
	int		min;
	t_stack	*t;

	t = *p;
	max = t->data;
	min = t->data;
	while (num-- > 0)
	{
		if (max < t->data)
			max = t->data;
		else if (min > t->data)
			min = t->data;
		t = t->next;
	}
	return (max + min) / 2;
}

void	attach_unsorted(t_carrier *carrier, t_stack **a, t_stack **b, char c)
{
	t_stack *t;

	t = (t_stack*)malloc(sizeof(t_stack) * 1);
	if (t == 0)
	{
		while (carrier->a_remnant != 0)
		{
			t = carrier->a_remnant;
			carrier->a_remnant = carrier->a_remnant->next;
			free(t);
		}
		while (carrier->b_remnant != 0)
		{
			t = carrier->b_remnant;
			carrier->b_remnant = carrier->b_remnant->next;
			free(t);
		}
		print_error(a, b, 0);
	}
	t->data = c == 'a' ? carrier->rra_cnt : carrier->rrb_cnt;
	t->next = c == 'a' ? carrier->a_remnant : carrier->b_remnant;
	if (c == 'a')
		carrier->a_remnant = t;
	else
		carrier->b_remnant = t;
}


void	pivoting_a(t_carrier *carrier, t_stack **a, t_stack **b, int mid)
{
	t_stack *p;

	while (carrier->a_cnt > 0)
	{
		p = *a;
		if (p->data <= mid)
		{
			pb(a, b);
			carrier->pb_cnt++;
			carrier->b_cnt++;
		}
		else
		{
			ra(a, 0);
			carrier->rra_cnt++;
		}
		carrier->a_cnt--;
	}
}

void	pivoting_b(t_carrier *carrier, t_stack **a, t_stack **b, int mid)
{
	t_stack *p;

	while (carrier->b_cnt > 0)
	{
		p = *b;
		if (p->data <= mid)
		{
			pa(a, b);
			carrier->pb_cnt--;
			carrier->a_cnt++;
		}
		else
		{
			rb(b, 0);
			carrier->rrb_cnt++;
		}
		carrier->b_cnt--;
	}
}