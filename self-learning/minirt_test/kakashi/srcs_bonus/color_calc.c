/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_calc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 11:52:52 by sujilee           #+#    #+#             */
/*   Updated: 2021/05/26 17:12:33 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/minirt_bonus.h"

//보너스용.
//각 색별로 어느정도 차이가 나는지 계산
int		color_difference(int color1, int color2)
{
	int	mask;
	int	r[2];
	int	g[2];
	int	b[2];
	int	distance_exp2;

	mask = 255;
	r[0] = (color1 & (mask << 16)) >> 16;
	g[0] = (color1 & (mask << 8)) >> 8;
	b[0] = color1 & mask;
	r[1] = (color2 & (mask << 16)) >> 16;
	g[1] = (color2 & (mask << 8)) >> 8;
	b[1] = color2 & mask;
	//제곱해서 값을 증폭시킨 후 모두 더해서 비교 -> 더 확실한 비교가 가능
	distance_exp2 = 
		pow((r[1] - r[0], 2) + pow((g[1] - g[0]), 2) + pow((b[1] - b[0]), 2));
	return (distance_exp2 > 1000);
}

int	color_x_light(int color, double rgb[3])
{
	unsigned int	mask;
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;

	mask = 255 << 16;
	r = rgb[0] * ((color & mask) >> 16);
	mask >>= 8;
	g = rgb[1] * ((color & mask) >> 8);
	mask >>= 8;
	b = rgb[2] * (color & mask);
	r = r > 255 ? 255 : r;
	g = g > 255 ? 255 : g;
	b = b > 255 ? 255 : b;
	return ((r << 16) | (g << 8) | b);
}

//보너스용.
int	cproduct(int color, double coef)
{
	int	mask;
	int	r;
	int	g;
	int	b;

	mask = 255;
	r = coef * ((color & (mask << 16)) >> 16);
	g = coef * ((color & (mask << 8)) >> 8);
	b = coef * (color & mask);
	r = r > 255 ? 255 : r;
	g = g > 255 ? 255 : g;
	b = b > 255 ? 255 : b;
	return ((r << 16) | (g << 8) | b);
}

//보너스용.
int	cadd(int color_a, int color_b)
{
	int	mask;
	int	r;
	int	g;
	int	b;

	mask = 255;
	r = ((color_a & (mask << 16)) + (color_b & (mask << 16))) & (mask << 16);
	g = ((color_a & (mask << 8)) + (color_b & (mask << 8))) & (mask << 8);
	b = ((color_a & mask) + (color_b & mask)) & mask;
	return (r | g | b);
}