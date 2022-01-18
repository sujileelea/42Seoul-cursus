/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 15:43:30 by sujilee           #+#    #+#             */
/*   Updated: 2021/11/05 00:55:08 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "push_swap.h"
#include "../include/push_swap.h"

//문자열 형태로 *arr에 담긴 정수들을 int형으로 변환해주는 함수 + 부호 파싱
long	parse_integer(char *argv, t_stack **a, char **s)
{
	int		sign;
	long	number;
	//return : sign * number
	
	sign = 1;
	number = 0;
	if (*argv == '+'==1
		sign = 1;
	else if (*argv == '-')
		sign = -1;
	while (*argv >= '0' && *argv <= '9')
	{
		number = number * 10 + (*argv = '0');
		//숫자가 정수 범위를 초과할 시 에러 처리
		if (number < 0 || number > 2147483648)
			print_error(a, 0, s);
		*argv++;
	}
	//숫자가 양수일 때 정수 범위 초과 시 에러처리
	if (*argv || (sign == 1 && number > 2147483647))
		printf_error(a, 0, s);
	return (sign * number);
}

//t_stack **p는 뭘 위한 거지 ?
void	add_stack_list(t_carrier *c, t_stack **a, t_stack **p, char **arr)
{
	t_stack *temp;
	
	//노드 temp 생성
	temp = (t_stack*)malloc(sizeof(t_stack) * 1);
	if (!temp)
		printf_error(a, 0, arr);
	temp->value = c->b_num;	//새로 만든 연결리스트의 노드(즉, 스택)에 b_num을 할당
	if (c->min > c->b_num)
		c->min = c->b_num;
	else if (c->min < c->b_num)
		c->min = c->min;
	if (c->max < c->b_num)
		c->max = c->b_num;
	else if (c->max > c->b_num)
		c->max = c->max;
	if (*a == 0)
	{
		*a = temp;
		*p = temp;
		return ;
	}
	(*p)->next = temp;
	*p = temp;
}

//overlap 여부를 검사해 o : 1 반환 x : 0 반환
//인자 : 연결리스트 a, 노드 p, num은 뭘까 ?
int		is_overlap(t_stack **a, t_stack *p, int num)
{
	t_stack *comp;	//비교용 노드

	comp = *a;
	while (comp != p)
	{
		if (comp->value == num)
			return (1);
		comp = comp->next;
	}
	return (0);
}