/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 19:38:27 by sujilee           #+#    #+#             */
/*   Updated: 2022/01/28 11:46:41 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_split_free(char **s)
{
	int	i;

	i = -1;
	while (s[++i] != 0)
		free(s[i]);
	free(s[i]);
	free(s);
}

void	free_stack(t_stack **stack)
{
	t_stack	*curr;
	t_stack	*temp;

	if (*stack == 0)
		return ;
	curr = *stack;
	while (curr != 0)
	{
		temp = curr->next;
		free(curr);
		curr = temp;
	}
}
