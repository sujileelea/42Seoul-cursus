/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 19:28:17 by sujilee           #+#    #+#             */
/*   Updated: 2022/01/27 17:14:57 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack **a)
{
	int		before;
	t_stack	*p;

	p = *a;
	before = p->data;
	p = p->next;
	while (p != 0)
	{
		if (before > p->data)
			return (0);
		before = p->data;
		p = p->next;
	}
	return (1);
}

void	push_swap(t_carrier *carrier, t_stack **a, t_stack **b)
{
	if (carrier->argc == 1 || ((is_sorted(a)) == 1))
		return ;
	else if (carrier->argc == 2)
	{
		if ((*a)->data == carrier->min)
			return ;
		else
			sa(a, 0);
	}
	else if (carrier->argc == 3)
		sort_three(carrier, a);
	else if (carrier->argc == 5)
		sort_five(carrier, a, b);
	else
		sort_many(carrier, a, b);
}

void	init_carrier(int ac, t_carrier *r)
{
	r->argc = ac;
	r->max = -2147483648;
	r->min = 2147483647;
	r->pb_cnt = 0;
	r->rra_cnt = 0;
	r->rrb_cnt = 0;
	r->b_cnt = 0;
	r->a_remnant = 0;
	r->b_remnant = 0;
}

int	main(int ac, char **av)
{
	t_stack		*a;
	t_stack		*b;
	t_carrier	carrier;

	if (ac >= 2)
	{
		a = 0;
		b = 0;
		init_carrier(ac, &carrier);
		fill_stack(&carrier, av, &a, 0);
		push_swap(&carrier, &a, &b);
		free_stack(&a);
	}
	return (0);
}
