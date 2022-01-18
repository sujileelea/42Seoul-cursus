/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 23:04:47 by sujilee           #+#    #+#             */
/*   Updated: 2021/05/26 17:12:33 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/minirt_bonus.h"

//도형은 기본적인 요소 + specular(렌즈?), reflection(반사), refraction(굴절), texture 추가
//추가적인 네개의 요소는 공통된 모양이기에 공통된 구조체에 들어감
//추가된 것들은 보너스용.

void	parse_plane(t_fig **elem, char *str)
{
	t_fig	*lst;

	ft_addnewlst_back(elem); //노드 맨 뒤에 새로운 리스트를 추가시켜줌
	lst = *elem;
	while (lst->next)
		lst = lst->next;
	lst->flag = PL;
	lst->fig.pl.p = parse_p3(&str);
	lst->normal = normalize(parse_p3(&str));
	lst->specular = rt_atof(&str); //specular는 정반사값
	check_values(lst->specular, 0, INFINITY, "Square specular"); //0부터 큰 수 사이로 값이 들어옴
	lst->refl_idx = rt_atof(&str);
	check_values(lst->refl_idx, 0, INFINITY, "Square reflection");
	lst->refr_idx = rt_atof(&str);
	check_values(lst->refr_idx, 0, INFINITY, "Square refraction");
	lst->texture = rt_atoi(&str);
	check_values(lst->texture, 0, 5, "Square texture");
	if (lst->texture == 2)
		lst->wavelength = rt_atoi(&str);
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
	lst->specular = rt_atof(&str);
	check_values(lst->specular, 0, INFINITY, "Sphere specular");
	lst->refl_idx = rt_atof(&str);
	check_values(lst->refl_idx, 0, INFINITY, "Sphere reflection");
	lst->refr_idx = rt_atof(&str);
	check_values(lst->refr_idx, 0, INFINITY, "Sphere refraction");
	lst->texture = rt_atoi(&str);
	check_values(lst->texture, 0, 5, "Sphere texture");
	if (lst->texture == 2)
		lst->wavelength = rt_atof(&str);
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
	lst->specular = rt_atof(&str);
	check_values(lst->specular, 0, INFINITY, "Square specular");
	lst->refl_idx = rt_atof(&str);
	check_values(lst->refl_idx, 0, INFINITY, "Square reflection");
	lst->refr_idx = rt_atof(&str);
	check_values(lst->refr_idx, 0, INFINITY, "Square refraction");
	lst->texture = rt_atoi(&str);
	check_values(lst->texture, 0, 5, "Square texture");
	if (lst->texture == 2)
		lst->wavelength = rt_atof(&str);
	lst->color = parse_color(&str);
}

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
	lst->specular = rt_atof(&str);
	check_values(lst->specular, 0, INFINITY, "Cylinder specular");
	lst->refl_idx = rt_atof(&str);
	check_values(lst->refl_idx, 0, 1, "Cylinder reflection");
	lst->refr_idx = rt_atof(&str);
	check_values(lst->refr_idx, 0, INFINITY, "Cylinder refraction");
	lst->texture = rt_atoi(&str);
	check_values(lst->texture, 0, 5, "Cylinder texture");
	if (lst->texture == 2)
		lst->wavelength = rt_atof(&str);
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
	lst->specular = rt_atoi(&str);
	check_values(lst->specular, 0, INFINITY, "Triangle specular");
	lst->refl_idx = rt_atof(&str);
	check_values(lst->refl_idx, 0, INFINITY, "Triangle reflection");
	lst->refr_idx = rt_atof(&str);
	check_values(lst->refr_idx, 0, INFINITY, "Triangle refraction");
	lst->texture = rt_atoi(&str);
	check_values(lst->texture, 0, 5, "Triangle texture");
	if (lst->texture == 2)
		lst->wavelength = rt_atof(&str);
	lst->color = parse_color(&str);
}