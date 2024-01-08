/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:39:53 by lbordona          #+#    #+#             */
/*   Updated: 2024/01/08 19:30:58 by lbordona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*routine(void *args)
{
	t_main	*main;
	int		i;

	main = (t_main *)args;
	i = main->n_thread;
	if (main->input.num_of_times_eat > 0)
	{
		while (main->input.num_of_times_eat > main->philo[i].num_of_times_ate
			&& main->philo_dead == 0)
			routine_execute(main, i);
	}
	else
	{
		while (main->philo_dead == 0)
		{
			if (routine_execute(main, i) == 0)
				break ;
		}
	}
	return (NULL);
}

int	routine_execute(t_main *main, int i)
{
	if (philo_eating(main, i) == 0)
		return (0);
	if (main->input.num_of_times_eat != main->philo[i].num_of_times_ate)
	{
		if (philo_sleeping(main, i) == 0)
			return (0);
		if (philo_thinking(main, i) == 0)
			return (0);
	}
	return (1);
}

void	*checker(void *args)
{
	t_main	*main;
	int		i;

	main = (t_main *)args;
	i = 0;
	if (main->input.num_of_times_eat > 0)
	{
		while (main->input.num_of_times_eat > main->philo[i].num_of_times_ate
			&& main->philo_dead == 0)
		{
			if (philo_dead(main, &i) == 1)
				break ;
		}
	}
	else
	{
		while (main->philo_dead == 0)
		{
			if (philo_dead(main, &i) == 1)
				break ;
		}
	}
	return (NULL);
}

int	print_philo(t_main *main, int id, char *color, char *status)
{
	long long	now;

	now = delta_time(main->t0);
	if (main->philo_dead == 1)
		return (0);
	pthread_mutex_lock(&main->write);
	if (main->philo_dead == 1)
	{
		pthread_mutex_unlock(&main->write);
		return (0);
	}
	else
		printf("[%s%-4lld ms]    [%d] %-30s%s\n", color, now, id,
			status, RESET);
	pthread_mutex_unlock(&main->write);
	return (1);
}
