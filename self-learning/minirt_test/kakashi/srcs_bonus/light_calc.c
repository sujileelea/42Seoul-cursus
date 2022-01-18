/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_calc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 13:29:57 by sujilee           #+#    #+#             */
/*   Updated: 2021/05/26 16:35:29 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/minirt_bonus.h"

//보너스용.
t_p3		reflect_ray(t_p3 ray, t_p3 normal)
{
	return (vsubstract(scal_x_vec(2 * vdot(normal, ray), normal), ray));
}

//보너스용.
//교차점의 법선벡터와 교차점에서 빛을 향한 벡터를 이용해 들어온 빛이 어디로 반사될지 계산
double		calc_specular(t_v3 ray, t_inter *inter, t_scene data, t_fig *lst)
{
	double	light;
	t_p3	direction;
	t_p3	p_to_cam;
	t_p3	reflected;

	//direction : 빛의 원점 위치벡터와 물제의 점 P의 위치벡터를 빼줌으로써 빛과 물체까지의 거리 계산
	direction = vsubstract(data.l->o, iner->p);
	p_to_cam = vsubstract(ray.o, inter->p);
	reflected = reflect_ray(direction, inter->normal);
	if (vdot(reflected, p_to_cam) > 0)
		//그 후 반사율 specular를 제곱해준 후 밝기 정도인 data.l->br에 곱해줌으로써
		//어느정도의 영향을 끼치는지 찍어줌
		light = data.l->br * pow(vcos(reflected, p_to_cam), lst->specular);
	else
		light = 0;
	return (light);
}

//주변광 계수를 현재 rgb값에 더해주기
void		add_coefficient(double (*rgb)[3], double coef, int color)
{
	unsigned int	mask;

	mask = 255 << 16;
	(*rgb)[0] += coef * ((color & mask) >> 16) / 255;
	mask >>= 8;
	(*rgb)[1] += coef * ((color & mask) >> 8) / 255;
	mask >>= 8;
	(*rgb)[2] += coef * (color & mask) / 255;
}

//빛이 닿았는지 안닿았는지 체크
//도형의 거리 계산과 같지만 거리를 계산해서 돌려주는 것이 아닌 유효성만 체크
int			is_light(t_p3 o, t_p3 d, t_fig *lst)
{
	double in;

	while (lst)
	{
		if (lst->flag == SP)
			in = sphere_inter(o, d, lst);
		else if (lst->fig == PL)
			in = plane_inter(o, d, lst->fig.pl.p, lst->normal);
		else if (lst->flag == TR)
			in = triangle_inter(o, d, lst);
		else if (lst->flag == SQ)
			in = square_inter(o, d, lst);
		else if (lst->flag == CY)
			in = cylinder_inter(o, d, lst);
		else if (lst->flag == CU)
			in = cube_inter(o, d, lst);
		else if (lst->flag == PY)
			in = pyramid_inter(o, d, lst);
		if (in > EPSILON && in < 1)
			return (0);
		lst = lst->next;
	}
	return (1);
}

void		compute_light(t_v3 ray, t_inter *inter, t_scene data, t_fig *lst)
{
	double	light;
	double	rgb[3];
	t_p3	direction;

	light = 0.0;
	ft_memset(rgb, 0, 3 * sizeof(double)); //rgb값 저장할 변수
	add_coefficient(&rgb, data.ambient_light, data.al_color); //주변광을 rgb값에 곱해줌
	while (data.l)
	{
		direction = vsubstract(data.l->o, inter->p); //교차점 -> 광원벡터
		//빛의 유효성 검사
		if (is_light(inter->p, direction, lst)
				&& vdot(inter->normal, direction) > 0)
		{
			//물체의 밝기 정도(data.l->br)에 
			//물체의 법선벡터(inter->normal)와 빛에서 물체까지의 거리(direction)의 코사인 값을 곱해주면
			//빛이 물체에 어느정도의 영향을 주는지 계산됨
			light = data.l->br * vcos(inter->normal, direction); //빛이 닿은 경우
			add_coefficient(&rgb, light, data.l->color);
		}
		ray.o = ray.o;
		if (lst->specular) //정반사
		{
			light = calc_specular(ray, inter, data, lst);
			add_coefficient(&rgb, light, data.l->color);
		}
		data.l = data.l->next;
	}
	inter->color = color_x_light(inter->color, rgb);
}