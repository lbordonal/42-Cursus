/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:43:10 by lbordona          #+#    #+#             */
/*   Updated: 2024/01/08 19:19:09 by lbordona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	start_philo(t_main *main, int i, int j)
{
	main->philo[i].id = i + 1;
	main->philo[i].num_of_times_ate = 0;
	main->philo[i].ttd = 0;
	main->philo[i].fork.left = i;
	main->philo[i].fork.right = j;
}

int	create_philos(t_main *main)
{
	int	i;
	int	j;

	main->philo = malloc(sizeof(t_philo) * (main->input.num_philo + 1));
	if (main->philo == NULL)
		return (0);
	i = 0;
	j = 1;
	while (j < main->input.num_philo)
	{
		start_philo(main, i, j);
		i++;
		j++;
	}
	j = 0;
	start_philo(main, i, j);
	return (1);
}
