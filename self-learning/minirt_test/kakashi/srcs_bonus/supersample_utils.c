/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supersample_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 12:14:26 by sujilee           #+#    #+#             */
/*   Updated: 2021/05/13 13:29:13 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/minirt_bonus.h"

int	average(int color1, int color2)
{
	int	average[3];
	int	mask;
	int	color[2];
	int	i;

	mask = 255;
	ft_memset(average, 0, 3 * sizeof(int));
	color[0] = color1;
	color[1] = color2;
	i = 0;
	while (i < 2)
	{
		average[0] += (color[i] & (mask << 16)) >> 16;
		average[1] += (color[i] & (mask << 8)) >> 8;
		average[2] += color[i] & mask;
		i++;
	}
	average[0] = average[0] / 2;
	average[1] = average[1] / 2;
	average[2] = average[2] / 2;
	return ((average[0] << 16) | (average[1] << 8) | average[2]);
}

//calc_pixel_color에서 구해온 color값을 비교 -> 1000이상 차이나면 재계산
//그게 아닐 경우 픽셀의 4개의 array를 더한 후 나눠서 평균을 구해줌
int		average_supersampled_color(int *color)
{
	int	ss_color[3];
	int	mask;
	int	n;

	ft_memset(ss_color, 0, sizeof(int) * 3);
	mask = 255;
	n = 0;
	//array는 4개 있으므로 4번 돌린 후
	while (n < 4)
	{
		ss_color[0] += (color[n] & (mask << 16)) >> 16;
		ss_color[1] += (color[n] & (mask << 8)) >> 8;
		ss_color[2] += color[n] & mask;
		n++;
	}
	//4로 나눠서 평균 값을 잡아줌
	ss_color[0] = ss_color[0] / 4;
	ss_color[1] = ss_color[1] / 4;
	ss_color[2] = ss_color[2] / 4;
	free(color);
	return ((ss_color[0] << 16) | (ss_color[1] << 8) | ss_color[2]);
}
//픽셀끼리 색 차이가 많이 날 경우 supersample, 즉 antialiasing을 해줌