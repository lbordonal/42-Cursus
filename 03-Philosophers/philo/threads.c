/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:57:27 by lbordona          #+#    #+#             */
/*   Updated: 2023/12/05 15:39:30 by lbordona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	create_threads(t_main *main)
{
	int	i;

	i = 0;
	main->philo_dead = 0;
	main->t0 = get_time();
	if (pthread_mutex_init(&main->write, NULL) != 0)
		return (0);
	while (i < main->input.num_philo)
	{
		main->n_thread = i;
		if (pthread_create(&main->philo[i].thread, NULL,
				&routine, (void *) main) != 0)
			return (0);
		i++;
		usleep(1000);
	}
	if (pthread_create(&main->orchestrator, NULL, &checker, (void *) main) != 0)
		return (0);
	usleep(1000);
	if (join_threads(main) == 0)
		return (0);
	return (1);
}

int	join_threads(t_main *main)
{
	int	i;

	i = 0;
	while (i < main->input.num_philo)
	{
		if (pthread_join(main->philo[i].thread, NULL) != 0)
			return (0);
		i++;
	}
	if (pthread_join(main->orchestrator, NULL) != 0)
		return (0);
	return (1);
}

int	destroy_threads(t_main *main)
{
	int	i;

	i = 0;
	while (i < main->input.num_philo)
	{
		pthread_mutex_destroy(&main->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&main->write);
	return (1);
}
