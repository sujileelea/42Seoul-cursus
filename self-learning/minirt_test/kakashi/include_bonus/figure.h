/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 18:21:37 by sujilee           #+#    #+#             */
/*   Updated: 2021/05/25 01:04:28 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIGURE_H
# define FIGURE_H

#include "minirt_bonus.h"

// t_p3 :  x, y, z 좌표를 구조체로 묶은것. vec/vec3.h에 선언되어있다.

typedef	struct	s_sp
{
	t_p3	c; //구의 중점 c(x, y, z)를 가리키는 위치벡터
	double	r; //구의 반지름
	int		inside; //카메라가 구의 안/밖에 존재하는지 확인하는 변수
}				t_sp;

typedef struct	s_pl
{
	t_p3	p; //(x, y, z)좌표 ?
}				t_pl;

typedef struct	s_sq
{
	t_p3	c; //정사각형의 중심점
	double	side; //한 변의 길이
}				t_sq;

typedef struct	s_cy
{
	t_p3	c; //밑원의 중점 좌표
	t_p3	nv; //노멀벡터. 즉 법선벡터
	double	r; //밑원의 반지름
	double	h; //원기둥의 높이
	double	dist1; //광선이 도달하는 점1 ?
	double	dist2; //광선이 도달하는 점2 ?
}				t_cy;

typedef struct	s_tr
{
	t_p3	p1; //삼각형의 꼭지점 1
	t_p3	p2; //삼각형의 꼭지점 2
	t_p3	p3; //삼각형의 꼭지점 3
}				t_tr;

union			u_fig //모든 객체를 union으로 저장해서 필요한것만 쓰도록 함 ?
{
	t_sp	sp;
	t_pl	pl;
	t_sq	sq;
	t_cy	cy;
	t_tr	tr;
};

#endif