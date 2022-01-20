/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 12:46:04 by sujilee           #+#    #+#             */
/*   Updated: 2022/01/20 13:02:26 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_carrier *carrier, t_stack *stack)
{
	t_stack *curr;

	if (!carrier)
	{	
		printf("no carrier");
		return ;
	}
	if (!stack)
	{
		printf("no stack");
		return ;
	}
	curr = stack;
	printf(">>> stack <<<  \n");
	while (curr)
	{
		printf("%d\n", curr->data);
		curr = curr->next;
	}
	printf(">>>>>> <<<<<<\n");
	return ;
}

void	debug(t_carrier *carrier, t_stack **a, t_stack **b)
{
	printf("carreir->ac_cnt : %d\n", carrier->ac_cnt);
	printf("carreir->min : %d\n", carrier->min);
	printf("carreir->max : %d\n", carrier->max);
	// printf("carreir->pivot : %d\n", carrier->pivot);
	printf("carreir->a_cnt : %d\n", carrier->a_cnt);
	printf("carreir->b_cnt : %d\n", carrier->b_cnt);
	printf("carreir->error : %d\n", carrier->error);
	printf("carreir->arem_cnt : %d\n", carrier->arem_cnt);
	printf("carreir->brem_cnt : %d\n", carrier->brem_cnt);
	printf("carreir->pa_num : %d\n", carrier->pa_num);	
	printf("carreir->pb_num : %d\n", carrier->pb_num); 
	printf("carreir->rra_num : %d\n", carrier->rra_num); 
	printf("carreir->rrb_num : %d\n", carrier->rrb_num);
	
	if (carrier->a_remnant)
		printf("carreir->a_remnant->data : %d\n", carrier->a_remnant->data);
	if (carrier->b_remnant)
		printf("carrier->b_remnant->data : %d\n", carrier->b_remnant->data);
}