/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pl_sq_tr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 14:38:31 by sujilee           #+#    #+#             */
/*   Updated: 2021/05/31 14:39:55 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

double		plane_inter(t_p3 o, t_p3 d, t_p3 plane_p, t_p3 plane_nv)
{
	double	x;
	double	denom;

	denom = vdot(plane_nv, d);
	if (denom == 0)
		return (INFINITY);
	x = (vdot(plane_nv, vsubstract(plane_p, o))) / denom;
	return (x > 0 ? x : INFINITY);
}

static int	point_out(t_p3 p1, t_p3 p2, t_p3 p3, t_p3 ip)
{
	t_p3	v1;
	t_p3	v2;
	t_p3	vp;

	v1 = vsubstract(p2, p1);
	v2 = vsubstract(p3, p1);
	vp = vsubstract(ip, p1);
	if (vdot(vcross(v1, v2), vcross(v1, vp)) < 0)
		return (1);
	return (0);
}

double		triangle_inter(t_p3 o, t_p3 d, t_fig *lst)
{
	double	id;
	t_p3	ip;

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

double		square_inter(t_p3 o, t_p3 d, t_fig *lst)
{
	t_p3		ip;
	t_sq_info	sq_info;
	double		id;
	double		cos1;
	double		limit;

	id = plane_inter(o, d, lst->fig.sq.c, lst->normal);
	ip = vadd(o, scal_x_vec(id, d));
	sq_info.floor = fabs(lst->normal.y) == 1 ?
		vdefine(1, 0, 0) : vdefine(0, 1, 0);
	sq_info.half_size = vcross(lst->normal, sq_info.floor);
	sq_info.center_to_ip = vsubstract(ip, lst->fig.sq.c);
	cos1 = fabs(vcos(sq_info.half_size, sq_info.center_to_ip));
	if (cos1 < sqrt(2) / 2)
		cos1 = cos(M_PI_2 - acos(cos1));
	limit = (lst->fig.sq.side / 2) / cos1;
	if (mod(sq_info.center_to_ip) <= limit)
		return (id);
	return (INFINITY);
}
