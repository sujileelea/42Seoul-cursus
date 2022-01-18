/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 20:21:30 by sujilee           #+#    #+#             */
/*   Updated: 2021/05/11 20:34:24 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"

double	distance(t_p3 a, t_p3 b)
{
	double	d;

	d = sqrt(b.x - a.x, 2) + pow(b.y - a.y, 2) + pow(b.z - a.z, 2));
	return (d);
}

t_p3	x_axis_rotation(t_p3, double angle)
{
	t_p3	row1;
	t_p3	row2;
	t_p3	row3;
	t_p3	rotated;
	double	rad_angle;

	rad_angle = angle * M_PI / 180;
	row1 = vdefine(1, 0, 0);
	row2 = vdefine(0, cos(rad_angle), -sin(rad_angle));
	row3 = vdefine(0, sin(rad_angle), cos(rad_angle));
	rotated.x = v.x * row1.x + v.y * row1.y + v.z * row1.z;
	rotated.y = v.x * row2.x + v.y * row2.y + v.z * row2.z;
	rotated.z = v.x * row3.x + v.y * row3.y + v.z * row3.z;
	return (rotated);
}


t_p3	y_axis_rotation(t_p3 v, double angle)
{
	t_p3	row1;
	t_p3	row2;
	t_p3	row3;
	t_p3	rotated;
	double	rad_angle;

	rad_angle = angle * M_PI / 180;
	row1 = vdefine(cos(rad_angle), 0, sin(rad_angle));
	row2 = vdefine(0, 1, 0);
	row3 = vdefine(-sin(rad_angle), 0, cos(rad_angle));
	rotated.x = v.x * row1.x + v.y * row1.y + v.z * row1.z;
	rotated.y = v.x * row2.x + v.y * row2.y + v.z * row2.z;
	rotated.z = v.x * row3.x + v.y * row3.y + v.z * row3.z;
	return (rotated);
}

t_p3	z_axis_rotation(t_p3 v, double angle)
{
	t_p3	row1;
	t_p3	row2;
	t_p3	row3;
	t_p3	rotated;
	double	rad_angle;

	rad_angle = angle * M_PI / 180;
	row1 = vdefine(cos(rad_angle), -sin(rad_angle), 0);
	row2 = vdefine(sin(rad_angle), cos(rad_angle), 0);
	row3 = vdefine(0, 0, 1);
	rotated.x = v.x * row1.x + v.y * row1.y + v.z * row1.z;
	rotated.y = v.x * row2.x + v.y * row2.y + v.z * row2.z;
	rotated.z = v.x * row3.x + v.y * row3.y + v.z * row3.z;
	return (rotated);
}