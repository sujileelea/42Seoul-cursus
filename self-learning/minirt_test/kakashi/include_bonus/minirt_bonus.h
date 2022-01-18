/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 16:22:57 by sujilee           #+#    #+#             */
/*   Updated: 2021/05/25 01:15:16 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <unistd.h> //write, read
# include <stdio.h> //printf
# include <stdlib.h> //malloc, free
# include <fcntl.h> //open? close?
#include <pthread.h> //보너스용. thread를 쓰기 위한 라이브러리. pthread_create, pthread_join

# include "mlx.h"
# include <math.h>

# include "figure.h"
# include "key_code.h"
# include "../utils/vec/vec3.h"

# include "get_next_line.h"
# include "../utils/libft/libft.h"

//fig.flag를 위한 상수들
# define SP 0 //구
# define PL 1 //평면
# define SQ 2 //정사각형
# define TR 3 //삼각형
# define CY 4 //원기둥
# define CU 5 //큐브
# define PY 6 //피라미드

# define WIN_SIZE_X 2560
# define WIN_SIZE_Y 1440

# define THREAD_NUM 4 //보너스용
# define EPSILON 0.00001 //아주 작은 수

typedef struct		s_v3
{
	t_p3			o; //시점벡터? 위치좌표를 가리키는 위치벡터
	t_p3			d; //방향벡터
}					t_v3;

typedef struct		s_fig
{
	int				flag; //번호로 어떤 도형인지 식별
	union u_fig		fig; //union으로 그때그때 도형 저장 ?
	int				color; //RGB 색
	t_p3			normal; //법선벡터 h = (x, y, z)처럼
	//여기서부턴 보너스
	int				specular; //보너스용. 정반사
	double			refl_idx; //보너스용. 반사율
	double			refr_idx; //보너스용. 굴절률
	int				texture; //보너스용. 질감 타입
	double			wavelength; //보너스용. 파장의 길이
	struct s_fig	*next;
}					t_fig;

typedef struct		s_light
{
	t_p3			o; //광원의 좌표를 가리키는 위치벡터
	double			br; //빛의 세기 [0.0, 1.0]
	int				color; //광선의 색
	struct s_light *next; //다음 노드
}					t_light;

typedef struct		s_cam
{
	int				idx; //카메라 인덱스
	t_p3			o; //카메라, 즉 시점의 좌표를 가리키는 위치벡터
	t_p3			nv; //카메라가 바라봐야 할 방향을 가리키는 벡터 : 어느쪽을 보고 있는지
	int				fov; //화각 [0, 180] : 얼마만큼의 각도로 (정면을) 보고 있는지
	void			*img_ptr; //mlx img_ptr(이미지 주소값). 카메라 별로 보고 있는 이미지가 다르니까
	int				*px_img; // 아래의 정보를 통해 구현할 픽셀이미지
	int				bits_per_pixel; //이미지의 한 픽셀에 필요한 바이트 수
	int				size_line; //이미지의 width(가로)표현에 필요한 바이트 수
	int				endian; //엔디안 정보
	struct s_cam	*next; //다음 카메라(노드)
}					t_cam;

typedef struct		s_scene
{
	int				res_init; //window 정보가 들어왔는지 체크해주는 flag 변수 ?
	int				xres; //해상도, x랜더링 사이즈 : x축 크기
	int				yres; //해상도, y랜더링 사이즈 : y축 크기
	int				cam_nb //카메라 개수
	t_light			*l; //광원 리스트(광원이 여러개 들어올 수 있뜨니까)
	int				al_init; //주변광이 들어왔는지 체크해주는 flag 변수 ?
	double			ambient_light; //주변광 밝기 정도 [0.0, 1.0]
	int				al_color; //주변광 al(ambient light)의 색
	int				bgr; //rgb, bgr 순서로 들어가서 이렇게 선언했대
}					t_scene;

typedef struct		s_mlx
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_cam			*cam;
	t_cam			*begin;
}					t_mlx;

typedef struct		s_wrap //wrap이라는 이름의 구조체 사용
{
	t_mlx			*mlx; //mlx 포인터
	t_scene			*data; //t_scene 포인터
	t_fig			*lst; //figures 포인터
	int				thread_id; //보너스용.
	int				x; //x축
	int				y; //y축
}					t_wrap;

typedef struct		 s_rss
{
	int				limit;
	int				xres;
	int				yres;
	int				x;
	int				y;
}					t_rss;

typedef struct		s_inter
{
	int				color;
	int				ref_color; //보너스용. 
	t_p3			normal;
	t_p3			p;
}					t_inter;

typedef struct		s_sq_info
{
	t_p3			half_size;
	t_p3			floor;
	t_p3			center_to_ip;
}					t_sq_info;

typedef struct		s_cube //보너스용. cube를 위한 구조체
{
	t_fig			sq; //정사각형 구조체
	t_p3			center; //정육면체의 중심점
	t_p3			normal[6]; //정육면체의 각 면에 대한 법선벡터
}					t_cube;

typedef struct		s_pyr //보너스용. 
{
	t_fig			sq; //아랫면인 사각형
	t_fig			tr;//4면을 이루는 삼각형
	t_p3			vertex_point; //피라미드의 꼭대기
	t_p3			normal[5]; //각 면에 대한 법선벡터
	t_p3			corner[4];
}					t_pry;

typedef struct		s_bmp_header
{
	char			type[2];
	unsigned int	size;
	unsigned int	reserved;
	unsigned int	offset;
}					t_bmphead;

typedef struct		s_dib_header
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
}					t_dibhead;

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
void			save_args2(t_fig **lst, char *str); //보너스용. 
void			parse_resolution(t_scene *data, char *str);
void			parse_ambient(t_scene *data, char *str);
void			parse_camera(t_mlx *mlx, t_scene *data, char *str);
void			parse_light(t_scene **data, char *str);
void			parse_cylinder(t_fig **elem, char *str);
void			parse_sphere(t_fig **elem, char *str);
void			parse_square(t_fig **elem, char *str);
void			parse_plane(t_fig **elem, char *str);
void			parse_triangle(t_fig **elem, char *str);
void			parse_cube(t_fig **elem, char *str); //보너스용. 
void			parse_pyramid(t_fig **elem, char *str); //보너스용. 

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
**			thread.c //보너스용. 
*/
void			multithreading(t_wrap *wrapper); //보너스용. 
void			wrap_data(t_mlx mlx, t_scene data, t_fig *lst, t_wrap *wrapper);

