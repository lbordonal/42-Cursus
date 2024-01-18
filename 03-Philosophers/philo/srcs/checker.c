/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 00:42:54 by lbordona          #+#    #+#             */
/*   Updated: 2024/01/18 01:21:21 by lbordona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	check_philo_dead(t_main *main)
{
	int	i;
	long long now;

	i = 0;
	now = get_time();
	while (i < main->num_philo)
	{
		pthread_mutex_lock(&main->philo[i].reaper);
		if ((now - main->philo[i].last_meal) > main->ttd)
		{
			print_philo_status(&main->philo[i], "died.");
			pthread_mutex_lock(&main->mutex);
			main->dead = 1;
			pthread_mutex_unlock(&main->mutex);
			pthread_mutex_unlock(&main->philo[i].reaper);
			return (1);
		}
		pthread_mutex_unlock(&main->philo[i].reaper);
		i++;
	}
	return (0);
}

int	check_philo_ate(t_main *main)
{
	if (main->num_of_times_eat == -1)
		return (0);
	pthread_mutex_lock(&main->mutex);
	if (main->all_ate == main->num_philo)
	{
		pthread_mutex_unlock(&main->mutex);
		return (1);
	}
	pthread_mutex_unlock(&main->mutex);
	return (0);
}

void	*checker(void *arg)
{
	t_main	*main;

	main = (t_main *)arg;
	while (1)
	{
		if (check_philo_dead(main))
			return (NULL);
		if (check_philo_ate(main))
			return (NULL);
	}
	return (NULL);
}



