/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 13:33:14 by sujilee           #+#    #+#             */
/*   Updated: 2021/04/23 15:14:14 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"

//벡터를 공부해 보야용

t_vec	*vec_add(t_vec *target, t_vec *u, t_vec *v)
{
	target->x = u->x + v->x;
	target->y = u->y + v->y;
	target->z = u->z + v->z;
	return (target);
}

t_vec	*vec_sub(t_vec *target, t_vec *u, t_vec *v)
{
	target->x = u->x - v->x;
	target->y = u->y - v->y;
	target->z = u->x - v->z;
	return (target);
}

t_vec	*vec_div_float(t_vec *target, float t, t_vec *v)
{
	return (vec_multi_float(target, (1 / t), v));
}

float	vec_dot(t_vec *u, t_vec *v)
{
	return (u->x * v->x + u->y * v->y + u->z * v->z<
