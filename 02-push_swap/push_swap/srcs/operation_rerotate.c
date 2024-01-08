/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rerotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 12:31:07 by lbordona          #+#    #+#             */
/*   Updated: 2023/03/29 12:40:24 by lbordona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rra(t_stack *stack)
{
	int	i;
	int	temp;

	i = stack->len_a - 1;
	temp = stack->stack_a[i];
	while (i > 0)
	{
		stack->stack_a[i] = stack->stack_a[i - 1];
		i--;
	}
	stack->stack_a[0] = temp;
	ft_printf("%s\n", "rra");
}

void	rrb(t_stack *stack)
{
	int	i;
	int	temp;

	i = stack->len_b - 1;
	temp = stack->stack_b[i];
	while (i > 0)
	{
		stack->stack_b[i] = stack->stack_b[i - 1];
		i--;
	}
	stack->stack_b[0] = temp;
	ft_printf("%s\n", "rrb");
}

void	rrr(t_stack *stack)
{
	rra(stack);
	rrb(stack);
	ft_printf("%s\n", "rrr");
}
