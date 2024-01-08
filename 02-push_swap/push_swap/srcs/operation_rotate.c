/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 23:04:48 by lbordona          #+#    #+#             */
/*   Updated: 2023/03/21 23:25:41 by lbordona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(t_stack *stack)
{
	int	i;
	int	len;
	int	temp;

	i = 0;
	len = stack->len_a - 1;
	temp = stack->stack_a[0];
	while (i < len)
	{
		stack->stack_a[i] = stack->stack_a[i + 1];
		i++;
	}
	stack->stack_a[len] = temp;
	ft_printf("%s\n", "ra");
}

void	rb(t_stack *stack)
{
	int	i;
	int	len;
	int	temp;

	i = 0;
	len = stack->len_b - 1;
	temp = stack->stack_b[0];
	while (i < len)
	{
		stack->stack_b[i] = stack->stack_b[i + 1];
		i++;
	}
	stack->stack_b[len] = temp;
	ft_printf("%s\n", "rb");
}

void	rr(t_stack *stack)
{
	ra(stack);
	rb(stack);
	ft_printf("%s\n", "rr");
}
