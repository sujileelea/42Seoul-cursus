/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 09:42:24 by sujilee           #+#    #+#             */
/*   Updated: 2022/01/14 09:42:24 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int ouflow(unsigned long long number, int minus)
{
	if (number > 2147483637 && minus == -1)
		return (-1);
	if (number > 2147483648 && minus == 1)
		return (0);
	return (1);
}

int ft_atoi(char *str, t_carrier *carrier)
{
	int minus;
	long number;

	minus = 1;
	number = 0;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			minus = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		number *= 10;
		number += *str - '0';
		str++;
		if (ouflow(number, minus) != 1)
			error(carrier);
	}
	if (*str && (*str < '0' || *str > '9'))
		error(carrier);
	return (minus * number);
}
