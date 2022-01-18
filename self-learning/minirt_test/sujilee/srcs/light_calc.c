/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_calc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 16:34:38 by sujilee           #+#    #+#             */
/*   Updated: 2021/05/27 16:29:32 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

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

int			is_light(t_p3 o, t_p3 d, t_fig *lst)
{
	double	in;

	while (lst)
	{
		if (lst->flag == SP)
			in = sphere_inter(o, d, lst);
		else if (lst->flag == PL)
			in = plane_inter(o, d, lst->fig.pl.p, lst->normal);
		else if (lst->flag == TR)
			in = triangle_inter(o, d, lst);
		else if (lst->flag == SQ)
			in = square_inter(o, d, lst);
		else if (lst->flag == CY)
			in = cylinder_inter(o, d, lst);
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
	ft_memset(rgb, 0, 3 * sizeof(double));
	add_coefficient(&rgb, data.ambient_light, data.al_color);
	while (data.l)
	{
		direction = vsubstract(data.l->o, inter->p);
		if (is_light(inter->p, direction, lst)
				&& vdot(inter->normal, direction) > 0)
		{
			light = data.l->br * vcos(inter->normal, direction);
			add_coefficient(&rgb, light, data.l->color);
		}
		ray.o = ray.o;
		data.l = data.l->next;
	}
	inter->color = color_x_light(inter->color, rgb);
}
