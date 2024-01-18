/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 21:23:47 by lbordona          #+#    #+#             */
/*   Updated: 2024/01/18 01:03:02 by lbordona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <pthread.h>
#include <sys/time.h>

typedef struct s_main
{
	int				num_philo;
	int				ttd;
	int				tte;
	int				tts;
	int				num_of_times_eat;
	int				all_ate;
	int				dead;
	long long		t0;
	struct s_philo	*philo;
	pthread_mutex_t	mutex;
	pthread_mutex_t	print;
	pthread_mutex_t	*forks;
	pthread_t		checker;
}		t_main;

typedef struct s_philo
{
	int				id;
	int				num_of_times_ate;
	long long		last_meal;
	pthread_t		thread;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	reaper;
	t_main			*main;
}		t_philo;

/* main.c: */
int				input_checker(char **av);
int				input_philo(int ac, char **av, t_main *main);
int				input_philo_continue(t_main *main);
void			philo_free(t_main *main);

/* libft_functions.c: */
int				ft_isdigit(int c);
int				ft_atoi(char *str);

/* starts.c: */
pthread_mutex_t	*start_forks(int num_philo);
t_philo			*start_philos(t_main *main);
void			start_threads(t_main *main);

/* threads.c: */
void			join_threads(t_main *main);

/* time.c: */
long long		get_time(void);
long long		delta_time(long long time);
void			exec_action(long long time);

/* routine.c: */
void			print_philo_status(t_philo *philo, char *status);
void			*routine(void *arg);

/* actions.c: */
int				grab_forks(t_philo *philo);
int				is_eating(t_philo *philo);
int				is_sleeping(t_philo *philo);
int				is_thinking(t_philo *philo);

/* checker.c: */
int				check_philo_dead(t_main *main);
int				check_philo_ate(t_main *main);
void			*checker(void *arg);

#endif
