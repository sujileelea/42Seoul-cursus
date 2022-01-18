/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 15:07:11 by sujilee           #+#    #+#             */
/*   Updated: 2022/01/17 16:28:09 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_sorted(t_stack *a)
{   
	if (!a)
		exit(1);
	while (a->next)
    {
        if (a->data > a->next->data)
            return (0);
        a = a->next;
    }
    return (1);
}

void	sort_three(t_carrier *carrier, t_stack **a)
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

void    sort_descending(t_carrier *carrier, t_stack **a, t_stack **b)
{
    int i;
    
    if (!carrier || !a)
        return ;
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
}
// 스택 a에서 5개 숫자 오름차순 정렬
void	sort_five(t_carrier *carrier, t_stack **a, t_stack **b)
{
    int max;
    int min;
    int i;
    
    max = carrier->max;
    min = carrier->min;
    i = 0;
    printf("max: %d, min: %d", max, min);
    while(i++ < 5)
    {
        printf("data: %d\n", ((*a))->data);
        if ((*a)->data == min || (*a)->data == max)
            pb(carrier, a, b);    
        else
            ra(a);
    }
    sort_three(carrier, a);

    if ((*b)->data == min)
        sb(b);
    pa(carrier, a, b);
    ra(a);
    pa(carrier, a, b);

    return ;
}

void    sort_many(t_carrier *carrier, t_stack **a, t_stack **b)
{
    if (!carrier || !a)
        return ;
    if (is_sorted(*a))
        return ;
    if (is_descending(carrier, *a))
        sort_descending(carrier, a, b);
    
    //a 스택에 미정렬된 뭉텅이가 있을 경우 a_to_b
    while (carrier->arem_cnt != 0)
    {
        if (carrier->pa_num == 0)
            break ;
        a_to_b(carrier, a, b);
    }
    //b 스택에 미정렬된 뭉텅이가 있을 경우 b_to_a
    while (carrier->b_cnt != 0)
    {
        if (carrier->pb_num == 0)
            break ;
        b_to_a(carrier, a, b);
    }
}