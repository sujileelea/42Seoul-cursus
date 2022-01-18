/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 18:01:29 by sujilee           #+#    #+#             */
/*   Updated: 2021/10/03 18:25:02 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

//첫 스택에 3개의 숫자만 들어왔을 경우
void	arrange_three_digits(t_record *r, t_stack **a)
{
	int		before;	//앞 노드의 값
	t_stack	*p;		//노드의 주소값을 가질 포인터

	p = *a;				//앞 노드의 주소값을 p에 넣어놓음
	before = p->value;	//상대적으로 앞 노드의 값
	p = p->next; 		//이제 비교를 위해 p에 뒷 노드의 주소를 가지게 함
	
	//before : 앞 노드의 데이터 p->value : 뒷 노드의 데이터
	if ((before == r->min && p->value == r->max) ||
		(before == r->max && p->value != r->min) ||
		(before != r->max && p->value == r->min))
			sa(a, 0, 0);
	p = *a;
	before = p->value;
	p = p->next;
	if (before == r->max && p->value == r->min)
		ra(a, 0, 0);
	else if (before != r->min && p->value == r->max)
		rra(a, 0, 0);
}

int		is_arranged(t_stack **a)
{
	int		before;
	t_stack	*p;

	p = *a;	//p는 a의 포인터(a의 주소값을 담고 있음)
	before = p->value;
	p = p->next;
	while (p != 0)
	{
		if (before > p->value)
			reutrn (0);
		before = p->value;
		p = p->next;
	}
}

void	arrange_and_print(t_record *record, t_stack **a, t_stack **b)
{
	if (record->argc == 1 || ((is_arranged(a)) == 1))
			return ;
	else if (record->argc == 2)
	{
		if ((*a)->value == record -> min)
			return ;
		else
			sa(a, 0, 0);
	}
	else if (record->argc == 3)
		arrange_three_digits(record, a);
	else if (record->argc == 5)
		arrange_five_digits(record, a, b);
	else
		arrange_many_digits(record, a, b);
}

void	set_record(int argc, t_record *r)
{
	r->argc = argc;
	r->max = -2147483648;
	r->min = 2147483647;
	r->pa_num = 0;
	r->rra_num = 0;
	r->rrb_num = 0;
 	r->b_num = 0;
	r->a_rest = 0;
	r->b_rest = 0;
}

int		main(int argc, char **argv)
{
	t_stack		*a;			//a 스택
	t_stack		*b;			//b 스택
	t_stack		record;

	if (argc >= 2)
	{
		a = 0;
		b = 0;
		set_record(argc, &record);
		fill_stack(&record, argv, &a, 0);
		arrange_n_print(&record, &a, &b);
		free_stack(&a);
	}

	return (0);
}
