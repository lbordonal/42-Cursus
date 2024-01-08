/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbordona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 17:22:39 by lbordona          #+#    #+#             */
/*   Updated: 2023/04/12 21:29:23 by lbordona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>

/* push_swap.c: */
void	ft_start_stacks(t_stack *stack, int len);
void	ft_fill_stack(int argc, char **argv, t_stack *stack);
void	check_errors_in_stack(t_stack *stack);
void	selection_sort(t_stack *stack);

/* utils.c: */
void	ft_is_all_digits(int ac, char **av);
int		out_of_limits(t_stack *stack);
int		duplicated_element(t_stack *stack);
int		stack_sorted_a(t_stack *stack);
int		stack_sorted_b(t_stack *stack);

/* errors.c: */
int		ft_check_limits(char **argv);
void	free_all(t_stack *stack);

/* operation_swap.c: */
void	sa(t_stack *stack);
void	sb(t_stack *stack);
void	ss(t_stack *stack);

/* operation_rotate.c: */
void	ra(t_stack *stack);
void	rb(t_stack *stack);
void	rr(t_stack *stack);

/* operation_push.c: */
void	pa(t_stack *stack);
void	pb(t_stack *stack);

/* operation_rerotate.c: */
void	rra(t_stack *stack);
void	rrb(t_stack *stack);
void	rrr(t_stack *stack);

/* sort_small.c: */
void	ft_sort_two(t_stack *stack);
void	ft_sort_three(t_stack *stack);
void	ft_sort_five(t_stack *stack);

/* sort_big.c: */
void	ft_crazy_sort(t_stack *stack);
void	ft_sort(t_stack *stack);

/* sort_utils_1.c: */
void	pa_ra_pa(t_stack *stack);
void	pa_pa_ra(t_stack *stack);
void	ft_transform(t_stack *stack, int *temp_stack);
void	fill_index(t_stack *stack);
void	find_top_bottom_mid(t_stack *stack);

/* sort_utils_2.c: */
void	pushback_to_a(t_stack *stack);
void	pushback_to_a_smarter(t_stack *stack, int pos);
void	ra_or_rra(t_stack *stack);
void	push_top_and_bottom_to_b(t_stack *stack);

#endif
