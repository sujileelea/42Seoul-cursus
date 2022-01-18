/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 18:18:51 by sujilee           #+#    #+#             */
/*   Updated: 2021/05/26 17:12:33 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/minirt_bonus.h"

//보너스용.
void	save_args2(t_fig **lst, char *str)
{
	if (*str == 'p' && *(str + 1) == 'y' && *(str++) && *(str++))
		parse_pyramid(lst, str);
	else if (*str == 't' && *(str + 1) == 'r' && *(str++) && *(str++))
		parse_triangle(lst, str);	
}

void	save_args(t_mlx *mlx, t_scene *data, t_fig **lst, char *str)
{
	if (*str == 'R')
		parse_resolution(data, ++str);
	else if (*str == 'A')
		parse_ambient(data, ++str);
	else if (*str == 'c' && (*(str + 1) == 32 || *(str + 1) == 9))
		parse_camera(mlx, data, ++str);
	else if (*str == 'l' && (*(str + 1) == 32 || *(str + 1) == 9))
		parse_light(&data, ++str);
	else if (*str == 'p' && *(str + 1) == 'l' && *(str++) && *(str++))
		parse_plane(lst, str);
	else if (*str == 's' && *(str + 1) == 'p' && *(str++) && *(str++))
		parse_sphere(lst, str);	
	else if (*str == 's' && *(str + 1) == 'q' && *(str++) && *(str++))
		parse_square(lst, str);
	else if (*str == 'c' && *(str + 1) == 'y' && *(str++) && *(str++))
		parse_cylinder(lst, str);
	else if (*str == 'c' && *(str + 1) == 'u' && *(str++) && *(str++))
		parse_cube(lst, str);
	save_args2(lst, str);
}

//#이면 주석, 문자열이 비어있으면 return해서 다음 줄을 받아오게 함
void	parsing(t_mlx *mlx, t_scene *data, t_fig **lst, char *str)
{
	if (*str == '#' || *str == 0)
		return ;
	else
		save_args(mlx, data, lst, str);
}

//srcs/minirt.c 의 메인에 있는 파싱 시작 함수
void	parse(t_mlx *mlx, t_scene *data, t_fig **lst, char **av)
{
	char	*str;
	int		fd;

	//도형, 빛, 카메라 노드를 모두 NULL로 초기화
	//resolution과 ambient_light의 기본 변수도 0으로 초기화(정보 없음 상태)
	*lst = NULL;
	data->l = NULL;
	mlx->cam = NULL; //while문 돌릴때 널가드
	data->res_init = 0;
	data->al_init = 0;
	if ((fd = open(av[1], 0)) == -1) //rt파일 경로를 따라가 잘못 열렸을 시 -1반환
		error_check(7, "Cannot open rt file");
	//gnl을 사용해 rt파일의 한 줄씩 전달
	while (get_next_line(fd, &str)
	{
		parsing(mlx, data, lst, str);
		free(str);
	}
	//모든 파싱이 끝나고 정보가 제대로 전달되지 않았을 경우 에러 처리
	if (data->res_init == 0 || data->al_init == 0 || mlx->cam == NULL)
		error_check(4, "Not enough elements in .rt file to render a scene");
	free(str);
	close(fd);
}