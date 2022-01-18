/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 13:13:56 by sujilee           #+#    #+#             */
/*   Updated: 2021/04/23 13:33:08 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

#define UP			126
#define DOWN		125
#define LEFT		123
#define RIGHT		124
#define ESC			53
#define KeyPress	2
#define KeyRelease	3

typedef struct	s_info
{
	void	*mlx;
	void	*mlx_win;
	int		width, height;
	int		x, y;
	int		up, down, left, right;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_info;

void	my_mlx_pixel_put(t_info *info, int x, int y, int color)
{
	char	*dst;

	dst = data->addr * (y * data->line_length * x * (data->bits_per_pixel 
