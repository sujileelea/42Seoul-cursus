/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 09:14:53 by sujilee           #+#    #+#             */
/*   Updated: 2022/03/24 11:47:22 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	handle_print(t_info *info, t_philo *philo, int action)
{
	unsigned long	now;

	pthread_mutex_lock(&info->print);
	now = ft_gettimeofday() - info->start;
	if (info->all_alive == TRUE && action == FORK)
		printf("%lums : %dth philo has taken a fork\n", now, philo->num);
	else if (info->all_alive == TRUE && action == EAT)
		printf("%lums : %dth philo is eating\n", now, philo->num);
	else if (info->all_alive == TRUE && action == SLEEP)
		printf("%lums : %dth philo is sleeping\n", now, philo->num);
	else if (info->all_alive == TRUE && action == THINK)
		printf("%lums : %dth philo is thinking\n", now, philo->num);
	else if (action == DIE && info->check_die == TRUE)
	{
		printf("%lums : %dth philo died\n", now, philo->num);
		info->check_die = FALSE;
	}
	pthread_mutex_unlock(&info->print);	
}

void	handle_action(t_info *info, t_philo *philo, int right_fork, int left_fork)
{
	if ((philo->num % 2 == 1 && pthread_mutex_lock(&info->fork[right_fork]) == 0)
		|| pthread_mutex_lock(&info->fork[left_fork]) == 0)
		handle_print(info, philo, FORK);
	//만약 홀수번째 철학자이고 왼쪽 포크 뮤텍스 락이 잘 걸린상태 || 오른쪽 포크 뮤텍스 락이 걸려있다면
	if ((philo->num % 2 == 1 && pthread_mutex_lock(&info->fork[left_fork]) == 0)
		|| pthread_mutex_lock(&info->fork[right_fork]) == 0)
		handle_print(info, philo, FORK);
	//홀수번째 철학자가 양쪽 포크를 모두 잡았을 경우(뮤텍스 락으로 포크 접근 요청을 성공했을 경우)
	handle_print(info, philo, EAT);
	philo->eat = ft_gettimeofday();
	ft_usleep(info->time_to_eat);
	pthread_mutex_unlock(&info->fork[right_fork]);
	pthread_mutex_unlock(&info->fork[left_fork]);
	philo->eat_num++;
	if (philo->info->num_of_must_eat == philo->eat_num)
		return ;
	handle_print(info, philo, SLEEP);
	ft_usleep(info->time_to_sleep);
	handle_print(info, philo, THINK);
}


void	*handle_state(void *arg)
{
	t_philo	*philo;
	t_info	*info;
	int		i;

	philo = (t_philo *)arg;
	info = (t_info *)philo->info;
	while (1)
	{
		i = -1;
		while (++i < info->num_of_philos)
		{
			if (philo[i].eat_num == info->num_of_must_eat)
				return (NULL);
			//철학자가 한계보다 굶어버리면
			if (ft_gettimeofday() - philo[i].eat > info->time_to_die)
			{
				info->all_alive = FALSE;
				// ???
				if (i == 0)
					pthread_mutex_unlock(&info->fork[philo[i].right_fork]);
				handle_print(info, &philo[i], DIE);
				return (NULL);
			}
		}
		usleep(20);
	}
}

void	*handle_loop(void *arg)
{
	t_philo	*philo;
	t_info	*info;

	philo = (t_philo *)arg;
	info = (t_info *)philo->info;
	//짝수번째 철학자라면 
	if (philo->num % 2 == 0)
		ft_usleep(info->time_to_eat - 1);
	while (1)
	{
		//만약 누군가라도 죽으면 루프 중료
		if (info->all_alive == FALSE)
			break ;
		//루프가 돌동안 handle_action 함수 호출
		handle_action(info, philo, philo->right_fork, philo->left_fork);
		
		//필요 식사 횟수를 달성했다면 루프 종료
		if (info->num_of_must_eat == philo->eat_num)
			break ;
	}
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_info	info;
	t_philo	*philo;

	if (argc !=5 && argc !=6)
		return (error_msg("wrong input argument number!\n"));
	if (init_info(argc, argv, &info) == FALSE)
		return (error_msg("Invalid number!\n"));
	if (init_philo(&info, &philo) == FALSE)
		return (error_msg("Failed malloc\n"));
	init_table(&info, philo);
	ft_free(&info, philo);
	return (0);
}