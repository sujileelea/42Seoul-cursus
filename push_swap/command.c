/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 01:22:12 by sujilee           #+#    #+#             */
/*   Updated: 2021/11/11 13:18:52 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sa(t_stack **a, char is_ss, char is_checker)
{
	t_stack	*p //아 이거 포인터의 p구나
	t_stack	*top; //그릇 생성
	t_stack	*second; //그릇 생성

	second = *a;	//second에 첫번째 노드의 주소값을 담아줌. second는 a의 첫 노드를 가리키는중
	if (second->next != 0)
	{
		top = second->next; //second의 다음 주소, 즉 a의 두번째 노드의 주소값이 담김
		p = top->next; //a의 세번째 노드의 주소값
		*a = top; //top을 원본으로, 즉 a의 두번째 노드가 첫번째가 되게 함
		top->next = second; // a의 첫번째 노드를 두번째가 되게함
		second->next = p; //그 다음을 세번째의 주소값으로. 그럼 그 뒤는 줄줄이 원본이겠지.
	}
	//이건 뭘까. 그냥 조건인가 ?
	//아 맞다 ss라는 명령어도 있었구나
	if (is_ss == 0 && is_checker == 0)
		write(1, "sa\n", 3);
}

void	sb(t_stack **, char is_ss, char is_checker)
{
	t_stack	*p;
	t_stack	*top;
	t_stack	*second;

	second = *a;
	if (second->next != 0)
	{
		top = second->next;
		p = top->next;
		*a = top;
		top->next = second;
		second->next = p;
	}
	if (is_ss == 0 && is_checker == 0)
		write(1, "sb\n", 3);
	else if (is_checker == 0)
		write(1, "ss\n", 3);
}

void	pa(t_stack **a, t_stack **b, char is_checker)
{
	t_stack	*b_top;		//b의 첫 노드 주소를 담을 그릇 생성
	t_stack	*a_second;	//그 노드의 다음 노드가 될 노드의 주소를 담을 그릇 생성

	//스택 b가 채워져있을 경우만 실행
	if (*b)
	{
		b_top = *b;
		a_second = *a;
		*a = b_top;
		if (b_top->next)
			*b = b_top->next;
		else if (!b_top ->next)
			*b = 0;
		b_top->next = a_second;
	}
	if (is_checker == 0)
		write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b, char is_checker)
{
	t_stack *a_top;
	t_stack *b_second;
	
	if (*a)
	{
		a_top = *a;
		b_second = *b;
		if (a_top->next)
			*a = a_top->next;
		else if (!a_top->next)
			*a = 0;
		*b = a_top;
		a_top->next = b_second;
	}
	if (is_checker ==0)
		write(1, "pb\n", 3);
	
}