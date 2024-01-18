/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 00:14:33 by lbordona          #+#    #+#             */
/*   Updated: 2024/01/18 01:18:32 by lbordona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	grab_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->main->mutex);
	if (philo->main->dead >= 1 || philo->main->all_ate == philo->main->num_philo)
	{
		pthread_mutex_unlock(&philo->main->mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->main->mutex);
	if (philo->id % 2)
	{
		pthread_mutex_lock(philo->r_fork);
		print_philo_status(philo, "has taken a fork.");
		pthread_mutex_lock(philo->l_fork);
		print_philo_status(philo, "has taken a fork.");
	}
	else
	{
		pthread_mutex_lock(philo->l_fork);
		print_philo_status(philo, "has taken a fork.");
		pthread_mutex_lock(philo->r_fork);
		print_philo_status(philo, "has taken a fork.");
	}
	return (0);
}

int	is_eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->main->mutex);
	if (philo->main->dead >= 1 || philo->main->all_ate == philo->main->num_philo)
	{
		pthread_mutex_unlock(&philo->main->mutex);
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
		return (1);
	}
	pthread_mutex_unlock(&philo->main->mutex);
	pthread_mutex_lock(&philo->reaper);
	philo->last_meal = get_time();
	print_philo_status(philo, "is eating.");
	pthread_mutex_lock(&philo->main->mutex);
	philo->num_of_times_ate++;
	if (philo->main->num_of_times_eat != -1)
	{
		if (philo->main->num_of_times_eat == philo->num_of_times_ate)
			philo->main->all_ate++;
	}
	pthread_mutex_unlock(&philo->main->mutex);
	pthread_mutex_unlock(&philo->reaper);
	exec_action(philo->main->tte);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
	return (0);
}

int	is_sleeping(t_philo *philo)
{
	pthread_mutex_lock(&philo->main->mutex);
	if (philo->main->dead >= 1 || philo->main->all_ate == philo->main->num_philo)
	{
		pthread_mutex_unlock(&philo->main->mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->main->mutex);
	print_philo_status(philo, "is sleeping.");
	exec_action(philo->main->tts);
	return (0);
}

int	is_thinking(t_philo *philo)
{
	pthread_mutex_lock(&philo->main->mutex);
	if (philo->main->dead >= 1 || philo->main->all_ate == philo->main->num_philo)
	{
		pthread_mutex_unlock(&philo->main->mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->main->mutex);
	print_philo_status(philo, "is thinking.");
	return (0);
}
