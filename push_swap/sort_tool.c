/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tool.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 19:14:10 by sujilee           #+#    #+#             */
/*   Updated: 2021/11/17 21:58:11 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int		get_pivot(t_stack **p, int num)
{
	int		min;
	int		max;
	t_stack	*temp;

	temp = *p;
	min = temp->value;
	max = temp->value;
	while (num-- > 0)
	{
		if (max < temp->value)
			max = temp->value;
		else if (min > temp->value)
			min = temp->value;
		temp = temp->next;
	}
	return ((min + max) / 2);
}

void    sort_a(t_carrier *c, t_stack **a)
{
	t_stack	*p;

	p = c->b_rest;
	if (p)
	{
		c->b_num = c->b_rest->value;
		c->b_rest = c->b_rest->next;
	}
	free (p);
	if (c->a_num == 1)
	{
		ra(a, 0, 0);
		c->a_num = 0;
		return ;
	}
	p = *a;
	if (p->value > (p->next)->value)
		sa(a, 0, 0);
	ra(a, 0, 0);
	ra(a, 0, 0);
	c->a_rest = 0;
}

void	sort_b(t_carrier *c, t_stack **a, t_stack **b)
{
	t_stack **p;

	c->pa_num -= c->b_num;
	c->a_num = c->a_rest->value;
	p = c->a_rest;
	c->a_rest = c->a_rest->nextl
	free(p);
	if (c->b_num == 1)
	{
		pa(a, b, 0);
		ra(a, 0, 0);
		c->b_num = 0;
		return ;
	}
	p = *b;
	if (p->value > (p->next)->value)
		sb(b, 0, 0);
	pa(a, b, 0);
	ra(a, 0, 0);
	pa(a, b, 0);
	ra(a, 0, 0);
	c->b_num = 0;
}


void	a_use_b(t_carrier *c, t_stack **a, t_stack **b)
{
	t_stack	*p;
	int		pivot;

	if (c->a_num < 3)
	{
		sort_a(c, a);
		return ;
	}
	//프롬프트에 들어온 숫자 개수 == a 스택에서 정렬해야할 숫자 개수일때
	if (c->a_num == c->ac_cnt)
		pivot = (c->min + c->max) / 2;
	else
		pivot = get_pivot(a, c->a_num);
	iterate_a(c, a, b, pivot);
	add_front_stack(c, a, b, 'a'); //? 이게 뭐지
	p = *a;
	while (c->rra_num > 0 && (c->a_rest->next !=0 ||
		p->value == c->min))
	{
		rra(a, 0, 0);
		c->rra_num--;
	}
	c->rra_num = 0;
}

void	b_use_a(t_carrier *c, t_stack **a, t_stack **b)
{
	int		pivot;

	//스택 a로 넘기기 전에 정렬해야할 숫자의 개수가 3개 미만일 경우
	if (c->b_num < 3)
	{
		sort_b(c, a, b);
		return ;
	}
	pivot = get_pivot(b, c->b_num);
	iterate_b(c, a, b, pivot);
	add_front_stack(c, a, b, 'b');
	while (c->b_rest->next && c->rrb_num > 0)
	{
		rrb(b, 0, 0);
		c->rra_num--;
	}
	c->rrb_num = 0;
}