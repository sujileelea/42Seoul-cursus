/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 16:54:22 by sujilee           #+#    #+#             */
/*   Updated: 2021/05/27 17:32:10 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	parse_resolution(t_scene *data, char *str)
{
	if (data->res_init > 0)
		error_check(4, "Double declaration Resolution");
	data->res_init += 1;
	data->xres = rt_atoi(&str);
	skip_space(&str);
	data->yres = rt_atoi(&str);
}

void	parse_ambient(t_scene *data, char *str)
{
	if (data->al_init > 0)
		error_check(4, "Double declaration Ambient lightning");
	data->al_init += 1;
	skip_space(&str);
	data->ambient_light = rt_atof(&str);
	check_values(data->ambient_light, 0, 1, "ambient lightning");
	data->al_color = parse_color(&str);
}

void	parse_camera(t_mlx *mlx, t_scene *data, char *str)
{
	t_cam	*elem;
	t_cam	*begin;
	int		idx;

	idx = 0;
	begin = mlx->cam;
	elem = err_malloc(sizeof(t_cam));
	elem->next = NULL;
	if (mlx->cam)
	{
		while (mlx->cam->next)
			mlx->cam = mlx->cam->next;
		idx = mlx->cam->idx;
		mlx->cam->next = elem;
	}
	else
		mlx->cam = elem;
	elem->idx = idx + 1;
	data->cam_nb = elem->idx;
	elem->o = parse_p3(&str);
	elem->nv = normalize(parse_p3(&str));
	elem->fov = rt_atoi(&str);
	check_values(elem->fov, 0, 180, "Camera FOV");
	mlx->cam = begin ? begin : elem;
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
	if (list)
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
	check_values(list->br, 0, 1, "Light bright");
	list->color = parse_color(&str);
	(*data)->l = begin ? begin : list;
}
