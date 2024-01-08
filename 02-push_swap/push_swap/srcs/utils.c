/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 22:10:50 by lbordona          #+#    #+#             */
/*   Updated: 2023/03/30 13:44:44 by lbordona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_is_all_digits(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j] != '\0')
		{
			if (ft_isdigitorsignal(av[i][j]) == 0)
			{
				ft_printf("%s\n", "Error");
				exit (0);
			}
			j++;
		}
		i++;
	}
}

int	out_of_limits(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->len_a)
	{
		if (stack->stack_a[i] > INT_MAX || stack->stack_a[i] < INT_MIN)
			return (1);
		i++;
	}
	return (0);
}

int	duplicated_element(t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	if (stack->len_a <= 1)
		return (0);
	while (i < stack->len_a)
	{
		j = i + 1;
		while (j < stack->len_a)
		{
			if (stack->stack_a[i] == stack->stack_a[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	stack_sorted_a(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->len_a - 1)
	{
		if (stack->stack_a[i] > stack->stack_a[i + 1])
			return (0);
		else
			i++;
	}
	return (1);
}

int	stack_sorted_b(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->len_b - 1)
	{
		if (stack->stack_b[i] > stack->stack_b[i + 1])
			return (0);
		else
			i++;
	}
	return (1);
}
