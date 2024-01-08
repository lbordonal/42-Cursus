/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 10:30:39 by lbordona          #+#    #+#             */
/*   Updated: 2023/12/05 11:41:59 by lbordona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	input_check(int ac, char **av)
{
	int	i;

	i = 0;
	if (ft_is_all_digits(ac, av) == 0)
		exit (0);
	if (ac < 5 || ac > 6)
	{
		printf("%s", "Please, verify the input → ./philo ");
		printf("%s", "[Number of philosophers] [Time to die] [Time to eat] ");
		printf("%s\n", "[Time to sleep] [Eat times]");
		return (0);
	}
	while (i < ac)
	{
		if (ft_atol(av[i]) > 2147483647 || ft_atol(av[i]) < 0)
		{
			printf("%s", "Please, verify the input → All parameters must be ");
			printf("%s\n", "greater than zero and lower than INT_MAX.");
			return (0);
		}
		i++;
	}
	return (1);
}

int	input_philos(int ac, char **av, t_main *main)
{
	if (ac == 5 || ac == 6)
	{
		main->input.num_philo = ft_atoi(av[1]);
		main->input.ttd = ft_atoi(av[2]);
		main->input.tte = ft_atoi(av[3]);
		main->input.tts = ft_atoi(av[4]);
		if (ac == 6)
			main->input.num_of_times_eat = ft_atoi(av[5]);
		else
			main->input.num_of_times_eat = -1;
		return (0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_main	main;

	if (input_check(ac, av) == 0)
		return (0);
	if (input_philos(ac, av, &main) == 0)
	{
		if (create_philos(&main) == 0)
			return (1);
		if (create_forks(&main) == 0)
			return (1);
		if (main.input.num_of_times_eat == 1)
		{
			if (lonely_philo(&main) == 0)
				return (1);
			return (0);
		}
		if (create_threads(&main) == 0)
			return (1);
		if (destroy_threads(&main) == 0)
			return (1);
		philo_free(&main);
		return (0);
	}
}

int	lonely_philo(t_main *main)
{
	if (pthread_mutex_init(&main->write, NULL) != 0)
		return (0);
	main->t0 = get_time();
	print_philo(main, 1, BLUE, "has taken a fork");
	exec_action(main->input.ttd);
	print_philo(main, 1, RED, "died");
	philo_free(main);
	return (1);
}
