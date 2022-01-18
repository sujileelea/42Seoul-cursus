/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_calc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 17:02:07 by sujilee           #+#    #+#             */
/*   Updated: 2021/05/26 17:12:33 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

static t_p3	set_camera(int n, t_rss rss, t_mlx mlx)
{
	double	asp_ratio;
	double	correct_fov;
	double	x_offset;
	double	y_offset;
	t_p3	p;

	x_offset = ((n % 3) * 0.5);
	y_offset = ((n / 3) * 0.5);
	asp_ratio = (double)rss.xres / (double)rss.yres;
	correct_fov = tan((mlx.cam->fov * M_PI / 180) / 2);
	p.x = (1 - 2 * ((rss.x + x_offset) / rss.xres)) * asp_ratio * correct_fov;
	p.y = (1 - 2 * ((rss.y + y_offset) / rss.yres)) * correct_fov;
	p.z = 1;
	return (p);
}

//axis : 축
static t_p3	look_at(t_p3 d, t_p3 cam_nv)
{
	t_p3 x_axis;
	t_p3 y_axis;
	t_p3 z_axis;
	t_p3 temp;
	t_p3 rotated;

	temp = vdefine(0, 1, 0);
	z_axis = cam_nv;
	if (cam_nv.y == 1 || cam_nv.y == -1)
		x_axis = cam_nv.y == 1 ? (t_p3){1, 0, 0} : (t_p3){-1 , 0, 0};
	else
		x_axis = vcross(temp, z_axis);
	y_axis = vcross(z_axis, x_axis);
	rotated.x = vdot(d, x_axis);
	rotated.y = vdot(d, y_axis);
	rotated.z = vdot(d, z_axis);
	return (rotated);
}

int		calc_ray(int n, t_rss rss, t_wrap *w)
{
	t_p3	d;
	int		color;

	color = 0;
	d = set_camera(n, rss, w->mlx);
	d = look_at(d, w->mlx.cam->nv);
	color = trace_ray(w->mlx.cam->o, d, w, REFLECTION_LIMIT);
	return (color);
}