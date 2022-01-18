/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 16:56:19 by sujilee           #+#    #+#             */
/*   Updated: 2021/05/26 16:57:33 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	parse_cylinder(t_fig **elem, char *str)
{
	t_fig	*lst;

	ft_addnewlst_back(elem);
	lst = *elem;
	while (lst->next)
		lst = lst->next;
	lst->flag = CY;
	lst->fig.cy.c = parse_p3(&str);
	lst->fig.cy.nv = normalize(parse_p3(&str));
	lst->fig.cy.r = rt_atof(&str) / 2;
	check_values(lst->fig.cy.r, 0, INFINITY, "Cylinder radius");
	lst->fig.cy.h = rt_atof(&str);
	check_values(lst->fig.cy.h, 0, INFINITY, "Cylinder height");
	lst->color = parse_color(&str);
}

void	parse_sphere(t_fig **elem, char *str)
{
	t_fig	*lst;

	ft_addnewlst_back(elem);
	lst = *elem;
	while (lst->next)
		lst = lst->next;
	lst->flag = SP;
	lst->fig.sp.c = parse_p3(&str);
	lst->fig.sp.r = rt_atof(&str) / 2;
	check_values(lst->fig.sp.r, 0, INFINITY, "Sphere radius");
	lst->color = parse_color(&str);
}

void	parse_square(t_fig **elem, char *str)
{
	t_fig	*lst;

	ft_addnewlst_back(elem);
	lst = *elem;
	while (lst->next)
		lst = lst->next;
	lst->flag = SQ;
	lst->fig.sq.c = parse_p3(&str);
	lst->normal = normalize(parse_p3(&str));
	lst->fig.sq.side = rt_atof(&str);
	check_values(lst->fig.sq.side, 0, INFINITY, "Square side");
	lst->color = parse_color(&str);
}

void	parse_plane(t_fig **elem, char *str)
{
	t_fig	*lst;

	ft_addnewlst_back(elem);
	lst = *elem;
	while (lst->next)
		lst = lst->next;
	lst->flag = PL;
	lst->fig.pl.p = parse_p3(&str);
	lst->normal = normalize(parse_p3(&str));
	lst->color = parse_color(&str);
}

void	parse_triangle(t_fig **elem, char *str)
{
	t_fig	*lst;

	ft_addnewlst_back(elem);
	lst = *elem;
	while (lst->next)
		lst = lst->next;
	lst->flag = TR;
	lst->fig.tr.p1 = parse_p3(&str);
	lst->fig.tr.p2 = parse_p3(&str);
	lst->fig.tr.p3 = parse_p3(&str);
	lst->normal = vcross(vsubstract(lst->fig.tr.p3, lst->fig.tr.p1),
			vsubstract(lst->fig.tr.p2, lst->fig.tr.p1));
	lst->color = parse_color(&str);
}