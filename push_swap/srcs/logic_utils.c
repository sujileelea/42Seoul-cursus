/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 19:56:11 by sujilee           #+#    #+#             */
/*   Updated: 2022/01/31 11:53:31 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_pivot(t_stack **stack, int num)
{
	int		max;
	int		min;
	t_stack	*curr;

	curr = *stack;
	max = curr->data;
	min = curr->data;
	while (num-- > 0)
	{
		if (max < curr->data)
			max = curr->data;
		else if (min > curr->data)
			min = curr->data;
		curr = curr->next;
	}
	return ((max + min) / 2);
}

void	attach_unsorted(t_carrier *carrier, t_stack **a, t_stack **b, char c)
{
	t_stack	*curr;

	curr = (t_stack *)malloc(sizeof(t_stack) * 1);
	if (curr == 0)
	{
		while (carrier->a_remnant != 0)
		{
			curr = carrier->a_remnant;
			carrier->a_remnant = carrier->a_remnant->next;
			free(curr);
		}
		while (carrier->b_remnant != 0)
		{
			curr = carrier->b_remnant;
			carrier->b_remnant = carrier->b_remnant->next;
			free(curr);
		}
		print_error(a, b, 0);
	}
	check_ab(carrier, curr, c);
}

void	pivoting_a(t_carrier *carrier, t_stack **a, t_stack **b, int pivot)
{
	t_stack	*curr;

	while (carrier->a_cnt > 0)
	{
		curr = *a;
		if (curr->data <= pivot)
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
	t_stack	*curr;

	while (carrier->b_cnt > 0)
	{
		curr = *b;
		if (curr->data <= pivot)
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
