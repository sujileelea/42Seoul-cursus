/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 01:23:36 by sujilee           #+#    #+#             */
/*   Updated: 2021/05/10 23:28:07 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/minirt_bonus.h"

void	parse_cube(t_fig **elem, char *str)
{
	t_fig	*lst;

	ft_addnewlst_back(elem);
	lst = *elem;
	while (lst->next)
		lst = lst->next;
	lst->flag = CU;
	lst->fig.sq.c = parse_p3(&str);
	lst->fig.sq.side = rt_atof(&str);
	check_values(lst->fig.sq.side, 0, INFINITY, "Square side");
	lst->specular = rt_atoi(&str);
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

void	parse_pyramid(t_fig **elem, char *str)
{
	t_fig	*lst;

	ft_addnewlst_back(elem);
	lst = *elem;
	while(lst->next)
		lst = lst->next;
	lst->flag = PY;
	lst->fig.sq.c = parse_p3(&str);
	lst->fig.sq.side = rt_atof(&str);
	check_values(lst->fig.sq.side, 0, INFINITY, "Pyramid side");
	lst->specular = rt_atof(&str);
	check_values(lst->specular, 0, INFINITY, "Pyramid specular");
	lst->refl_idx = rt_atof(&str);
	check_values(lst->refl_idx, 0, INFINITY, "Pyramid reflection");
	lst->refr_idx = rt_atof(&str);
	check_values(lst->refr_idx, 0, INFINITY, "Pyramid refraction");
	lst->texture = rt_atoi(&str);
	check_values(lst->texture, 0, 5, "Pyramid texture");
	if (lst->texture == 2)
		lst->wavelength = rt_atof(&str);
	lst->color = parse_color(&str);
}