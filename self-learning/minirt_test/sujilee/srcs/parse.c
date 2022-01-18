/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 16:53:54 by sujilee           #+#    #+#             */
/*   Updated: 2021/05/27 17:29:15 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	save_args(t_mlx *mlx, t_scene *data, t_fig **lst, char *str)
{
	if (*str == 'R')
		parse_resolution(data, ++str);
	else if (*str == 'A')
		parse_ambient(data, ++str);
	else if (*str == 'c' && (*(str + 1) == 32 || *(str + 1) == 9))
		parse_camera(mlx, data, ++str);
	else if (*str == 'c' && *(str + 1) == 'y' && *(str++) && *(str++))
		parse_cylinder(lst, str);
	else if (*str == 'l' && (*(str + 1) == 32 || *(str + 1) == 9))
		parse_light(&data, ++str);
	else if (*str == 's' && *(str + 1) == 'p' && *(str++) && *(str++))
		parse_sphere(lst, str);
	else if (*str == 's' && *(str + 1) == 'q' && *(str++) && *(str++))
		parse_square(lst, str);
	else if (*str == 'p' && *(str + 1) == 'l' && *(str++) && *(str++))
		parse_plane(lst, str);
	else if (*str == 't' && *(str + 1) == 'r' && *(str++) && *(str++))
		parse_triangle(lst, str);
}

void	parsing(t_mlx *mlx, t_scene *data, t_fig **lst, char *str)
{
	if (*str == '#' || *str == 0)
		return ;
	else
		save_args(mlx, data, lst, str);
}

void	parse(t_mlx *mlx, t_scene *data, t_fig **lst, char **av)
{
	char	*str;
	int		fd;

	*lst = NULL;
	data->l = NULL;
	mlx->cam = NULL;
	data->res_init = 0;
	data->al_init = 0;
	if ((fd = open(av[1], 0)) == -1)
		error_check(7, "rt file can not open");
	while (get_next_line(fd, &str))
	{
		printf("std : : %s\n", str);
		parsing(mlx, data, lst, str);
		free(str);
	}
	if (data->res_init == 0 || data->al_init == 0 || mlx->cam == NULL)
		error_check(4, "Not enough elements in rt file to render a scene");
	free(str);
	close(fd);
}