/*
**			sample_pixel.c
*/
int				*sample_pixel(int *edge_color, int last[2],
											t_rss rss, t_wrap *w);

/*
**			ray_tracing.c
*/
int				trace_ray(t_p3 o, t_p3 d, t_wrap *w, int depth);
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
**			compound_inter.c //보너스용. 
*/
double			cube_inter(t_p3 o, t_p3 d, t_fig *lst); //보너스용. 
double			pyramid_inter(t_p3 o, t_p3 d, t_fig *lst); //보너스용. 

/*
**			light_calc.c
*/
t_p3			reflect_ray(t_p3 ray, t_p3 normal); //보너스용. 
double			calc_specular(t_v3 ray, t_inter *inter,
							t_scene data, t_fig *lst); //보너스용. 
void			add_coefficient(double (*rgb)[3], double coef, int color);
int				is_light(t_p3 o, t_p3 d, t_fig *lst);
void			compute_light(t_v3 ray, t_inter *inter,
							t_scene data, t_fig *lst);

/*
**			color_calc.c
*/
int				color_x_light(int color, double rgb[3]);
int				cproduct(int color, double coef); //보너스용. 
int				cadd(int color_a, int color_b); //보너스용. 
int				color_difference(int color, int color2); //보너스용. 

/*
**			supersample.c
*/
int				supersample(int *color, t_rss rss, t_wrap *w); //보너스용. 
int				average(int color1, int color2); //보너스용. 
int				average_supersampled_color(int *color);

/*
**			texture.c //보너스용. 
*/
void			apply_texture(int texture, t_inter *inter, t_fig *lst); //보너스용

/*
**			mlx_func.c
*/
void			init_mlx(t_mlx *mlx, t_scene *data);
void			start_mlx(t_mlx mlx, t_scene data);
int				close_red_button();
int				key_press(int keycode, t_mlx *mlx);
#endif