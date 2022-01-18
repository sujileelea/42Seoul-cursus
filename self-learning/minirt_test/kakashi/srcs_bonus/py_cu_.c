/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   py_cu_.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 22:31:45 by sujilee           #+#    #+#             */
/*   Updated: 2021/05/12 00:55:55 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/minirt_bonus.h"

static void	init_cube(t_cube *cube, t_fig *lst)
{
	//6개 면에 대한 각각의 법선벡터를 잡아줌
	cube->normal[0] = vdefine(1, 0, 0);
	cube->normal[1] = vdefine(-1, 0, 0);
	cube->normal[2] = vdefine(0, 1, 0);
	cube->normal[3] = vdefine(0, -1, 0);
	cube->normal[4] = vdefine(0, 0, 1);
	cube->normal[5] = vdefine(0, 0, -1);
	cube->center = lst->fig.sq.c;
	cube->sq.fig.sq.side = lst->fig.sq.side;
}

double		cube_inter(t_p3 o, t_p3 d, t_fig *lst)
{
	t_cube	cube;
	t_p3	close_normal;
	double	close_inter;
	double	inter;
	int		i;

	init_cube(&cube, lst); //cube 구조체 초기화
	close_inter = INFINITY;
	i = 0;
	//모든 면에 대한 계산
	while (i < 6)
	{
		//한 면의 중심점을 잡아줌
		cube.sq.fig.sq.c = vadd(cube.center,
				scal_x_vec(lst->fig.sq.side / 2, cube.normal[i]));
		//한 면의 법선벡터는 현재 큐브의 법선벡터와 같음
		cube.sq.normal = cube.normal[i];
		inter = square_inter(o, d, &(cube.sq)); //정사각형 계산
		if (inter > EPSILON && inter < close_inter)
		{
			close_inter = inter;
			close_normal = cube.sq.normal;
		}
		i++;
	}
	lst->normal = close_normal;
	return (close_inter);
}

static void	init_pyramid(t_pyr *p, t_fig *lst)
{
	int	i;

	p->normal[0] = vdefine(1, 0, 0);
	p->normal[1] = vdefine(0, 0, 1);
	p->normal[2] = vdefine(-1, 0, 0);
	p->normal[3] = vdefine(0, 0, -1);
	p->normal[4] = vdefine(1, 0, 0);
	p->vertex_point = vadd(lst->fig.sq.c,
			scal_x_vec(lst->fig.sq.side, vdefine(0, 1, 0)));
	p->sq.fig.sq.side = lst->fig.sq.sid;
	p->sq.fig.sq.c = lst->fig.sq.c;
	p->sq.normal = vdefine(0, -1 ,0);
	i = 0;
	while (i < 4)
	{
		p->corner[i] = vadd(lst->fig.sq.c,
				scal_x_vec(lst->fig.sq.side / 2, p->normal[i]));
		p->corner[i] = vadd(p->corner[i],
				scal_x_vec(lst->fig.sq.side / 2, p->normal[i + 1]));
		i++;
	}
	p->tr.fig.tr.p3 = p->vertex_point;
}

double		pyramid_inter(t_p3 o, t_p3 d, t_fig *lst)
{
	t_pyr	p;
	t_p3	close_normal;
	double	close_inter;
	double	inter;
	int		i;

	init_pyramid(&p, lst);
	close_inter = INFINITY;
	i = 0;
	while (i < 4)
	{
		p.tr.fig.tr.p1 = p.corner[i];
		p.tr.fig.tr.p2 = i < 3 ? p.corner[i + 1] : p.corner[0];
		p.tr.normal = vcross(vsubstract(p.tr.fig.tr.p3, p.tr.fig.tr.p1)
				vsubstract(p.tr.fig.tr.p2, p.tr.fig.tr.p1));
		inter = triangle_inter(o, d, &(p.tr));
		if (inter > EPSILON && inter < close_inter)
		{
			close_inter = inter;
			close_normal = p.tr.normal;
		}
		i++;
	}
	lst->normal = close_normal;
	return (close_inter);
}