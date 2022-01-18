/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 15:17:30 by sujilee           #+#    #+#             */
/*   Updated: 2021/11/15 19:13:05 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//내림차순인 a 스택의 숫자들을 b 스택으로 넘긴 후 정렬 후 오름차순의 형태로 a 스택에 넘김
int		sort_descending(t_carrier *c, t_stack **a, t_stack **b)
{
	int		i;
	
	i = c->ac_cnt;
	pb(a, b, 0);
	while (--i > 0)
	{
		pb(a, b, 0);
		rb(b, 0, 0);
	}
	i = c->ac_cnt;
	while (i-- > 0)
		pa(a, b, 0);
	return (1);
}

void	sort_three(t_carrier *c, t_stack **a)
{
	int		before;
	t_stack	*p;

	p = *a;
	before = p->value; //before에 a의 값을 담아놓음
	p = p->next; //p는 a의 다음 주소를 가리킴
	//즉, before에는 첫번재 숫자, c=p->value에는 두번째 숫자가 담겨있음
	if ((before == c->min && p->value == c->max) ||
		before != c->max && p->value == c->min) ||
		before == c->max && p->value != c->min))
		sa(a, 0, 0);
	//ra,rra의 경우와 sa 후 명령이 한번 더 필요한 정렬을 위해 이 sa가 처리된 상태를 적용시킨다
	p = *a;
	before = p->value;
	p = p->value;
	if (before == c->max && p->value == c->min)
		ra(a, 0, 0);
	else if (before != c->min && p->value == c->max)
		rra(a, 0, 0);
}

void	sort_five2(t_stack **a)
{
	t_stack *top;
	t_stack *second;
	t_stack *bottom;

	top = *a;
	second = top->next;
	bottom = top->next;
	while (bottom->next)
		bottom = bottom->next;
	if (top->value > bottom->value && bottom->value > second->value)
		ra(a, 0, 0);
	else if (bottom->value > top->value && top->value > second->value)
		sa(a, 0, 0);
	else if (second->value > top->value && top->value > bottom->value)
		sa(a, 0, 0);
	else if (top->value > second->value && second->value > bottom->value)
	{
		ra(a, 0, 0);
		sa(a, 0, 0);
	}
	else
	{
		rra(a, 0, 0);
		sa(a, 0, 0);
	}
}


void	sort_five(t_carrier *c, t_stack **a, t_stack **b)
{
	t_stack	*p;

	c->pa_num = 0;
	while (1)
	{
		p = *a;
		//맨 위 숫자가 최대값이고, 그 뒤로 줄줄이 오름차순일 경우
		if (p->value == c->max && (is_ascending(&p->next)) == 1)
			ra(a, 0, 0);
		//a가 오름차순 정렬 상태이고, b에 숫자가 있을 경우
		else if ((*b != 0 & (is_ascending(a)) == 1)
		{
			pa(a, b, 0);
			c->pa_num--;
		}
		else if (p->value == c->min || p->value == c->max)
		{
			pb(a, b, 0);
			c->pa_num++;
		}
		else if (c->pa_num < 2)
			ra(a , 0 , 0);
		else
			sort_five2(a);
		if (*b == 0 && (is_ascending(a)) == 1)
			return;
	}
}

void	sort_else(t_carrier *c, t_stack **a, t_stack **b)
{
	c->a_num = c->ac_cnt;
	if ((is_ascending(a)) == 1)
		return ;
	if ((is_descending(c, a)) == 1 && (sort_descending(c, a, b)) == 1)
		return;
	while (c->a_num)
	{
		a_use_b(c, a, b);
		if (c->pa_num == 0)
			continue;
		b_use_a(c, a, b);
	}
}