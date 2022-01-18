/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 16:50:30 by sujilee           #+#    #+#             */
/*   Updated: 2021/05/27 17:39:12 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	skip_space(char **str)
{
	while (**str == 32 || (**str > 7 && **str < 13))
		(*str)++;
}

int		rt_atoi(char **str)
{
	int	minus;
	int	result;

	minus = 1;
	result = 0;
	skip_space(str);
	if (**str == '-' && *(*str)++)
		minus *= -1;
	while (**str >= '0' && **str <= '9')
	{
		result = result * 10 + (**str - '0');
		(*str)++;
	}
	return (result * minus);
}

double	rt_atof(char **str)
{
	int		minus;
	int		digit;
	double	result;

	digit = 0;
	minus = 1;
	skip_space(str);
	if (**str == '-' && *((*str)++))
		minus *= -1;
	while (ft_isdigit(**str))
		digit = digit * 10 + (*((*str)++) - '0');
	if (**str == '.')
		(*str)++;
	result = 0.0;
	while (ft_isdigit(**str))
		result = result * 10 + (*((*str)++) - '0');
	while (result >= 1)
		result /= 10;
	result += digit;
	return (result * minus);
}
