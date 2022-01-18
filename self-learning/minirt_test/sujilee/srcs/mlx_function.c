/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 16:43:36 by sujilee           #+#    #+#             */
/*   Updated: 2021/05/27 16:25:10 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

int		key_press(int keycode, t_mlx *mlx)
{
	if (keycode == ESC)
	{
		printf("Exit program with pressing \"esc\" key\n");
		exit(0);
	}
	if (keycode == SPACE_BAR)
	{
		if (mlx->cam->next)
		{
			mlx->cam = mlx->cam->next;
			mlx_put_image_to_window(mlx->mlx_ptr,
					mlx->win_ptr, mlx->cam->img_ptr, 0, 0);
		}
		else
		{
			mlx->cam = mlx->begin;
			mlx_put_image_to_window(mlx->mlx_ptr,
					mlx->win_ptr, mlx->cam->img_ptr, 0, 0);
		}
	}
	mlx->cam = mlx->cam;
	return (1);
}

int		close_red_button(void)
{
	printf("Exit program with pressing \"red button\"\n");
	exit(0);
	return (1);
}

void	init_mlx(t_mlx *mlx, t_scene *data)
{
	t_cam	*cam_begin;

	mlx->mlx_ptr = mlx_init();
	cam_begin = mlx->cam;
	mlx->begin = mlx->cam;
	data->xres = data->xres < WIN_SIZE_X ? data->xres : WIN_SIZE_X;
	data->yres = data->yres < WIN_SIZE_Y ? data->yres : WIN_SIZE_Y;
	while (mlx->cam)
	{
		mlx->cam->img_ptr = mlx_new_image(mlx->mlx_ptr, data->xres, data->yres);
		mlx->cam->px_img = (int *)mlx_get_data_addr(mlx->cam->img_ptr,
			&mlx->cam->bits_per_pixel, &mlx->cam->size_line, &mlx->cam->endian);
		mlx->cam = mlx->cam->next;
	}
	mlx->cam = cam_begin;
}

void	start_mlx(t_mlx mlx, t_scene data)
{
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, data.xres, data.yres,
			"miniRT");
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.cam->img_ptr, 0, 0);
	mlx_hook(mlx.win_ptr, KEY_PRESS, 0, key_press, &mlx);
	mlx_hook(mlx.win_ptr, PRESS_RED_BUTTON, 0, close_red_button, 0);
	mlx_loop(mlx.mlx_ptr);
}
