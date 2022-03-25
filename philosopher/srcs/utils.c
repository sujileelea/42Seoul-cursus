/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 09:21:31 by sujilee           #+#    #+#             */
/*   Updated: 2022/03/25 15:19:24 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	error_msg(char *msg)
{
	printf("ERROR : %s\n", msg);
	return (FALSE);
}

int	ft_atoi(char *input)
{
	long long	output;
	int			i;

	i = 0;
	output = 0;
	while (input[i] >= '0' && input[i] <= '9')
	{
		output = (output * 10) + (input[i] - '0');
		i++;
	}
	if (input[i] || output > 2147483647)
		return (FALSE);
	return ((int)output);
}

unsigned long	ft_gettimeofday(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((unsigned long)(time.tv_sec * 1000 + time.tv_usec / 1000));
}

void	ft_usleep(unsigned long input_time)
{
	unsigned long	target;
	
	target = input_time + ft_gettimeofday();
	while (target > ft_gettimeofday())
		usleep(200);
}

void	ft_free(t_info *info, t_philo *philo)
{
	int	i;
	
	i = -1;
	while (++i < info->num_of_philos)
		pthread_mutex_destroy(&info->fork[i]);
	pthread_mutex_destroy(&info->print);
	free(info->fork);
	free(philo);
}