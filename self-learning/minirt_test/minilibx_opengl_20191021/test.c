/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 22:12:54 by sujilee           #+#    #+#             */
/*   Updated: 2021/04/22 22:31:49 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dest;

	dest = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dest = color;
}

int		main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int		i;
	int		j;
	int		k;

	mlx = mlx_init(); //작성한 프로그램과 윈도우 사이의 연결 초기화
	mlx_win = mlx_new_window(mlx, 600, 400, "miniRT"); //새로운 윈도우 생성
	img.img = mlx_new_image(mlx, 600, 400);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	for (i = 250, k = 99; i < 300; i++, k -= 2)
	{
		for (j = 150 + k; j < 250; j++)
			my_mlx_pixel_put(&img, i, j, 0x0000FF);
	}
	for (i = 300, k = 0; i < 350; i++, k += 2)
	{
		for (j = 150 + k; j < 250; j++)
			my_mlx_pixel_put(&img, i, j, 0x0000FF00);
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}
