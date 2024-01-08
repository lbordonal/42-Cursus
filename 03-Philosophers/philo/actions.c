/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 18:39:24 by lbordona          #+#    #+#             */
/*   Updated: 2024/01/08 19:30:37 by lbordona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	philo_eating(t_main *main, int i)
{
	if (pthread_mutex_lock(&main->forks[main->philo[i].fork.left]) != 0)
		return (0);
	if (print_philo(main, main->philo[i].id, BLUE, "has taken a fork") == 0)
		return (0);
	if (pthread_mutex_lock(&main->forks[main->philo[i].fork.right]) != 0)
		return (0);
	if (print_philo(main, main->philo[i].id, BLUE, "has taken a fork") == 0)
		return (0);
	if (print_philo(main, main->philo[i].id, GREEN, "is eating") == 0)
		return (0);
	main->philo[i].ttd = get_time ();
	exec_action(main->input.tte);
	drop_forks(main, i);
	return (1);
}

int	philo_sleeping(t_main *main, int i)
{
	if (print_philo(main, main->philo[i].id, PINK, "is sleeping") == 0)
		return (0);
	exec_action(main->input.tts);
	return (1);
}

int	philo_thinking(t_main *main, int i)
{
	if (print_philo(main, main->philo[i].id, G_CYAN, "is thinking") == 0)
		return (0);
	return (1);
}

int	philo_dead(t_main *main, int *i)
{
	int	time;

	if (*i == main->input.num_philo)
		*i = 0;
	time = delta_time(main->philo[*i].ttd);
	if (time > main->input.ttd)
	{
		print_philo(main, main->philo[*i].id, RED, "died");
		main->philo_dead = 1;
		return (1);
	}
	i++;
	return (0);
}

int	drop_forks(t_main *main, int i)
{
	if (pthread_mutex_unlock(&main->forks[main->philo[i].fork.left]))
		return (0);
	if (pthread_mutex_unlock(&main->forks[main->philo[i].fork.right]))
		return (0);
	main->philo[i].num_of_times_ate++;
	return (1);
}
