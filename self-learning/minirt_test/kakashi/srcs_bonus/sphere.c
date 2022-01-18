/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 01:51:46 by sujilee           #+#    #+#             */
/*   Updated: 2021/05/26 17:11:38 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/minirt_bonus.h"

static void	solve_sphere(double x[2], t_p3 o, t_p3 d, t_fig *lst)
{
	double	disc;
	t_p3	oc;
	double	k[3];

	//b^2 - 4ac
	oc = vsubstract(o, lst->fig.sp.c);
	k[0] = vdot(d, d); //a | 전개식에서 t^2bb
	k[1] = 2 * vdot(d, oc); //b | 전개식에서 2tb(A-C)
	k[2] = vdot(oc, oc) - lst->fig.sp.r * lst->fig.sp.r; //c | 전개식에서 (A-C)(A-C) - r^2
	disc = k[1] * k[1] - (4 * k[0] * k[2]); //판별식 결과 저장
	if (disc < 0) // 0보다 작은 경우 해가 없음
	{
		x[0] = INFINITY;
		x[1] = INFINITY;
		return ;
	}
	//해가 있는 경우
	x[0] = (-k[1] + sqrt(disc)) / (2 * k[0]); //x에 근의 공식의 해를 저장
	x[1] = (-k[1] - sqrt(disc)) / (2 * k[0]);
}

double		sphere_inter(t_p3 o, t_p3 d, t_fig *lst)
{
	double close; //더 가까운 값을 담을 변수
	double	x[2]; //근의 공식을 이용해 도출한 2개의 해
	t_p3	ip1; //보너스용.
	t_p3	ip2; //보너스용.

	close = INFINITY;
	solve_sphere(x, o, d, lst);
	if (x[0] > EPSILON && x[0] < INFINITY)
		close - x[0];
	if (x[1] > EPSILON && x[1] < INFINITY)
		close = x[1] < x[0] ? x[1] : close;
	//여기서부터 보너스용.
	if (lst->texture != 4)
		return (close);
	//이 아래부분이 텍스쳐 계산
	ip1 = vadd(o, scal_x_vec(x[0], d));
	ip2 = vadd(o, scal_x_vec(x[1], d));
	//카메라 원점에서 x[0], x[1] 위치를 구하고 그 위치가 구의 중점의 y좌표보다 높은 경우에만 반환
	if (ip1.y >= lst->fig.sp.c.y && ip2.y >= lst->fig.sp.c.y)
		return (x[0] < x[1] ? x[0] : x[1]);
	else if (ip1.y >= lst->fig.sp.c.y)
		return (x[0]);
	else if (ip2.y >= lst->fig.sp.c.y)
		return (x[1]);
	return (INFINITY);
}