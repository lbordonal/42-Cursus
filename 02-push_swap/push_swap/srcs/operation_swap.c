/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 22:18:20 by lbordona          #+#    #+#             */
/*   Updated: 2023/03/21 23:05:44 by lbordona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(t_stack *stack)
{
	int	temp;

	if (stack->len_a > 1)
	{
		temp = stack->stack_a[0];
		stack->stack_a[0] = stack->stack_a[1];
		stack->stack_a[1] = temp;
		ft_printf("%s\n", "sa");
	}
	return ;
}

void	sb(t_stack *stack)
{
	int	temp;

	if (stack->len_b > 1)
	{
		temp = stack->stack_b[0];
		stack->stack_b[0] = stack->stack_b[1];
		stack->stack_b[1] = temp;
		ft_printf("%s\n", "sb");
	}
	return ;
}

void	ss(t_stack *stack)
{
	sa(stack);
	sb(stack);
	ft_printf("%s\n", "ss");
}
