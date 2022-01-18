/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 18:42:55 by sujilee           #+#    #+#             */
/*   Updated: 2021/05/26 17:12:33 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

int		calc_pixel_color(int *edge_color, int last[2], t_wrap *w)
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
	//if문은 보너스용.
	if (color_difference(color[0], color[3])
			|| color_difference(color[1], color[2]))
		return (supersample(color, rss, w));
	return (average_supersampled_color(color));
}

void	render_scene(t_wrap *w)
{
	int		edge_color[w->data.xres + 2]; //픽셀의 겹치는 모서리의 색(하나로 묶은거)
	int		last[2];
	int		color;
	int		n;

	n = w->data.yres / THREAD_NUM; //y를 쓰레드 개수로 나눠줌
	w->y = n * w->thread_id; //나눈 수에 현재 쓰레드 넘버를 곱해서 현재 처리해야 할 범위 지정
	while (w->y < (n * (w->thread_id + 1)))//현재 쓰레드의 시작부터 다음 쓰레드의 이전 값까지 돌림
	{
		w->x = 0;
		while (w->x < w->data->xres)
		{
			//color라는 int형 변수에 현재 픽셀의 값을 계산해서 저장한 후 배열에 넣어줌
			color = calc_pixel_color(edge_color, lst, w);
			w->mlx.cam->px_img[w->y * w->data.xres + w->x] = color;
			w->x++;
		}
		if (w->thread_id == THREAD_NUM - 1)
			//진행률 표시. 모든 쓰레드는 동시진행이기 때문에 마지막 쓰레드에서만 해줌
			printf("\rRendering scene (cam %d/%d) [%d%%]", 
				w->mlx.cam->idx, w->data.cam_nb, 100 * (w->y % n) / n);
		w->y++;
	}
	if (w->thread_id == THREAD_NUM - 1)
		//랜더링 완료
		printf("\rRendering scene (cam %d/%d) [100%%]\n",
			w->mlx.cam->idx, w->data.cam_nb);
	return ;
}

int		main(int ac, char *av[])
{
	t_mlx	mlx;
	t_scene	data;
	t_fig	*lst;
	t_wrap	w;

	//에러 처리 해줘용(인자 개수에 따라)

	if (ac < 2 || ac > 3) //인자 개수가 2나 3이 아니면 에러
		error_check(1, "");
	//2번째 인자가 .rt 파일이 아닐 경우 (obj파일이 뭐시여)
	if (ac == 2 && ft_strncmp(av[1] + ft_strlen(av[1]) - 3, ".rt", 3))
		error_check(2, "");
	//3번째 인자가 --save 옵션이 아닐 경우 
	if (ac == 3 && ft_strncmp(av[2], "--save", 6))
		error_check(3, "");
	parse(&mlx, &data, &lst, av) //파싱 시작 함수 -> srcs/parse.c
	init_mlx(&mlx, &data); //srcs/mlx_function.c
	wrap_data(mlx, data, lst, wrapper); //srcs/multithread.c
	multithreading(wrapper)); //srcs/multithread.c
	if (ac == 3)
		make_bmp(mlx, data, av[1]); //srcs/make_bmp.c
	success_message(ac);
	start_mlx(mlx, data); //srcs/mlx_funtion.c
	return (0);
}