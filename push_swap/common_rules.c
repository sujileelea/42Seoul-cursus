/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_rules.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 13:56:33 by sujilee           #+#    #+#             */
/*   Updated: 2021/11/17 22:28:27 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
//#include "push_swap.h"

void	add_front_stack(t_carrier *c, t_stack **a, t_stack **b, char c)
{
	t_stack *temp;

	//temp 노드 하나 생성해줌
	temp = (t_stack*)malloc(sizeof(t_stack) * 1);
	if (temp == 0)
	{
		//a->rest 노드 전부 다 free 시켜버림
		while (c->a_rest)
		{
			temp = c->a_rest;
			c->a_rest = c->a_rest->next;
			free(temp);
		}
		//b->rest 노드 전부 다 free 시켜버림
		while (c->b_rest)
		{
			temp = c->b_rest;
			c->b_rest = c->b_rest->next;
			free(temp;)
		}
		print_error(a, b, 0);
	}
	if (c == 'a')
		temp->value = c->rra_num;
	else if (c == 'b')
		temp->value = c->rrb_num;
	if (c == 'a')
		temp->next = c->a_rest;
	else if (c == 'b')
		temp->next = c->b_rest;
}

//a 스택을 순환하며 피봇보다 작거나 같으면 pb, 크면 ra 시키는 작업 함수
void    iterate_a(t_carrier *c, t_stack **a, t_stack **b, int pivot)
{
	t_stack	*p;

	while (c->a_num > 0)
	{
		p = *a;
		if (p->value <= pivot)
		{
			pb(a, b, 0);
			c->pa_num++;
			c->b_num++;
		}
		else
		{
			ra(a, 0, 0);
			c->rra_num++;
		}
		c->a_num--;
	}
}

//b스택을 순환하며 피봇보다 작거나 같은 pa, 크면 rb 시키는 작업 함수
void	iterate_b(t_carrier *c, t_stackk **a, t_stack **b, int pivot)
{
	t_stack *p;

	while (c->b_num > 0)
	{
		p = *b;
		if (p->value <= pivot)
		{
			pa(a, b, 0);
			c->pa_num--;
			c->a_num++;
		}
		else
		{
			rrb(b ,0, 0);
			c->rrb_num++;	
		}
		c->b_num--;
	}
}

void	free_stack(t_stack **a_or_b)
{
	t_stack	*copy;
	t_stack *temp;
	
	copy = *a_or_b;
	if (copy == 0)
		return ;
	while (copy)
	{
		temp = copy->next;
		free(copy);
		copy = temp;
	}
}

//세번째 인자 ?
void	print_error(t_stack **a, t_stack **b, char **s)
{
	int	i;

	i = 0;
	if (a)
		free_stack(a);
	if (b)
		free_stack(b);
	if (s)
	{
		while (s[i++])
			free(s[i]);
		free(s[i]);
		free(s);
	}
	write(2, "Error\n", 6);
	exit(0);
}