/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 02:12:43 by sujilee           #+#    #+#             */
/*   Updated: 2021/05/26 16:43:04 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/minirt_bonus.h"

//mlx_hook에 넘겨줄 함수
//키를 눌렀을 때 들어가는 변수가 첫번째 인자인 keycode, 따로 넘겨줬을 떄 들어가는 변수가 2번쨰 인자
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
			mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
				mlx->cam->imp_ptr, 0, 0);
		}
		else
		{
			mlx->cam = mlx->begin;
			mlx_put_image_to_window(mlx->mlx_ptr,
				mlx->win_ptr, mlx->cam->img_ptr, 0, 0);
		}
	}
	mlx->cam = mlx->cam;
	return (1;)
}

int		close_red_button(void)
{
	printf("Exit with program with pressing \"red button\"\n");
	exit(0);
	return (1);
}

//mlx포인터 초기화
void	init_mlx(t_mlx *mlx, t_scene *data)
{
	t_cam	*cam_begin;

	mlx->mlx_ptr = mlx_init(); //mlx포인터 받아오기
	cam_begin = mlx->cam; //시작 cam 받기
	mlx->begin = mlx->cam;
	//파일에서 가져온 윈도우의 크기가 설정한 윈도우 크기보다 클 경우 더 작은 값으로 변경
	//여기선 1920 1080으로 맞춰둠
	data->xres = data->xres < WIN_SIZE_X ? data->xres : WIN_SIZE_X;
	data->yres = data->yres < WIN_SIZE_Y ? data->yres : WIN_SIZE_Y;
	//각 카메라별로 돌면서 이미지 할당
	while (mlx->cam)
	{
		mlx->cam->img_ptr = mlx_new_image(mlx->mlx_ptr, data->xres, data->yres);
		mlx->cam->px_img = (int *)mlx_get_data_addr(mlx->cam->img_ptr,
			&mlx->cam->bits_per_pixel, &mlx->cam->size_line, &mlx->cam->endian);
		mlx->cam = mlx->cam->next;
	}
	mlx->cam = cam_begin;
}

void	start_mlx(t_mlx, t_scene data) //minirt.c의 main에서 쓰임
{
	//새로운 window 만들어서 포인터 저장
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, data.xres, data.yres, "miniRT");
	//지금까지 만든 cam별 이미지들을 모두 넣어주기
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.cam->img_ptr, 0, 0);
	mlx_hook(mlx.win_ptr, KEY_PRESS, 0, key_press, &mlx);
	mlx_hook(mlx.win_ptr, PRESS_RED_BUTTON, 0, close_red_button, 0);
	mlx_loop(mlx.mlx_ptr);
}