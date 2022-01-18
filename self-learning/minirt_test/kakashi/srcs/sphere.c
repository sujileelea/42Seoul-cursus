/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 17:10:36 by sujilee           #+#    #+#             */
/*   Updated: 2021/05/26 17:11:54 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

static void	solve_sphere(double x[2], t_p3 o, t_p3 d, t_fig *lst)
{
	double	disc;
	t_p3	oc;
	double	k[3];

	oc = vsubstract(o, lst->fig.sp.c);
	k[0] = vdot(d, d);
	k[1] = 2 * vdot(d, oc);
	k[2] = vdot(oc, oc) - lst->fig.sp.r * lst->fig.sp.r;
	disc = k[1] * k[1] - (4 * k[0] * k[2]);
	if (disc < 0)
	{
		x[0] = INFINITY;
		x[1] = INFINITY;
		return ;
	}
	x[0] = (-k[1] + sqrt(disc)) / (2 * k[0]);
	x[1] = (-k[1] - sqrt(disc)) / (2 * k[0]);
}

double		sphere_inter(t_p3 o, t_p3 d, t_fig *lst)
{
	double	close;
	double	x[2];

	close = INFINITY;
	solve_sphere(x, o, d, lst);
	if (x[0] > EPSILON && x[0] < INFINITY)
		close = x[0];
	if (x[1] > EPSILON && x[1] < INFINITY)
		close = x[1] < x[0] ? x[1] : close;
	return (close);
}