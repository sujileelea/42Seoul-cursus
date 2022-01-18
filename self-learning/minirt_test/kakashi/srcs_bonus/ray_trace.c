/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_trace.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 00:05:00 by sujilee           #+#    #+#             */
/*   Updated: 2021/05/26 17:08:54 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/minirt_bonus.h"

//flag에 따른 계산과 최단거리 정해주기...?
void	try_all_inter(t_v3 ray, t_fig *lst,
			t_fig *close_fig, double *close_inter)
{
	double distance;

	while (lst)
	{
		if (lst->flag == SP)
			distance = sphere_inter(ray.o, ray.d, lst);
		else if (lst->flag == PL)
			distance = plane_inter(ray.o, ray.d, lst->fig.pl.p, lst->normal);
		else if (lst->flag == TR)
			distance = triangle_inter(tay.c, ray.d, lst);
		else if (lst->fig == SQ)
			distance = square_inter(ray.o, ray.d, lst);
		else if (lst->flag == CY)
			distance = cylinder_inter(ray.o, ray.d, lst);
		else if (lst->flag == CU)
			distance  cube_inter(ray.o, ray.d, lst);
		else if (lst->flag == PY)
			distance = pyramid_inter(ray.o, ray.d, lst);
		if (distance > EPSILON && distance < *close_inter)
		{
			*close_fig = *lst;
			*close_inter = distance;
		}
		lst = lst->next;
	}
}

//도형의 법선벡터 계산. 법선벡터를 카메라 방향으로 바꿔줌
void	calc_normal(t_inter *inter, t_p3 d, t_fig *lst)
{
	if (lst->flag == SP) //구의 경우
	{
		//구의 중심에서 점 p로 향하는 벡터의 단위벡터를 법선벡터로 잡음
		inter->normal = normalize(vsubstract(inter->p, lst->fig.sp.c));
		if (vcos(d, inter->normal) > 0) //90도 이하면
		{
			inter->normal = scal_x_vec(-1, inter->normal); //법선벡터를 카메라 방향으로 전환
			lst->fig.sp.inside = 1; //카메라는 구 안에 있음
		}
		else
			lst->fig.sp.inside = 0; //90도 이상이면 카메라는 구 밖에 있음
	}
	else
		inter->normal = vcos(d, lst->normal) > 0 ? scal_x_vec(-1, lst->normal) :
			lst->normal; //두 벡터가 90도 이하이면 법선벡터를 카메라 방향으로 바꿈
}

//보너스용.
//굴절률 계산
t_p3	refract_ray(t_p3 d, t_p3 normal, t_fig *lst)
{
	double cosi;
	double etai;
	double etat;
	double eta;
	double k;

	cosi = vdot(d, normal);
	etai = 1;
	etat = lst->refr_idx;
	if (lst->fig.sp.inside == 1)
	{
		k = etai;
		etai = etat;
		etat = k;
	}
	eta = etai / etat;
	k = 1 - eta * eta * (1 - cos1 * cosi);
	return (k < 0 ? reflect_ray(scal_x_vec(-1, d), normal) :
		 vadd(scal_x_vec(eta, d), scal_x_vec(eta - (sqrt(k) / cosi), normal)));
}

//calc_ray에서 color 계산해주는 부분
int		trace_ray(t_p3 o, t_p3 d, t_wrap *w, int depth)
{
	t_v3	ray;
	t_fig	close_fig;
	t_inter	inter;
	double	close_inter;
	double	r; //? 보너스용.

	ray.o = o;
	ray.d = d;
	close_inter = INFINITY;
	close_fig.flag = -1;
	try_all_inter(ray, w->lst, &close_fig, &close_inter);
	inter.p = vadd(o, scal_x_vec(close_inter, d));
	calc_normal(&inter, d, &close_fig);
	//컬러값 지정. 만약 플래그가 -1이라면(도형이 없다면) 기본값으로 설정해줌
	inter.color = close_fig.flag != -1 ? close_fig.color : w->data.bgr;
	apply_texture(close_fig.texture, &inter, w->lst); //보너스용. 텍스처 값 추가
	compute_light(ray, &inter, w->data, w->lst); //빛 계산
	//여기서부터 보너스용.
	r = close_fig.flag != -1 ? close_fig.refl_idx : 0;
	close_fig.refr_idx = close_fig.flag != -1 ? close_fig.refr_idx : 0;
	if (close_fig.refr_dix > 0)
		inter.color = trace_ray(inter.p,
			refract_ray(d, inter.normal, &close_fig), w, depth);
	if (r > 0 && depth > 0)
		inter.ref_color = trace_Ray(inter.p,
			reflect_ray(scal_x_vec(-1, d), inter.normal, w, depth - 1) // ?
	return (cadd(cproduct(inter.color, 1 - r), cproduct(inter.ref_color, r)));
}