/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multithread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 11:25:39 by sujilee           #+#    #+#             */
/*   Updated: 2021/05/13 13:28:14 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/minirt_bonus"

//쓰레드 생성 시 전해줄 함수. ? 쓰레드 생성시에 사용되는 함수는 다른곳에서 쓰이지 않으면
//미사용 함수로 처리돼서 static 함수로 같은 파일안에 묶어놔줘야함
static void	*render_thread(void *ptr)
{
	t_wrap	*w;

	w = (t_wrap *)ptr;
	//render_thread 함수에서 전체 카메라를 돌며 함수를 호출해서 값을 채워줌
	while (w->mlx.cam)
	{
		render_scene(w); //srcs/minirt.c
		w->mlx.cam = w->mlx.cam->next;
	}
	return (NULL);
}

?
int		pthread_create(pthread_t *th_id, const pthread_attr_t *attr, void *함수,
void *arg);
//th_id : pthread 식별자 thread가 성공적으로 생성되면 thread 식별값이 주어짐
//attr : pthread 옵션. 기본 옵션을 쓸 떼는 NULL 전달
//함수 : pthread에서 사용할 함수. 반환값과 매개변수가 void* 이어야함
//		ex) void	*func(void *arg){};
//arg : 3번째 인자인 함수에 넘겨줄 매개변수. void형으로 넘겨준 후 내부에서 원래 자료형으로 캐스팅해 사용

int		pthread_join(pthread_t th_id, void **thread_return);
//th_id : join시켜줄 pthread id
//thread_return : pthread의 리턴값, 포인트로 받아오니 잘 넣을것
?

//쓰레드 만들기
//매개변수에 상수를 넣어주는 것은 명시적인 이유 ?
//상수가 있는 경우 매개변수의 사이즈를 알려주는 또다른 매개변수를 굳이 받을 필요가 없음
//그래서 더 편하고 간결하지롱
void	multithreading(t_wrap *wrapper)
{
	pthread_t	threads[THREAD_NUM];
	int			i;

	i = 0;
	while (i < THREAD_NUM)
	{
		pthread_create(&threads[i], NULL, render_thread, &wrapper[i]);
		i++;
	}
	i = 0;
	while (i < THREAD_NUM)
		pthread_join(threads[i++], NULL);
}

//멀티쓰레딩을 하기 위해 우선 같은 정보들을 가진 변수를 선언(mlx, data, lst)
//데이터x쓰레드 개수만큼 복사해서
//wrapper라는 이름의 변수에 모두 저장
void	wrap_data(t_mlx *mlx, t_scene data, t_fig *lst, t_wrap *wrapper)
{
	int	i;

	i = 0;
	while (i < THREAD_NUM)
	{
		wrapper[i].mlx = mlx;
		wrapper[i].data = data;
		wrapper[i].lst = lst;
		wrapper[i].thread_id = i; //thread index ?
		i++;
	}
}