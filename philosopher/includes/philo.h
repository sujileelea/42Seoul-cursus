/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 09:06:02 by sujilee           #+#    #+#             */
/*   Updated: 2022/03/25 15:19:32 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <sys/time.h>

#define TRUE	0
#define FALSE	-1
#define FORK	1
#define	EAT		2
#define SLEEP	3
#define THINK	4
#define DIE		5

typedef struct s_info
{
	int				num_of_philos;
	unsigned long	time_to_die;
	unsigned long	time_to_eat;
	unsigned long	time_to_sleep;
	int				num_of_must_eat;
	unsigned long	start;   //프로그램 시작 시간
	int				all_alive;
	int				check_die;
	pthread_mutex_t	print;
	pthread_mutex_t	*fork;
}				t_info;

// 철학자 한명 한명에게 부여되는 구조체
typedef struct s_philo
{
	int				num;
	unsigned long	eat;		//식사를 시작한 시간
	int				eat_num;
	int				left_fork;
	int				right_fork;
	pthread_t		thread;
	t_info			*info;
}				t_philo;

/* ************************************************************************** */
/*                                  init.c                                    */
/* ************************************************************************** */

int				init_info(int argc, char **argv, t_info *info);
int				init_philo(t_info *info, t_philo **philo);
void			init_table(t_info *info, t_philo *philo);

/* ************************************************************************** */
/*                                  philo.c                                   */
/* ************************************************************************** */

void			handle_print(t_info *info, t_philo *philo, int action);
void			handle_action(t_info *info, t_philo *philo, int r_fork, int l_fork);
void			*handle_state(void *arg);
void			*handle_loop(void *arg);
int				main(int argc, char **argv);

/* ************************************************************************** */
/*                                  utils.c                                   */
/* ************************************************************************** */

int				error_msg(char *msg);
int				ft_atoi(char *input);
unsigned long	ft_gettimeofday(void);
void			ft_usleep(unsigned long input_time);
void			ft_free(t_info *info, t_philo *philo);

#endif
