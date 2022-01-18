/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 16:51:34 by sujilee           #+#    #+#             */
/*   Updated: 2021/05/26 16:52:58 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	comma(char **str)
{
	if (**str != ',')
		error_check(4, "Parameter have wrong format");
	(*str)++;
}

int		parse_color(char **str)
{
	int r;
	int g;
	int b;

	r = 0;
	g = 0;
	b = 0;
	r |= rt_atoi(str);
	check_values(r, 0, 255, "color");
	r <<= 16;
	comma(str);
	g |= rt_atoi(str);
	check_values(g, 0, 255, "color");
	g <<= 8;
	comma(str);
	b |= rt_atoi(str);
	check_values(b, 0, 255, "color");
	return (r | g | b);
}

t_p3	parse_p3(char **str)
{
	t_p3	p;

	p.x = rt_atof(str);
	comma(str);
	p.y = rt_atof(str);
	comma(str);
	p.z = rt_atof(str);
	return (p);
}

void	ft_addnewlst_back(t_fig **alst)
{
	t_fig	*begin;
	t_fig	*elem;
	t_fig	*list;

	begin = *alst;
	list = *alst;
	elem = err_malloc(sizeof(t_fig));
	elem->next = NULL;
	if (list)
	{
		while (list->next)
			list = list->next;
		list->next = elem;
	}
	else
		begin = elem;
	*alst = begin;
}