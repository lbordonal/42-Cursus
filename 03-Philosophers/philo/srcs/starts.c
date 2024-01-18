/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   starts.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 22:17:02 by lbordona          #+#    #+#             */
/*   Updated: 2024/01/18 01:04:57 by lbordona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

pthread_mutex_t	*start_forks(int num_philo)
{
	int				i;
	pthread_mutex_t	*forks;

	i = 0;
	forks = malloc(sizeof(pthread_mutex_t) * num_philo);
	if (!forks)
		return (NULL);
	while (i < num_philo)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
	return (forks);
}

t_philo	*start_philos(t_main *main)
{
	int		i;
	t_philo	*philo;

	i = 0;
	philo = malloc(sizeof(t_philo) * main->num_philo);
	if (!philo)
		return (NULL);
	while (i < main->num_philo)
	{
		philo[i].id = i + 1;
		philo[i].last_meal = get_time();
		philo[i].num_of_times_ate = 0;
		philo[i].l_fork = &main->forks[i];
		if (main->num_philo != 1)
			philo[i].r_fork = &main->forks[(i + 1) % main->num_philo];
		philo[i].main = main;
		pthread_mutex_init(&philo[i].reaper, NULL);
		i++;
	}
	return (philo);
}

void	start_threads(t_main *main)
{
	int	i;

	i = 0;
	while (i < main->num_philo)
	{
		if (pthread_create(&main->philo[i].thread, NULL,
				&routine, &main->philo[i]) != 0)
			printf("%s\n", "Error creating thread for philo");
		usleep(1000);
		i++;
	}
	if (pthread_create(&main->checker, NULL, &checker, main) != 0)
		printf("%s\n", "Error creating thread for checker");
}
