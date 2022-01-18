/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 14:39:14 by sujilee           #+#    #+#             */
/*   Updated: 2021/05/31 14:39:55 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC3_H
# define VEC3_H

# include <math.h>

typedef struct	s_p3
{
	double	x;
	double	y;
	double	z;
}				t_p3;

t_p3			vdefine(double x, double y, double z);
t_p3			vadd(t_p3 a, t_p3 b);
t_p3			vsubstract(t_p3 a, t_p3 b);
double			vdot(t_p3 a, t_p3 b);
t_p3			vcross(t_p3 a, t_p3 b);
t_p3			scal_x_vec(double t, t_p3 a);
double			mod(t_p3 v);
t_p3			normalize(t_p3 v);
double			vcos(t_p3 a, t_p3 b);
double			vsin(t_p3 a, t_p3 b);
double			distance(t_p3 a, t_p3 b);
t_p3			x_axis_rotation(t_p3 v, double angle);
t_p3			y_axis_rotation(t_p3 v, double angle);
t_p3			z_axis_rotation(t_p3 v, double angle);
#endif
