/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 12:43:37 by lbordona          #+#    #+#             */
/*   Updated: 2023/04/12 21:27:25 by lbordona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sort_two(t_stack *stack)
{
	if (stack->stack_a[0] > stack->stack_a[1])
		sa(stack);
}

void	ft_sort_three(t_stack *stack)
{
	int	*a;

	a = stack->stack_a;
	if (stack_sorted_a(stack) == 0)
	{
		if ((a[0] > a[1]) && (a[1] < a[2]) && (a[2] > a[0]))
			sa(stack);
		else if ((a[0] > a[1]) && (a[1] < a[2]) && (a[2] < a[0]))
			ra(stack);
		else if ((a[0] < a[1]) && (a[1] > a[2]) && (a[2] < a[0]))
			rra(stack);
		else if ((a[0] > a[1]) && (a[1] > a[2]) && (a[2] < a[0]))
		{
			sa(stack);
			rra(stack);
		}
		else if ((a[0] < a[1]) && (a[1] > a[2]) && (a[2] > a[0]))
		{
			sa(stack);
			ra(stack);
		}
	}
}

void	ft_sort_five(t_stack *stack)
{
	push_top_and_bottom_to_b(stack);
	ft_sort_three(stack);
	if (stack->stack_b[0] > stack->stack_b[1])
		pa_ra_pa(stack);
	else
		pa_pa_ra(stack);
}
