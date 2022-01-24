/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 19:37:19 by sujilee           #+#    #+#             */
/*   Updated: 2022/01/24 19:43:07 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


long	get_integer(char *av, t_stack **a, char **s)
{
	int		minus;
	long	num;

	num = 0;
	minus = 1;
	if (*av == '+' || *av == '-')
		minus = *av++ == '+' ? 1 : -1;
	if (*av < '0' || *av > '9')
		print_error(a, 0, s);
	while (*av >= '0' && *av <= '9')
	{
		num = num * 10 + (*av++ - '0');
		if (num < 0 || num > 2147483648)
			print_error(a, 0, s);
	}
	if (*av != 0 || (minus == 1 && num > 2147483647))
		print_error(a, 0, s);
	return (num * minus);
}

int		is_overlapped(t_stack **a, t_stack *p, int num)
{
	t_stack *comp;

	comp = *a;
	while (comp != p)
	{
		if (comp->data == num)
			return (1);
		comp = comp->next;
	}
	return (0);
}

void	link_stack(t_carrier *carrier, t_stack **a, t_stack **p, char **arr)
{
	t_stack *t;

	t = (t_stack*)malloc(sizeof(t_stack) * 1);
	if (t == 0)
		print_error(a, 0, arr);
	t->data = carrier->b_cnt;
	carrier->min = carrier->min > carrier->b_cnt ? carrier->b_cnt : carrier->min;
	carrier->max = carrier->max < carrier->b_cnt ? carrier->b_cnt : carrier->max;
	t->next = 0;
	if (*a == 0)
	{
		*a = t;
		*p = t;
		return ;
	}
	(*p)->next = t;
	*p = t;
}

void	fill_stack(t_carrier *carrier, char **av, t_stack **a, int num)
{
	int		i; //argv[index]
	int		j;
	char	**arr;
	t_stack *p;

	i = 0;
	p = 0;
	while (++i < carrier->argc)
	{
		arr = ft_split(av[i], ' ');
		if (arr == 0)
			print_error(a, 0, 0);
		j = -1;
		while (arr[++j] != 0)
		{
			carrier->b_cnt = (int)get_integer(arr[j], a, arr);
			link_stack(carrier, a, &p, arr);
			if ((is_overlapped(a, p, carrier->b_cnt)) == 1)
				print_error(a, 0, arr);
			num++;
		}
		ft_split_free(arr);
	}
	carrier->b_cnt = 0;
	carrier->argc = num;
}
