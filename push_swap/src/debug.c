/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 20:09:27 by sujilee           #+#    #+#             */
/*   Updated: 2022/01/25 04:33:34 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	print_stack(t_carrier *carrier, t_stack *stack)
{
	t_stack	*curr;

	if (!carrier)
	{	
		write(1, "no carrier\n", 11);
		return ;
	}
	if (!stack)
	{
		write(1, "no stack\n", 9);
		return ;
	}
	curr = stack;
	write(1, ">>> stack <<<  \n", 16);
	while (curr)
	{
		printf("%d\n", curr->data);
		curr = curr->next;
	}
	write(1, ">>>>>> <<<<<<\n", 14);
	return ;
}
