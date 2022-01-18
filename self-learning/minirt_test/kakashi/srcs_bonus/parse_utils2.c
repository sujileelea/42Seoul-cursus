/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 19:34:30 by sujilee           #+#    #+#             */
/*   Updated: 2021/05/10 23:28:12 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/minirt_bonus.h"


//rgb 파싱 시 콤마를 스킵해주는 함수. 콤마가 아니면 에러
void	comma(char **str)
{
	if (**str != ',')
		error_check(4, "Parameter has wrong format");
	(*str)++;
}

//각 rgb 정보를 파싱, 모두 더해 16진수의 형태로 바꿔줌
int		parse_color(char **str)
{
	int		r;
	int		g;
	int		b;

	r = 0;
	g = 0;
	b = 0;
	r |= rt_atoi(str); //비트 or 연산
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

//p3 구조체로 파싱해서 변환 ?
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

//카메라나 빛의 경우 연결리스트의 형태로 구현하기 때문에 포인터로 주는 함수 ?
void	ft_addnewlst_back(t_fig **alst)
{
	t_fig	*begin;
	t_fig	*elem;
	t_fig	list;

	begin = *alst;
	list = *alst;
	elem = err_malloc(sizeof(t_fig));
	elem->next - NULL;
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