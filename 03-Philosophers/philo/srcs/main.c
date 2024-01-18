/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 21:25:38 by lbordona          #+#    #+#             */
/*   Updated: 2024/01/18 01:16:14 by lbordona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	input_checker(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j] != '\0')
		{
			if (!ft_isdigit(av[i][j]))
			{
				printf("%s", "Please, verify the input → All parameters must be ");
				printf("%s\n", "numbers and equal or greater than zero.");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	input_philo(int ac, char **av, t_main *main)
{
	main->num_philo = ft_atoi(av[1]);
	main->ttd = ft_atoi(av[2]);
	main->tte = ft_atoi(av[3]);
	main->tts = ft_atoi(av[4]);
	if (ac == 6)
		main->num_of_times_eat = ft_atoi(av[5]);
	else
		main->num_of_times_eat = -1;
	main->all_ate = 0;
	main->dead = 0;
	main->t0 = get_time();
	pthread_mutex_init(&main->print, NULL);
	pthread_mutex_init(&main->mutex, NULL);
	if (main->num_philo == 0 || main->ttd == 0 || main->tte == 0 ||
		main->tts == 0 || main->num_of_times_eat == 0)
	{
		printf("%s", "Please, verify the input → ./philo ");
		printf("%s", "[Number of philosophers] [Time to die] [Time to eat] ");
		printf("%s\n", "[Time to sleep] [Eat times]");
		return (0);
	}
	if (!input_philo_continue(main))
		return (0);
	return (1);
}

int	input_philo_continue(t_main *main)
{
	//main->forks = start_forks(main->num_philo);
	if (!(main->forks = start_forks(main->num_philo)))
	{
		free(main->forks);
		return (0);
	}
	//main->philo = start_philos(main);
	if (!(main->philo = start_philos(main)))
	{
		free(main->philo);
		return (0);
	}
	return (1);
}

void	philo_free(t_main *main)
{
	free(main->philo);
	free(main->forks);
}

int	main(int ac, char **av)
{
	t_main	main;

	if (ac == 5 || ac == 6)
	{
		if (!input_checker(av))
			return (0);
		if (!input_philo(ac, av, &main))
			return (0);
		start_threads(&main);
		join_threads(&main);
		philo_free(&main);
	}
	else
	{
		printf("%s", "Please, verify the input → ./philo ");
		printf("%s", "[Number of philosophers] [Time to die] [Time to eat] ");
		printf("%s\n", "[Time to sleep] [Eat times]");
	}
	return (0);
}
