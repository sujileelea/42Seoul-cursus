/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 19:55:45 by sujilee           #+#    #+#             */
/*   Updated: 2022/01/31 11:55:11 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handle_one_two_a(t_carrier *carrier, t_stack **a)
{
	t_stack	*curr;

	curr = carrier->b_remnant;
	if (curr != 0)
	{
		carrier->b_cnt = carrier->b_remnant->data;
		carrier->b_remnant = carrier->b_remnant->next;
	}
	free(curr);
	if (carrier->a_cnt == 1)
	{
		ra(a, 0);
		carrier->a_cnt = 0;
		return ;
	}
	curr = *a;
	if (curr->data > (curr->next)->data)
		sa(a, 0);
	ra(a, 0);
	ra(a, 0);
	carrier->a_cnt = 0;
}

void	handle_one_two_b(t_carrier *carrier, t_stack **a, t_stack **b)
{
	t_stack	*curr;

	carrier->pb_cnt -= carrier->b_cnt;
	carrier->a_cnt = carrier->a_remnant->data;
	curr = carrier->a_remnant;
	carrier->a_remnant = carrier->a_remnant->next;
	free(curr);
	if (carrier->b_cnt == 1)
	{
		pa(a, b);
		ra(a, 0);
		carrier->b_cnt = 0;
		return ;
	}
	curr = *b;
	if (curr->data > (curr->next)->data)
		sb(b, 0);
	pa(a, b);
	ra(a, 0);
	pa(a, b);
	ra(a, 0);
	carrier->b_cnt = 0;
}

void	b_to_a(t_carrier *carrier, t_stack **a, t_stack **b)
{
	int	pivot;

	if (carrier->b_cnt < 3)
	{
		handle_one_two_b(carrier, a, b);
		return ;
	}
	pivot = get_pivot(b, carrier->b_cnt);
	pivoting_b(carrier, a, b, pivot);
	attach_unsorted(carrier, a, b, 'b');
	while (carrier->b_remnant->next != 0 && carrier->rrb_cnt > 0)
	{
		rrb(b, 0);
		carrier->rrb_cnt--;
	}
	carrier->rrb_cnt = 0;
}

void	a_to_b(t_carrier *carrier, t_stack **a, t_stack **b)
{
	int		pivot;
	t_stack	*curr;

	if (carrier->a_cnt < 3)
	{
		handle_one_two_a(carrier, a);
		return ;
	}
	if (carrier->a_cnt == carrier->argc)
		pivot = (carrier->min + carrier->max) / 2;
	else
		pivot = get_pivot(a, carrier->a_cnt);
	pivoting_a(carrier, a, b, pivot);
	attach_unsorted(carrier, a, b, 'a');
	curr = *a;
	while (carrier->rra_cnt > 0 && (carrier->a_remnant->next != 0
			|| curr->data == carrier->min))
	{
		rra(a, 0);
		carrier->rra_cnt--;
	}
	carrier->rra_cnt = 0;
}