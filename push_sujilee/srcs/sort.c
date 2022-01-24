/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 19:45:08 by sujilee           #+#    #+#             */
/*   Updated: 2022/01/24 16:59:29 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			is_sorted(t_stack **a)
{
	t_stack *head;

	head = *a;
	while (head->next)
	{
		if (head->data > head->next->data)
			return (0);
		head = head->next;
	}
	return (1);

}

int    is_descending(t_carrier *carrier, t_stack *a)
{
	t_stack *curr;

    if (!carrier || !a)
        return (0);
    curr = a;
    while (curr->next)
    {
        if (curr->data < curr->next->data)
            return (0);
         curr = curr->next;
    }
    return (1);
}

int    sort_descending(t_carrier *carrier, t_stack **a, t_stack **b)
{
	int i;
    
    if (!carrier || !a)
        return (0);
        //첫 pb
    pb(carrier, a, b);
        //a스택이 비워질때까지 pb rb
    i = carrier->ac_cnt;
    while (--i)
    {
        pb(carrier, a, b);
        rb(b);
    }
    while (i++ < carrier->ac_cnt)
        pa(carrier, a, b);
        //b스택이 비워질때까지 pa
    return (1);
}
void		sort_three(t_carrier *carrier, t_stack **a)
{
    if (!carrier || !a)
		exit(1);
    //1 2 3 
	if ((*a)->data < (*a)->next->data && (*a)->next->data < (*a)->next->next->data)
        return ;
    //1 3 2 
    else if ((*a)->next->next->data > (*a)->data && (*a)->next->data > (*a)->next->next->data)
    {
        sa(a);
        ra(a);
    }
    //2 1 3 
    else if ((*a)->data > (*a)->next->data && (*a)->next->next->data > (*a)->data)
        sa(a);
    //2 3 1
	else if ((*a)->next->data > (*a)->data && (*a)->data > (*a)->next->next->data)
        rra(a);
    //3 1 2
	else if ((*a)->data > (*a)->next->next->data && (*a)->next->next->data > (*a)->next->data)
        ra(a);
    //3 2 1
    else if ((*a)->data > (*a)->next->data && (*a)->next->data > (*a)->next->next->data)
    {
        ra(a);
        sa(a);
    }
    return ; 
}

void		sort_five(t_carrier *carrier, t_stack **a, t_stack **b)
{

}

void    sort_many(t_carrier *carrier, t_stack **a, t_stack **b)
{
	carrier->arem_cnt = carrier->ac_cnt;
	if ((is_sorted(a)) == 1)
		return ;
	if ((is_descending(carrier, *a)) == 1 && (sort_descending(carrier, a, b)) == 1)
		return ;
	while (carrier->arem_cnt != 0)
	{
		a_to_b(carrier, a, b);
		if (carrier->pa_num == 0)
			continue ;
		b_to_a(carrier, a, b);
	}
}
