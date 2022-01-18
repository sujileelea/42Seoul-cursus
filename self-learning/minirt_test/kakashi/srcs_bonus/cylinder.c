/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 14:34:13 by sujilee           #+#    #+#             */
/*   Updated: 2021/05/26 17:12:33 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/minirt_bonus.h"

//원기둥은 크게 뚜껑과 몸체의 계산으로 나뉨

//x[0], x[1] 은 카메라에서 쏜 ray와 원기둥의 교점 두개
static int		solve_cylinder(double x[2], t_p3 o, t_p3 d, t_fig *lst)
{
	t_p3	v;
	t_p3	u;
	double	a;
	double	b;
	double	c;

	//수형으로 바라보는 벡터 v와 u를 구함
	v = scal_x_vec(vdot(d, lst->fig.cy.nv), lst->fig.cy.nv);
	v = vsubstract(d, v);
	u = scal_x_vec(vdot(vsubstract(o, lst->fig.cy.c), lst->fig.cy.nv),
		lst->fig.cy.nv);
	u = vsubstract(vsubstract(o, lst->fig.cy.c), u);
	//근의 공식을 이용해 해를 구함(해 x[0], x[1]은 카메라에서 쏜 ray에 닿은 실린더의 point)
	a = vdot(v, v);
	b = 2 * vdot(v, u);
	c = vdot(u, u) - pow(lst->fig.cy.r, 2);
	x[0] = (-b + sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);
	x[1] = (-b - sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);
	if (x[0] < EPSILON && x[1] < EPSILON)
	{
		x[0] = INFINITY;
		x[1] = INFINITY;
		return (0);
	}
	return (1);
}

static t_p3		calc_cy_normal(double x[2], t_p3 o, t_p3 d, t_fig *lst)
{
	double	dist; //실린더의 밑면으로부터 x[0], x[1]까지의 거리
	double	res;

	//dist의 유효성 (0보다 크고 높이(h)보다 작아야함)
	if ((lst->fig.cy.dist1 >= 0 && lst->fig.cy.dist1 <= lst->fig.cy.h)
		&& (lst->fig.cy.dist2 >= 0 && lst->fig.cy.dist2 <= lst->fig.cy.h))
	{
		//둘 중 더 큰 값을 결과로 잡아줌
		dist = x[0] < x[1] ? lst->fig.cy.dist1 : lst->fig.cy.dist2;
		res = x[0] < x[1] ? x[0] : x[1];
	}
	//아래는 둘 중 하나의 값만 닿은 경우 ?
	else if (lst->fig.cy.dist1 >= 0 && lst->fig.cy.dist1 <= lst->fig.cy.h
				&& x[0] > EPSILON)
	{
		dist = lst->fig.cy.dist1;
		res = x[0];
	}
	else
	{
		dist = lst->fig.cy.dist2;
		res = x[1];
	}
	x[0] = res;
	//normalize 해주며 방향벡터를 계산해줌
	return (normalize(vsubstract(vsubstract(scal_x_vec(res, d),
			scal_x_vec(dist, lst->fig.cy.nv)), vsubstract(lst->fig.cy.c, 0))));
}

static double	cy_intersection(t_p3 o, t_p3 d, t_p3 *normal, t_fig *lst)
{
	double	x[2]; //카메라에서 쏜 ray와 원기둥의 교점 두개

	if (solve_cylinder(x, o, d, lst) == 0) //구의 방정식을 이용해 실린더의 원에 해를 구해옴 ?
		return(INFINITY);
	//밑면으로부터 x까지의 거리 계산
	lst->fig.cy.dist1 = vdot(lst->fig.cy.nv, vsubstract(scal_x_vec(x[0], d),
		vsubstract(lst->fig.cy.c, o)));
	lst->fig.cy.dist2 = vdot(lst->fig.cy.nv, vsubstract(scal_x_vec(x[1], d).
		vsubstract(lst->fig.cy.c, o)));
	if (!((lst->fig.cy,dist1 >= 0 && lst->fig.cy.dis1 <= lst->fig.cy.h
			&& x[0] > EPSILON) || (lst->fig.cy.dist2 >= 0 &&
			lst->fig.cy.dist2 <= lst->fig.cy.h && x[1] > EPSILON)))
		return (INFINITY);
	*normal = calc_cy_normal(x, o, d, lst); //법선벡터
	return (x[0]);
}

//보너스용.
static double	caps_intersection(t_p3 o, t_p3 d, t_fig *lst)
{
	double	id1;
	double	id2;
	t_p3	ip1; //실린더 아랫면 위의 한 점
	t_p3	ip2; //실린더 윗면 위의 한 점
	t_p3	c2; //실린더 윗면의 중심(아랫면의 중심 c)

	c2 = vadd(lst->fig.cy.c, scal_x_vec(lst->fig.cy.h, lst->fig.cy.nv));
	id1 = plane_inter(o, d, lst->fig.cy.c, lst->fig.cy.nv);
	id2 = plane_inter(o, d, c2, lst->fig.cy.nv);
	if (id1 < INFINITY || id2 < INFINIY)
	{
		ip1 = vadd(o, scal_x_vec(id1, d));
		ip2 = vadd(o, scal_x_vec(id2, d));
		if ((id1 < INFINITY && distance(ip1, lst->fig.cy.c) <= lst->fig.cy.r)
				&& (id2 < INFINITY && distance(ip2, c2) <= lst->fig.cy.r))
			return (id1 < id2 ? id1 : id2);
		else if (id1 < INFINITY &&
					distance(ip1, lst->fig.cy.c) <= lst->fig.cy.r)
			return (id1);
		else if (id2 < INFINITY &&
					distance(ip2, c2) <= lst->fig.cy.r)
			return (id2);
	}
	return (INFINITY);
}

double		cylinder_inter(t_p3 o, t_p3 d, t_fig *lst)
{
	double	cy_inter; //실린더의 몸체와 ray가 만나는 점까지의 거리
	double	caps_inter; //보너스용. 실런더의 캡(윗, 밑)과 ray가 만나는 점까지의 거리
	t_p3	cy_normal;//실런더의 법선벡터

	cy_inter = cy_intersection(o, d, &cy_normal, lst);
	if (lst->texture == 4)
		caps_inter = INFINITY;
	else
		caps_inter = caps_intersection(o, d, lst);
	if (cy_inter < INFINITY || caps_inter < INFINITY)
	{
		if (cy_inter < caps_inter)
		{
			lst->normal = cy_normal;
			return (cy_inter);
		}
		lst->normal = lst->fig.cy.nv;
		return (caps_inter);
	}
	return (INFINITY);
}