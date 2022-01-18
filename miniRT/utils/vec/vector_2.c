/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 14:39:21 by sujilee           #+#    #+#             */
/*   Updated: 2021/05/31 14:39:55 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"

t_p3	scal_x_vec(double t, t_p3 a)
{
	t_p3	v;

	v.x = t * a.x;
	v.y = t * a.y;
	v.z = t * a.z;
	return (v);
}

double	mod(t_p3 v)
{
	return (sqrt(vdot(v, v)));
}

t_p3	normalize(t_p3 v)
{
	t_p3	nv;
	double	mod;

	mod = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
	nv.x = v.x / mod;
	nv.y = v.y / mod;
	nv.z = v.z / mod;
	return (nv);
}

double	vcos(t_p3 a, t_p3 b)
{
	return (vdot(a, b) / (mod(a) * mod(b)));
}

double	vsin(t_p3 a, t_p3 b)
{
	return (sqrt(1 - pow(vcos(a, b), 2)));
}
