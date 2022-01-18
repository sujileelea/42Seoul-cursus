/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supersample.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 16:36:58 by sujilee           #+#    #+#             */
/*   Updated: 2021/05/13 16:49:39 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include_bonus/minirt_bonus.h"

static int	supersample_first(int *color, int center, t_rss rss, t_wrap *w)
{
	t_rss	tmp;
	int		*subsquare;
	int		col; //

	subsquare = (int *)err_malloc(sizeof(int) * 4);
	subsquare[0] = color[0];
	subsquare[1] = calc_ray(1, rss, w);
	subsquare[2] = calc_ray(3, rss, w);
	subsquare[3] = center;
	tmp.limit = rss.limit - 1;
	tmp.x = rss.x * 2;
	tmp.y = rss.y * 2;
	tmp.xres = rss.xres * 2;
	tmp.yres = rss.yres * 2;
	col = supersample(subsquare, tmp, w);
	return (col);
}

static int	supersample_second(int *color, int center, t_rss rss, t_wrap *w)
{
	t_rss	tmp;
	int		*subsquare;
	int		col;

	subsquare = (int *)err_malloc(sizeof(int) * 4);
	subsquare[0] = calc_ray(1, rss, w);
	subsquare[1] = color[1];
	subsquare[2] = center;
	subsquare[3] = calc_ray(5, rss, w);
	tmp.limit = rss.limit - 1;
	tmp.x = rss.x * 2 + 1;
	tmp.y = rss.y * 2;
	tmp.xres = rss.xres * 2;
	tmp.yres = rss.yres * 2;
	col = supersample(subsquare, tmp, w);
	return (col);
}

static int	supersample_third(int *color, int center, t_rss rss, t_wrap *w)
{
	t_rss	tmp;
	int		*subsquare;
	int		col;

	subsquare = (int *)err_malloc(sizeof(int) * 4);
	subsquare[0] = calc_ray(3, rss, w);
	subsquare[1] = center;
	subsquare[2] = color[2];
	subsquare[3] = calc_ray(3, rss, w);
	tmp.limit = rss.limit - 1;
	tmp.x = rss.x * 2;
	tmp.y = rss.y * 2 + 1;
	tmp.xres = rss.xres * 2;
	tmp.yres = rss.yres * 2;
	col = supersample(subsquare, tmp, w);
	return (col);
}

static int	supersample_fourth(int *color, int center, t_rss rss, t_wrap *w)
{
	t_rss	tmp;
	int		*subsquare;
	int		col;

	subsquare = (int *)err_malloc(sizeof(int) * 4);
	subsquare[0] = center;
	subsquare[1] = calc_ray(5, rss, w);
	subsquare[2] = calc_ray(7, rss, w);
	subsquare[3] = color[3];
	tmp.limit = rss.limit - 1;
	tmp.x = rss.x * 2 + 1;
	tmp.y = rss.y * 2 + 1;
	tmp.xres = rss.xres * 2;
	tmp.yres = rss.yres * 2;
	col = supersample(subsquare, tmp, w);
	return (col);
}

int			supersample(int *color, t_rss rss, t_wrap *w)
{
	int	center;
	int	n;

	center = calc_ray(4, rss, w);
	n = 0;
	while (n < 4)
	{
		if (!color_difference(color[n], center) || rss.limit == 0)
			color[n] = average(color[n], center);
		else
		{
			if (n == 0)
				color[0] = supersample_first(color, center, rss, w);
			else if (n == 1)
				color[1] = supersample_second(color, center, rss, w);
			else if (n == 2)
				color[2] = supersample_third(color, center, rss, w);
			else if (n == 3)
				color[3] = supersample_fourth(color, center, rss, w);
		}
		n++;
	}
	return (average_supersampled_color(color));
}