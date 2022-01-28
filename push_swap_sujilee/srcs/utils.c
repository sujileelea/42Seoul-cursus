/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 19:37:19 by sujilee           #+#    #+#             */
/*   Updated: 2022/01/28 11:33:50 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	get_integer(char *argv, t_stack **a, char **s)
{
	int		sign;
	long	num;

	num = 0;
	sign = 1;
	if (*argv == '+' || *argv == '-')
	{
		if (*argv++ == '+')
			sign = 1;
		else
			sign = -1;
	}
	if (*argv < '0' || *argv > '9')
		print_error(a, 0, s);
	while (*argv >= '0' && *argv <= '9')
	{
		num = num * 10 + (*argv++ - '0');
		if (num < 0 || num > 2147483648)
			print_error(a, 0, s);
	}
	if (*argv != 0 || (sign == 1 && num > 2147483647))
		print_error(a, 0, s);
	return (sign * num);
}

int	is_overlapped(t_stack **a, t_stack *new_node, int num)
{
	t_stack	*comp;

	comp = *a;
	while (comp != new_node)
	{
		if (comp->data == num)
			return (1);
		comp = comp->next;
	}
	return (0);
}

void	link_stack(t_carrier *carrier, t_stack **a, t_stack **new_node, char **arr)
{
	t_stack	*temp;

	temp = (t_stack *)malloc(sizeof(t_stack) * 1);
	if (temp == 0)
		print_error(a, 0, arr);
	temp->data = carrier->b_cnt;
	if (carrier->min > carrier->b_cnt)
		carrier->min = carrier->b_cnt;
	if (carrier->max < carrier->b_cnt)
		carrier->max = carrier->b_cnt;
	temp->next = 0;
	if (*a == 0)
	{
		*a = temp;
		*new_node = temp;
		return ;
	}
	(*new_node)->next = temp;
	*new_node = temp;
}

void	fill_stack(t_carrier *carrier, char **argv, t_stack **a, int num)
{
	int		av_idx;
	int		arr_idx;
	char	**arr;
	t_stack	*new_node;

	av_idx = 0;
	new_node = 0;
	while (++av_idx < carrier->argc)
	{
		arr = ft_split(argv[av_idx], ' ');
		if (arr == 0)
			print_error(a, 0, 0);
		arr_idx = -1;
		while (arr[++arr_idx] != 0)
		{
			carrier->b_cnt = (int)get_integer(arr[arr_idx], a, arr);
			link_stack(carrier, a, &new_node, arr);
			if ((is_overlapped(a, new_node, carrier->b_cnt)) == 1)
				print_error(a, 0, arr);
			num++;
		}
		ft_split_free(arr);
	}
	carrier->b_cnt = 0;
	carrier->argc = num;
}

void	check_ab(t_carrier *carrier, t_stack *t, char c)
{
	if (c == 'a')
		t->data = carrier->rra_cnt;
	else
		t->data = carrier->rrb_cnt;
	if (c == 'a')
		t->next = carrier->a_remnant;
	else
		t->next = carrier->b_remnant;
	if (c == 'a')
		carrier->a_remnant = t;
	else
		carrier->b_remnant = t;
}
