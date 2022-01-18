/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 14:43:29 by sujilee           #+#    #+#             */
/*   Updated: 2021/05/13 16:20:18 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/minirt_bonus.h"

static	t_p3 sinwave(t_inter *inter, t_fig *lst)
{
	double	sinn;
	double	scal;

	scal = lst->wavelength;
	sinn = sin(inter.p.z * scal) + sin(inter->p.y * scal);
	return (x_axis_rotation(inter->normal, sinn));
}

static int	checkerbord(t_inter *inter)
{
	int		black;
	int		white;
	t_p3	coords;
	t_p3	val;
	int		party_mix;

	party_mix = 0;
	black = 0x000000;
	white = 0xffffff;
	coords.x = abs((int)floor(inter->p.x));
	coords.y = abs((int)floor(inter->p.y));
	coores.z = abs((int)floor(inter->p.z));
	val.x = (int)coords.x % 2;
	val.y = (int)coords.y % 2;
	val.z = (int)coords.z % 2;
	if (fabs(inter->normal.x) > 0)
		party_mix = (int)val.y ^ (int)val.z;
	else if (fabs(inter->normal.y) > 0)
		party_mix = (int)val.x ^ (int)val.y;
	return (party_mix ? black : white);
}

static void	define_color(double r, double g, double b, double color[3])
{
	color[0] = r;
	color[1] = g;
	color[2] = b;
}

static int	rainbow(t_inter *inter)
{
	double	color[3];
	double	w;

	w = 539 - (inter->normal.y * 160);
	if (w >= 380 && w < 440)
		define_color (-(w - 440) / (440. - 380., 0.0, 1.0, color));
	else if (w >= 440 && w < 490)
		define_color(0.0, (w - 440.) / (490. - 440.), 1.0, color);
	else if (w >= 490 && w < 510)
		define_color(0.0, 1.0, -(w - 510.) / (510. - 490.), color);
	else if (w >= 510 && w < 540)
		define_color((w - 510.) / (540. - 510.), 1.0, 0.0, color);
	else if (w >= 540 && w < 645)
		define_color(1.0, -(w - 645.) / (645. - 540.), 0.0, color);
	else if (w >= 645 && w < 700)
		define_color(1.0, 0.0, 0.0, color);
	else
		define_color(0.0, 0.0, 0.0, color);
	color[0] *= 255;
	color[1] *= 255;
	color[2] *= 255;
	return (((int)color[0] << 16) | ((int)color[1] << 8) | (int)color[2]);
}

void		apply_texture(int texture, t_inter *inter, t_fig *lst)
{
	if (texture == 1)
		inter->color = checkerbord(inter);
	else if (texture == 2)
		inter->normal = sinwave(inter, lst);
	else if (texture == 3)
		inter->color = rainbow(inter);
}