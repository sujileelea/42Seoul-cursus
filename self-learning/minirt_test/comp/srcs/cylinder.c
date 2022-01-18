/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 19:29:38 by joockim           #+#    #+#             */
/*   Updated: 2021/05/27 20:16:34 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

static int		solve_cylinder(double x[2], t_p3 o, t_p3 d, t_fig *lst)
{
	t_p3	v;
	t_p3	u;
	double	a;
	double	b;
	double	c;

	v = scal_x_vec(vdot(d, lst->fig.cy.nv), lst->fig.cy.nv);
	v = vsubstract(d, v);
	u = scal_x_vec(vdot(vsubstract(o, lst->fig.cy.c), lst->fig.cy.nv),
			lst->fig.cy.nv);
	u = vsubstract(vsubstract(o, lst->fig.cy.c), u);
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
	double	dist;
	double	res;

	if ((lst->fig.cy.dist1 >= 0 && lst->fig.cy.dist1 <= lst->fig.cy.h)
			&& (lst->fig.cy.dist2 >= 0 && lst->fig.cy.dist2 <= lst->fig.cy.h))
	{
		dist = x[0] < x[1] ? lst->fig.cy.dist1 : lst->fig.cy.dist2;
		res = x[0] < x[1] ? x[0] : x[1];
	}
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
	return (normalize(vsubstract(vsubstract(scal_x_vec(res, d),
			scal_x_vec(dist, lst->fig.cy.nv)), vsubstract(lst->fig.cy.c, o))));
}

static double	cy_intersection(t_p3 o, t_p3 d, t_p3 *normal, t_fig *lst)
{
	double	x[2];

	if (solve_cylinder(x, o, d, lst) == 0)
		return (INFINITY);
	lst->fig.cy.dist1 = vdot(lst->fig.cy.nv, vsubstract(scal_x_vec(x[0], d),
				vsubstract(lst->fig.cy.c, o)));
	lst->fig.cy.dist2 = vdot(lst->fig.cy.nv, vsubstract(scal_x_vec(x[1], d),
				vsubstract(lst->fig.cy.c, o)));
	if (!((lst->fig.cy.dist1 >= 0 && lst->fig.cy.dist1 <= lst->fig.cy.h
					&& x[0] > EPSILON) || (lst->fig.cy.dist2 >= 0 &&
						lst->fig.cy.dist2 <= lst->fig.cy.h && x[1] > EPSILON)))
		return (INFINITY);
	*normal = calc_cy_normal(x, o, d, lst);
	return (x[0]);
}

double			cylinder_inter(t_p3 o, t_p3 d, t_fig *lst)
{
	double	cy_inter;
	t_p3	cy_normal;

	cy_inter = cy_intersection(o, d, &cy_normal, lst);
	if (cy_inter < INFINITY)
		return (cy_inter);
	return (INFINITY);
}
