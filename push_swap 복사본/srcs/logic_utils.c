/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 19:56:11 by sujilee           #+#    #+#             */
/*   Updated: 2022/01/25 04:59:34 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		get_pivot(t_stack **stack, int size)
{
	int		max;
	int		min;
	t_stack	*temp;

	temp = *stack;
	max = temp->data;
	min = temp->data;
	while (size-- > 0)
	{
		if (max < temp->data)
			max = temp->data;
		else if (min > temp->data)
			min = temp->data;
		temp = temp->next;
	}
	return (max + min) / 2;
}

void	attach_unsorted(t_carrier *carrier, t_stack **a, t_stack **b, char c)
{
	t_stack *temp;

	temp = (t_stack*)malloc(sizeof(t_stack) * 1);
	if (temp == 0)
	{
		while (carrier->a_remnant != 0)
		{
			temp = carrier->a_remnant;
			carrier->a_remnant = carrier->a_remnant->next;
			free(temp);
		}
		while (carrier->b_remnant != 0)
		{
			temp = carrier->b_remnant;
			carrier->b_remnant = carrier->b_remnant->next;
			free(temp);
		}
		print_error(a, b, 0);
	}
	// temp->data = c == 'a' ? carrier->rra_cnt : carrier->rrb_cnt;
	// temp->next = c == 'a' ? carrier->a_remnant : carrier->b_remnant;
	if (c == 'a')
		temp->data = carrier->rra_cnt;
	else
		temp->data = carrier->rrb_cnt;

	if (c == 'a')
		temp->next = carrier->a_remnant;
	else
		temp->next = carrier->b_remnant;

	if (c == 'a')
		carrier->a_remnant = temp;
	else
		carrier->b_remnant = temp;
}


void	pivoting_a(t_carrier *carrier, t_stack **a, t_stack **b, int pivot)
{
	t_stack *p;

	while (carrier->a_cnt > 0)
	{
		p = *a;
		if (p->data <= pivot)
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

void	pivoting_b(t_carrier *carrier, t_stack **a, t_stack **b, int pivot)
{
	t_stack *p;

	while (carrier->b_cnt > 0)
	{
		p = *b;
		if (p->data <= pivot)
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