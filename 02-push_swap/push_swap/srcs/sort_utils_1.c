/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 12:56:16 by lbordona          #+#    #+#             */
/*   Updated: 2023/04/12 20:54:49 by lbordona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pa_ra_pa(t_stack *stack)
{
	pa(stack);
	ra(stack);
	pa(stack);
}

void	pa_pa_ra(t_stack *stack)
{
	pa(stack);
	pa(stack);
	ra(stack);
}

void	ft_transform(t_stack *stack, int *temp)
{
	int	i;
	int	j;

	i = 0;
	while (i < stack->len_a)
	{
		j = 0;
		while (j < stack->len_a)
		{
			if (stack->stack_a[i] == temp[j])
			{
				stack->stack_a[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
}

void	fill_index(t_stack *stack)
{
	int	i;
	int	*aux;
	int	temp;

	i = 0;
	aux = ft_calloc(stack->len_a, sizeof(int));
	if (!aux)
		return ;
	aux = ft_memcpy(aux, stack->stack_a, sizeof(int) * stack->len_a);
	while (i < stack->len_a - 1)
	{
		if (aux[i] > aux[i + 1])
		{
			temp = aux[i];
			aux[i] = aux[i + 1];
			aux[i + 1] = temp;
			i = 0;
		}
		else
			i++;
	}
	ft_transform(stack, aux);
	free(aux);
}

void	find_top_bottom_mid(t_stack *stack)
{
	int	i;
	int	len;

	i = 0;
	len = stack->len_a - 1;
	fill_index(stack);
	while (stack->stack_a[i] != 0)
		i++;
	stack->top = stack->stack_a[i];
	i = 0;
	while (stack->stack_a[i] != len)
		i++;
	stack->bottom = stack->stack_a[i];
	if (len % 2 == 0)
		stack->mid = len / 2;
	else if (len % 2 != 0)
		stack->mid = (len + 1) / 2;
}
