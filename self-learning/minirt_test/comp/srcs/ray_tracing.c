/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 17:13:43 by joockim           #+#    #+#             */
/*   Updated: 2021/05/27 19:11:04 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void		try_all_inter(t_v3 ray, t_fig *lst,
		t_fig *close_fig, double *close_inter)
{
	double	distance;

	while (lst)
	{
		if (lst->flag == SP)
			distance = sphere_inter(ray.o, ray.d, lst);
		else if (lst->flag == PL)
			distance = plane_inter(ray.o, ray.d, lst->fig.pl.p, lst->normal);
		else if (lst->flag == TR)
			distance = triangle_inter(ray.o, ray.d, lst);
		else if (lst->flag == SQ)
			distance = square_inter(ray.o, ray.d, lst);
		else if (lst->flag == CY)
			distance = cylinder_inter(ray.o, ray.d, lst);
		if (distance > EPSILON && distance < *close_inter)
		{
			*close_fig = *lst;
			*close_inter = distance;
		}
		lst = lst->next;
	}
}

void		calc_normal(t_inter *inter, t_p3 d, t_fig *lst)
{
	if (lst->flag == SP)
	{
		inter->normal = normalize(vsubstract(inter->p, lst->fig.sp.c));
		if (vcos(d, inter->normal) > 0)
		{
			inter->normal = scal_x_vec(-1, inter->normal);
			lst->fig.sp.inside = 1;
		}
		else
			lst->fig.sp.inside = 0;
	}
	else
		inter->normal = vcos(d, lst->normal) > 0 ? scal_x_vec(-1, lst->normal)
			: lst->normal;
}

int			trace_ray(t_p3 o, t_p3 d, t_wrap *w)
{
	t_v3	ray;
	t_fig	close_fig;
	t_inter	inter;
	double	close_inter;

	ray.o = o;
	ray.d = d;
	close_inter = INFINITY;
	close_fig.flag = -1;
	try_all_inter(ray, w->lst, &close_fig, &close_inter);
	inter.p = vadd(o, scal_x_vec(close_inter, d));
	calc_normal(&inter, d, &close_fig);
	inter.color = close_fig.flag != -1 ? close_fig.color : w->data.bgr;
	compute_light(ray, &inter, w->data, w->lst);
	return (inter.color);
}
