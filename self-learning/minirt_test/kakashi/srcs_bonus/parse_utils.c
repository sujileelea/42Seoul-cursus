/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 12:56:42 by sujilee           #+#    #+#             */
/*   Updated: 2021/05/14 16:18:36 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/minirt_bonus.h"

//공백을 스킵하는 함수. 이중포인터 사용
void	skip_space(char **str)
{
	while (**str == 32 || (**str > 7 && **str < 13))
		(*str)++;
}

//atoi와 비슷하지만 이중포인터를 받아 공백까지 스킵해줌
int		rt_atoi(char **str)
{
	int	minus;
	int	result;

	minus = 1;
	result = 0;
	skip_space(str);
	if (**str == '-' && *(*str)++)  //값 참조가 아니라 인덱스 증가시켜주는 의도
		minus *= -1;
	while (**str >= '0' && **str <= '9')
	{
		result = result * 10 + (**str - '0');
		(*str)++; 
	}
	return (result * minus);
}

//atoF와 비슷하지만 이중포인터를 받아 공백까지 스킵해줌
double	rt_atof(char **str)
{
	int		minus;
	int		digit;
	double	result;

	d = 0;
	minus = 1;
	skip_space(str);
	if (**str == '-' && *((*str)++))
		minus *= -1;
	while (ft_isdigit(**str))
		digit = digit * 10 + (*((*str)++) - '0');
	while (result >= 1)
		result /= 10;
	result += digit;
	return (result * minus);
}