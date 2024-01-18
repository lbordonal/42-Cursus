/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 23:46:54 by lbordona          #+#    #+#             */
/*   Updated: 2024/01/18 01:12:49 by lbordona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	print_philo_status(t_philo *philo, char *status)
{
	long long	now;

	pthread_mutex_lock(&philo->main->mutex);
	if (philo->main->dead >= 1 || philo->main->all_ate == philo->main->num_philo)
	{
		pthread_mutex_unlock(&philo->main->mutex);
		return ;
	}
	pthread_mutex_unlock(&philo->main->mutex);
	now = delta_time(philo->main->t0);
	pthread_mutex_lock(&philo->main->print);
	printf("[%-4lld ms]    [%d] %s\n", now, philo->id, status);
	pthread_mutex_unlock(&philo->main->print);
	return ;
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->main->num_philo == 1)
	{
		pthread_mutex_lock(philo->l_fork);
		print_philo_status(philo, "has taken a fork.");
		pthread_mutex_unlock(philo->l_fork);
		return (NULL);
	}
	if (philo->id % 2 == 0)
		usleep(2000);
	while (philo->main->dead == 0)
	{
		if (grab_forks(philo))
			return (NULL);
		if (is_eating(philo))
			return (NULL);
		if (is_sleeping(philo))
			return (NULL);
		if (is_thinking(philo))
			return (NULL);
	}
	return (NULL);
}
