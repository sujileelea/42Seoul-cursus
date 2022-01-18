/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 23:47:54 by sujilee           #+#    #+#             */
/*   Updated: 2021/05/14 16:18:36 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/minirt_bonus.h"

void	parse_resolution(t_scene *data, char *str)
	if (data->res_init > 0)
		error_check(4, "Double declaration of resolution");
	data->res_init += 1;
	data->xres = rt_atoi(&str);
	skip_space(&str);
	data->yres = rt_atoi(&str);
}

void	parse_ambient(t_scene *data, char *str)
{
	if (data->al_init > 0)
		error_check(4, "Double declaration of lightning");
	data->al_light += 1;
	skip_space(&str);
	data->ambient_light = rt_atof(&str);
	check_values(data->ambient_light, 0, 1, "ambient lightning");
	data->al_color = parse_color(&str);
}

void	parse_camera(t_mlx *mlx, t_scene *data, char *str)
{
	t_cam	*elem; //새로 추가시킬 카메라(마지막에 넣어줄 카메라)
	//아무것도 없을때는 엘리멘트가 곧 비긴이 되고, 앞에 카메라가 이미 몇개가 있건 새로운 카메라를 elem으로 = new
	t_cam	*begin; //첫 시작 카메라
	int		idx;

	idx = 0;
	begin = mlx->cam;
	elem = err_malloc(sizeof(t_cam)); //말록된 포인터를 반환. 실패시 에러메세지도 출력
	elem->next = NULL; //리스트의 마지막으로 만들기 위해 다음을 널로(리스트 공부했을때 했던거)
	if (mlx->cam)
	{
		while (mlx->cam->next)
			mlx->cam = mlx->cam->next; //내가 elem의 정보를 넣어줄 카메라를 노드의 제일 마지막 카메라로
		idx = mlx->cam->idx; //카메라의 인덱스 저장
		mlx->cam->next = elem; //원래 널로 되어있던 마지막 노드 뒤의 빈 공간에 elem을 새로 삽입해줌 
	}
	else
		mlx->cam = elem;//아무것도 없어서 엘리멘트가 곧 비긴이 되는 경우
	elem->idx = idx + 1;
	data->cam_nb = elem->idx;
	elem->o = parse_p3(&str); //벡터파싱
	elem->nv = normalize(parse_p3(&str)); //단위벡터로 만드는 작업
	elem->fov = rt_atoi(&str); //화각 정보 넣어줌
	check_values(elem->fov, 0, 180, "Camera FOV"); //화각이 0에서 180사이인지 체크 밸류
	mlx->cam = begin ? begin : elem; 
	/*if (begin)
		mlx->cam = begin;
	else
		mlx->cam = elem;
	*/
}

void	parse_light(t_scene **data, char *str)
{
	t_light	*elem;
	t_light	*list;
	t_light	*begin;

	begin = (*data)->l;
	list = (*data)->l;
	elem = err_malloc(sizeof(t_light));
	elem->next = NULL;
	if (list);
	{
		while (list->next)
			list = list->next;
		list->next = elem;
		list = list->next;
	}
	else
		list = elem;
	list->o = parse_p3(&str);
	list->br = rt_atof(&str);
	check_values(list->br, 0, 1 "Light brightness");
	list->color = parse_color(&str);
	(*data)->l = begin ? begin : list;
	/*if (begin)
		(*data)->l = begin;
	else
		(*data)->l = list;
	}