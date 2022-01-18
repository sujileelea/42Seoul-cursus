/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hello.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 20:19:45 by sujilee           #+#    #+#             */
/*   Updated: 2021/04/30 20:39:34 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "vec3.h"

typedef struct	s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	int		*data;
	int		bpp;
	int		size_l;
	int		endian;
}			t_mlx;

t_mlx app;

int		main(void)
{
	const int image_width = 256;
	const int image_height = 256;
	t_vec	pizxel_color;

	app.mlx_ptr = mlx_init();
	app.win_ptr = mlx_new_window(app.mlx_ptr, 256, 256, "PPM IMAGE");
	app.img_ptr = mllx_new_image(app.mlx_ptr, image_width, image_height);
	app.data = mlx_new_image(app.img_ptr, &app.bpp, &app.size_l, &app.endian);

	int	j = 0;
	while (j < image_height)
	{
		int i = 0;
		while (i < image_width)
		{
			float r = (double)i / (image_width - 1);
			float g = (image_height - (double)j - 1) / (image_height - 1);
			float b = 0.25;

			int	ir = 255.999 * r;
			int ig = 255.999 * g;
			int ib = 255.999 * b;

			pixel_color.x = ir * 256 * 256;
			pixel_color.y = ig * 256;
			pixel_color.z = ib;

			printf("%d, %d, %d\n", ir, ig, ib);

			int	color = pixel_color.x + pixel_color.y + pixel_color.z;
			app.data[j * 256 + i] = mlx_get_color_value(app.mlx_ptr, color);
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(app.mlx_ptr, app.win_ptr, app.img_ptr, 0, 0);
	mlx_loop(app.mlx_ptr);
}
