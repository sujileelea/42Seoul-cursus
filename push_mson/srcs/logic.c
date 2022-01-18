/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:26:21 by sujilee           #+#    #+#             */
/*   Updated: 2022/01/17 16:23:51 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a_to_b(t_carrier *carrier, t_stack **a, t_stack **b)
{
    int max;
    int min;
    int pivot;
    int i;
    t_stack *curr;

    max = find_max(carrier, a);
    min = find_min(carrier, b);
    i = carrier->a_cnt;
    pivot = (max + min) / 2;
    while (i--)
    {
        curr = *a;
        if (curr->data <= pivot)
        {
            pb(carrier, a, b);
            carrier->pb_num++;
        }
		else if (curr->data > pivot)
		{
			ra(a);
			carrier->arem_cnt++;
        }

		//
		if (carrier->pa_num <= 2)
		{
			//rra();
			//rra_num++;
			//curr = curr->next;
		}

    }
}



void	b_to_a(t_carrier *carrier, t_stack **a, t_stack **b)
{
	int pivot;
	int i;
	int max;
	int min;
	t_stack *curr;

	
	max = find_max(carrier, b);
	min = find_min(carrier, b);
	i = carrier->a_cnt;
	if (carrier->pb_num > 2)
	{
		pivot = (max + min) / 2;
		while (i--)
		{
			curr = *b;
			if (curr->data <= pivot)
			{
				pb(carrier, a, b);
				carrier->pb_num++;
			}
			else if (curr->data > pivot)
			{
				ra(a);
				carrier->arem_cnt++;
			}
		}
	}
}