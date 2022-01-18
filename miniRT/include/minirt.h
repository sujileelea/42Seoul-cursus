/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 14:37:04 by sujilee           #+#    #+#             */
/*   Updated: 2021/05/31 14:48:54 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "mlx.h"
# include <math.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "../utils/libft/libft.h"
# include "get_next_line.h"
# include "../utils/vec/vec3.h"
# include "figures.h"
# include "key_code.h"

# define SP 0
# define PL 1
# define SQ 2
# define TR 3
# define CY 4
# define CU 5
# define PY 6

# define WIN_SIZE_X 2560
# define WIN_SIZE_Y 1440

# define EPSILON 0.00001

typedef	struct	s_v3
{
	t_p3	o;
	t_p3	d;
}				t_v3;

typedef struct	s_fig
{
	int				flag;
	union u_fig		fig;
	int				color;
	t_p3			normal;
	struct s_fig	*next;
}				t_fig;

typedef struct	s_light
{
	t_p3			o;
	double			br;
	int				color;
	struct s_light	*next;
}				t_light;

typedef struct	s_cam
{
	int				idx;
	t_p3			o;
	t_p3			nv;
	int				fov;
	void			*img_ptr;
	int				*px_img;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	struct s_cam	*next;
}				t_cam;

typedef struct	s_scene
{
	int		res_init;
	int		xres;
	int		yres;
	int		cam_nb;
	t_light	*l;
	int		al_init;
	double	ambient_light;
	int		al_color;
	int		bgr;
}				t_scene;

typedef struct	s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_cam	*cam;
	t_cam	*begin;
}				t_mlx;

typedef struct	s_wrap
{
	t_mlx	mlx;
	t_scene	data;
	t_fig	*lst;
	int		x;
	int		y;
}				t_wrap;

typedef struct	s_rss
{
	int	limit;
	int	xres;
	int	yres;
	int	x;
	int	y;
}				t_rss;

typedef struct	s_inter
{
	int		color;
	t_p3	normal;
	t_p3	p;
}				t_inter;

typedef struct	s_sq_info
{
	t_p3	half_size;
	t_p3	floor;
	t_p3	center_to_ip;
}				t_sq_info;

typedef struct	s_bmp_header
{
	char			type[2];
	unsigned int	size;
	unsigned int	reserved;
	unsigned int	offset;
}				t_bmphead;

typedef struct	s_dib_header
{
	unsigned int	size;
	int				width;
	int				height;
	unsigned short	colplanes;
	unsigned short	bpp;
	unsigned int	compression;
	unsigned int	img_size;
	int				x_ppm;
	int				y_ppm;
	unsigned int	color_number;
	unsigned int	important_color;
}				t_dibhead;

/*
**			minirt.c
*/
int				calc_pixel_color(int *edge_color, int last[2], t_wrap *w);
void			render_scene(t_wrap *w);
int				main(int ac, char **av);

/*
**			camera_calc.c
*/
int				calc_ray(int n, t_rss rss, t_wrap *w);

/*
**			make_bmpfile.c && make_bmpfile_utils.c
*/
void			make_bmp(t_mlx mlx, t_scene data, char *name);
int				get_file_name(char *name);
int				get_sub_len(char *name);

/*
**			parse1.c && parse2.c && parse3.c && parse4.c
*/
void			parse(t_mlx *mlx, t_scene *data, t_fig **lst, char **av);
void			parsing(t_mlx *mlx, t_scene *data, t_fig **lst, char *str);
void			save_args(t_mlx *mlx, t_scene *data, t_fig **lst, char *str);
void			parse_resolution(t_scene *data, char *str);
void			parse_ambient(t_scene *data, char *str);
void			parse_camera(t_mlx *mlx, t_scene *data, char *str);
void			parse_light(t_scene **data, char *str);
void			parse_cylinder(t_fig **elem, char *str);
void			parse_sphere(t_fig **elem, char *str);
void			parse_square(t_fig **elem, char *str);
void			parse_plane(t_fig **elem, char *str);
void			parse_triangle(t_fig **elem, char *str);

/*
**			parse_utils1.c && parse_utils2.c
*/
void			comma(char **str);
int				parse_color(char **str);
t_p3			parse_p3(char **str);
void			ft_addnewlst_back(t_fig **alst);
void			skip_space(char **str);
int				rt_atoi(char **str);
double			rt_atof(char **str);

/*
**			error_checking.c
*/
void			*err_malloc(unsigned int n);
void			error_check(int n, char *error_message);
void			check_values(double n, double min, double max, char *err);
void			success_message(int ac);

/*
**			sample_pixel.c
*/
int				*sample_pixel(int *edge_color, int last[2],
											t_rss rss, t_wrap *w);

/*
**			ray_tracing.c
*/
int				trace_ray(t_p3 o, t_p3 d, t_wrap *w);
void			try_all_inter(t_v3 ray, t_fig *lst,
				t_fig *close_fig, double *close_inter);
void			calc_normal(t_inter *inter, t_p3 d, t_fig *lst);
t_p3			refract_ray(t_p3 d, t_p3 normal, t_fig *lst);

/*
**			sphere.c
*/
double			sphere_inter(t_p3 o, t_p3 d, t_fig *lst);

/*
**			pl_sq_tr.c
*/
double			plane_inter(t_p3 o, t_p3 d, t_p3 plane_p, t_p3 plane_nv);
double			triangle_inter(t_p3 o, t_p3 d, t_fig *lst);
double			square_inter(t_p3 o, t_p3 d, t_fig *lst);

/*
**			cylinder.c
*/
double			cylinder_inter(t_p3 o, t_p3 d, t_fig *lst);

/*
**			light_calc.c
*/
void			add_coefficient(double (*rgb)[3], double coef, int color);
int				is_light(t_p3 o, t_p3 d, t_fig *lst);
void			compute_light(t_v3 ray, t_inter *inter,
							t_scene data, t_fig *lst);

/*
**			color_calc.c
*/
int				color_x_light(int color, double rgb[3]);
int				average_supersampled_color(int *color);

/*
**			mlx_func.c
*/
void			init_mlx(t_mlx *mlx, t_scene *data);
void			start_mlx(t_mlx mlx, t_scene data);
int				close_red_button();
int				key_press(int keycode, t_mlx *mlx);
#endif
