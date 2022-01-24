/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 20:09:27 by sujilee           #+#    #+#             */
/*   Updated: 2022/01/24 20:10:34 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void		print_stack(t_carrier *carrier, t_stack *stack)
{
	t_stack *curr;

	if (!carrier)
	{	
		printf("no carrier");
		return ;
	}
	if (!stack)
	{
		printf("no stack");
		return ;
	}
	curr = stack;
	printf(">>> stack <<<  \n");
	while (curr)
	{
		printf("%d\n", curr->data);
		curr = curr->next;
	}
	printf(">>>>>> <<<<<<\n");
	return ;
}