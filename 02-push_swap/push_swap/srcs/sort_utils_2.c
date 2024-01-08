/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 17:58:44 by lbordona          #+#    #+#             */
/*   Updated: 2023/04/12 21:22:31 by lbordona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pushback_to_a(t_stack *stack)
{
	while (stack->len_b > 0)
		pa(stack);
}

void	pushback_to_a_smarter(t_stack *stack, int pos)
{
	int	i;
	int	size;

	if ((stack_sorted_a(stack)) && (stack_sorted_b(stack)))
	{
		while (stack->len_b > 0)
			pa(stack);
		return ;
	}
	size = stack->len_b;
	i = 0;
	while (i < size && stack->len_b)
	{
		if ((stack->stack_b[0] & (1 << (pos + 1))) == 1)
			rb(stack);
		else
			pa(stack);
		i++;
	}
}

void	ra_or_rra(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack->stack_a[i] != 0)
		i++;
	if (stack->mid - i >= 0)
		ra(stack);
	else
		rra(stack);
}

void	push_top_and_bottom_to_b(t_stack *stack)
{
	int	*a;
	int	top;
	int	bottom;

	find_top_bottom_mid(stack);
	a = stack->stack_a;
	top = stack->top;
	bottom = stack->bottom;
	while (stack->len_a != 3)
	{
		if (a[0] == top || a[0] == bottom)
			pb(stack);
		else
		{
			if ((a[1] == top || a[1] == bottom)
				|| (a[2] == top || a[2] == bottom))
				ra(stack);
			else
				rra(stack);
		}
	}
}
