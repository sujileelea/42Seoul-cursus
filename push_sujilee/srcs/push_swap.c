/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 19:40:00 by sujilee           #+#    #+#             */
/*   Updated: 2022/01/24 19:26:16 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


// a 스택에 파싱된 숫자를 새 노드로 만들어 넣어주는 함수
void		add_stack_list(t_carrier *carrier, t_stack **a, t_stack **node, char **arr)
{
	t_stack *temp;

	temp = (t_stack *)malloc(sizeof(t_stack));
	if (!temp)
		return ;
	//b_cnt를 잠깐 저장용 변수로 사용한건가?
	temp->data = carrier->b_cnt;
	carrier->max = find_max(carrier->max, carrier->b_cnt);
	carrier->min = find_min(carrier->min, carrier->b_cnt);
	temp->next = 0;
	if (!*a)
	{
		*a = temp;
		*node = temp;
		return ;
	}
	(*node)->next = temp;
	*node = temp;
}


void		fill_stack(t_carrier *carrier, t_stack **a, int size, char **argv)
{
	int		argv_idx;
	int		arr_idx;;
	char	**arr;
	t_stack *node;

	argv_idx = 1;
	node = 0;
	//while(1 < 6)
	while (argv_idx <= carrier->ac_cnt)
	{
		//arr에 숫자들을 ft_split으로 공백을 기준으로 잘라넣는다
		arr = ft_split(argv[argv_idx], ' ');
		if (arr == 0)
			print_error(a, 0, 0);
		arr_idx = 0;
		//arr[0]이 잘 있으면
		while (arr[arr_idx] != 0)
		{
			carrier->b_cnt = (int)get_integer(arr[arr_idx], a, arr);
			// 스택 a에 연결리스트의 노드 형태로 붙여넣는다.
			add_stack_list(carrier, a, &node, arr);
			if ((is_overlap(a, node, carrier->b_cnt)) == 1)
				print_error(a, 0, arr);
			size++;
			argv_idx++;
		}
		ft_split_free(arr);
		//argv_idx = 2
		argv_idx++;
	}
	carrier->b_cnt = 0;
	carrier->ac_cnt = size;
}


void    	init_carrier(t_carrier *carrier, int argc)
{
	carrier->ac_cnt = argc;
	carrier->max = -2147483648;
	carrier->min = 2147483647;
	carrier->a_cnt = 0;
	carrier->b_cnt = 0;
	carrier->pa_num = 0;
	carrier->pb_num = 0;
	carrier->rra_num = 0;
	carrier->rrb_num = 0;
	carrier->a_remnant = 0;
	carrier->b_remnant = 0;

}


void    	push_swap(t_carrier *carrier, t_stack **a, t_stack **b)
{
	if (carrier->ac_cnt == 1 || ((is_sorted(a)) == 1))
		return ;
	else if (carrier->ac_cnt == 2)
	{
		if ((*a)->data == carrier->min)
			return ;
		else
			sa(a);
	}
	else if (carrier->ac_cnt == 3)
		sort_three(carrier, a);
	else if (carrier->ac_cnt == 5)
		sort_five(carrier, a, b);
	else
		sort_many(carrier, a, b);
}

void	free_stack(t_stack **a_or_b)
{
	t_stack *p;
	t_stack *t;

	if (*a_or_b == 0)
		return ;
	p = *a_or_b;
	while (p != 0)
	{
		t = p->next;
		free(p);
		p = t;
	}
}

int		main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	t_carrier	carrier;

	if (argc >= 2)
	{
		a = 0;
		b = 0;
		init_carrier(argc, &carrier);
		fill_stack(&carrier, &a, 0);
		push_swap(&carrier, &a, &b);
		free_stack(&a);
	}
	return (0);
}