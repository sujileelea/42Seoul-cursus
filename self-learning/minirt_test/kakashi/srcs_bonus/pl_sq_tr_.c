/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pl_sq_tr_.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 23:31:21 by sujilee           #+#    #+#             */
/*   Updated: 2021/05/12 00:53:12 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/minirt_bonus.h"

static int	point_out(t_p3 p1, t_p3 p2, t_p3 p3, t_p3 ip)
{
	t_p3	v1;
	t_p3	v2;
	t_p3	vp;

	v1 = vsubstract(p2 ,p1); //p1에서 p2로 가는 벡터
	v2 = vsubstract(p3, p1); //p1에서 p3로 가는 벡터
	vp = vsubstract(ip, p1); //p1에서 평면 위의 점으로 가는 벡터
	if (vdot(vcross(v1, v2), vcross(v1, vp)) < 0) //위 값들의 외적으로 유효성을 검사
		return (1);
	return (0);
}

double		plane_inter(t_p3 o, t_p3 d, t_p3 plane_p, t_p3 plane_nv)
{
	double x;
	double denom;

	denom = vdot(plane_nv, d); //카메라 to pixel 방향벡터와 법선벡터 내적
	if (denom == 0) //벡터의 내적이 0이라는 건 두 벡터가 수직이라는 것
		return (INFINITY);
	//카메라에서 plane 위의 모든 점을 향한 벡터의 내적은 모두 같음
	//camera to point와 법선벡터를 내적하면 임의의 한 점까지의 거리를 알 수 있음
	x = (vdot(plane_nv, vsubstract(plane_p, o))) / denom;
	return (x > 0 ? x : INFINITY);
}

double		triangle_inter(t_p3 o, t_p3 d, t_fig *lst)
{
	double	id; //camera to point까지의 거리
	t_p3	ip; //삼각형(평면) 위의 점 

	id = plane_inter(o, d, lst->fig.tr.p1, lst->normal);
	ip = vadd(o, scal_x_vec(id, d));
	if (point_out(lst->fig.tr.p1, lst->fig.tr.p2, lst->fig.tr.p3, ip))
		return (INFINITY);
	if (point_out(lst->fig.tr.p2, lst->fig.tr.p3, lst->fig.tr.p1, ip))
		return (INFINITY);
	if (point_out(lst->fig.tr.p3, lst->fig.tr.p1, lst->fig.tr.p2, ip))
		return (INFINITY);
	return (id);
}

//사각형의 경우 정사각형의 형태로 고려
//현재 가지고 있는 정보 : 정사각형의 중심좌표와 사각형(평면)의 법선벡터
//sq_info.floor : 법선벡터를 이용해 임의의 벡터를 하나 정해줌 -> half_size를 정하기 위해
double		square_inter(t_p3 o, t_p3 d, t_fig *lst)
{
	t_p3		ip;
	t_sq_info	sq_info;
	double		id;
	double		cos1;
	double		limit; //사각형의 중점에서 한 꼭지점까지의 거리

	id = plane_inter(o, d, lst->fig.sq.c, lst->normal); //카메라에서 point까지의 거리
	ip = vadd(o, scal_x_vec(id, d)); //point의 좌표
	sq_info.floor = fabs(lst->normal.y) == 1 ? vdefine(1, 0, 0) : 
		vdefine(0, 1, 0);
	sq_info.half_size = vcorss(lst->normal, sq_info.floor);
	sq_info.center_to_ip = vsubstract(ip, lst->fig.sq.c);
	cos1 = fabs(vcos(sq_info.half_size, sq_info.center_to_ip));
	if (cos1 < sqrt(2) / 2)
		cos1 = cos(M_PI_@ - acos(cos1));
	limit = (lst->fig.sq.side / 2) / cos1;
	if (mod(sq_info.center_to_ip) <= limit)
		return (id);
	return (INFINITY);
}