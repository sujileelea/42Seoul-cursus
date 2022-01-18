/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 16:38:40 by sujilee           #+#    #+#             */
/*   Updated: 2021/05/26 17:12:33 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

int			calc_pixel_color(int *edge_color, int last[2], t_wrap *w)
{
	t_rss	rss;
	int		*color;

	rss.limit = 3;
	rss.xres = w->data.xres;
	rss.yres = w->data.yres;
	rss.x = w->x;
	rss.y = w->y;
	w->data.bgr = 0x353535;
	color = sample_pixel(edge_color, last, rss, w);
	return (average_supersampled_color(color));
}

void		render_scene(t_wrap *w)
{
	int	edge_color[w->data.xres + 2];
	int	last[2];
	int	color;
	int	n;

	n = w->data.yres;
	w->y = 0;
	while (w->y < n)
	{
		w->x = 0;
		while (w->x < w->data.xres)
		{
			color = calc_pixel_color(edge_color, last, w);
			w->mlx.cam->px_img[w->y * w->data.xres + w->x] = color;
			w->x++;
		}
		ft_printf("\rRendering scene (cam %d/%d) [%d%%]",
				w->mlx.cam->idx, w->data.cam_nb, 100 * (w->y % n) / n);
		w->y++;
	}
	ft_printf("\rRendering scene (cam %d/%d) [100%%]\n",
			w->mlx.cam->idx, w->data.cam_nb);
	return ;
}

//보너스는 
static void	make_wrap(t_mlx mlx, t_scene data, t_fig *lst, t_wrap *wrap)
{
	wrap->mlx = mlx;
	wrap->data = data;
	wrap->lst = lst;
}

//보너스는
static void	rendering(void *ptr)
{
	t_wrap	*w;

	w = (t_wrap *)ptr;
	while (w->mlx.cam)
	{
		render_scene(w);
		w->mlx.cam = w->mlx.cam->next;
	}
}

int			main(int ac, char **av)
{
	t_mlx	mlx;
	t_scene	data;
	t_fig	*lst;
	t_wrap	w;

	if (ac < 2 || ac > 3)
		error_check(1, "");
	if (ac == 2 && ft_strncmp(av[1] + ft_strlen(av[1]) - 3, ".rt", 3))
		error_check(2, "");
	if (ac == 3 && ft_strncmp(av[2], "--save", 6))
		error_check(3, "");
	parse(&mlx, &data, &lst, av);
	init_mlx(&mlx, &data);
	make_wrap(mlx, data, lst, &w);
	rendering(&w);
	if (ac == 3)
		make_bmp(mlx, data, av[1]);
	success_message(ac);
	start_mlx(mlx, data);
	return (0);
}
