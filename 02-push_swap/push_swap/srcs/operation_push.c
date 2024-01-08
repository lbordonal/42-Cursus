/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 23:25:01 by lbordona          #+#    #+#             */
/*   Updated: 2023/03/29 12:31:43 by lbordona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pa(t_stack *stack)
{
	int	i;

	if (stack->len_b <= 0)
		return ;
	i = stack->len_a;
	while (i >= 1)
	{
		ft_swap(&stack->stack_a[i], &stack->stack_a[i - 1]);
		i--;
	}
	stack->stack_a[0] = stack->stack_b[0];
	i = 0;
	while (i < stack->len_b - 1)
	{
		ft_swap(&stack->stack_b[i], &stack->stack_b[i + 1]);
		i++;
	}
	stack->len_a++;
	stack->len_b--;
	ft_printf("%s\n", "pa");
}

void	pb(t_stack *stack)
{
	int	i;

	if (stack->len_a <= 0)
		return ;
	i = stack->len_b;
	while (i >= 1)
	{
		ft_swap(&stack->stack_b[i], &stack->stack_b[i - 1]);
		i--;
	}
	stack->stack_b[0] = stack->stack_a[0];
	i = 0;
	while (i < stack->len_a - 1)
	{
		ft_swap(&stack->stack_a[i], &stack->stack_a[i + 1]);
		i++;
	}
	stack->len_a--;
	stack->len_b++;
	ft_printf("%s\n", "pb");
}
