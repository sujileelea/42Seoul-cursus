/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 19:47:16 by sujilee           #+#    #+#             */
/*   Updated: 2022/01/25 04:53:34 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(t_stack **a, t_stack **b, char **s)
{
	int	i;

	if (a != 0)
		free_stack(a);
	if (b != 0)
		free_stack(b);
	if (s != 0)
	{
		i = -1;
		while (s[++i] != 0)
			free(s[i]);
		free(s[i]);
		free(s);
	}
	write(2, "Error\n", 6);
	exit(0);
}
