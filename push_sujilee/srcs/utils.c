/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 22:02:23 by sujilee           #+#    #+#             */
/*   Updated: 2022/01/24 17:02:51 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void        error(t_carrier *carrier)
// {

// }

long	get_integer(char *argv, t_stack **a, char **s)
{
	int		sign;
	long	num;

	num = 0;
	sign = 1;
	if (*argv == '+' || *argv == '-')
		sign = *argv++ == '+' ? 1 : -1;
	//if (*argv < '0' || *argv > '9')
		//print_error(a, 0, s);
	while (*argv >= '0' && *argv <= '9')
	{
		num = num * 10 + (*argv++ - '0');
		// if (num < 0 || num > 2147483648)
		//	print_error(a, 0, s);
	}
	if (*argv != 0 || (sign == 1 && num > 2147483647))
	//	print_error(a, 0, s);
		return (num * sign);
	return (0);
}

// void        is_overlapped(t_carrier *carrier, t_stack **a)
// {
//     t_stack *temp;
//     t_stack *comp;

//     temp = *a;
//     while (temp != 0)
//     {
//         comp = temp->next;
//         while (comp != 0)
//         {
//             if (temp->data == comp->data)
//             {
//                 error(carrier);
//                 printf("is overlapped!\n");
//                 return ;
//             }
//             comp = comp->next;
//         }
//         temp = temp->next;
//     }
// }

int		is_overlap(t_stack **a, t_stack *p, int num)
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

int			find_max(char old, char new)
{
	int	max;

	max = old;
	if (old < new)
		max = new;
	return (max);
}

int    		find_min(char old, char new)
{
	int min;

	min = old;
	if (old > new)
		min = new;
	return (min);
}