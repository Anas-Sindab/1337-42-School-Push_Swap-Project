/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_header_file.hwap_algo_count_moves.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasinda <anasinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 23:35:47 by anasinda          #+#    #+#             */
/*   Updated: 2026/01/05 07:02:42 by anasinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include "../../includes/helper_functions.h"
#include "../../includes/push_swap_header_file.h"

void	ft_calc_total_mp(t_arg **stack_a, t_arg **stack_b)
{
	t_arg	*temp_b;

	(void)stack_a;
	temp_b = *stack_b;
	while (*stack_b)
	{
		if (((*stack_b)->mpa >= 0 && (*stack_b)->mpb >= 0)
			|| ((*stack_b)->mpa < 0 && (*stack_b)->mpb < 0))
			(*stack_b)->total_mp = ft_max_return(ft_abs((*stack_b)->mpa),
					ft_abs((*stack_b)->mpb));
		else
			(*stack_b)->total_mp = ft_abs((*stack_b)->mpa)
				+ ft_abs((*stack_b)->mpb);
		*stack_b = (*stack_b)->next;
	}
	*stack_b = temp_b;
}

void	ft_set_mpa_for_stack_b(t_arg **stack_a, t_arg **stack_b)
{
	t_arg	*temp_a;
	t_arg	*temp_b;

	temp_a = *stack_a;
	temp_b = *stack_b;
	while (*stack_b)
	{
		while ((*stack_b)->target_node != (*stack_a)->pos_sorted)
			*stack_a = (*stack_a)->next;
		(*stack_b)->mpa = (*stack_a)->mpa;
		*stack_a = temp_a;
		*stack_b = (*stack_b)->next;
	}
	*stack_b = temp_b;
}

int	ft_lower_half_upper_half_check(t_arg **stacks, int size)
{
	int	move;

	move = (*stacks)->index;
	if (move <= size / 2)
		return (move);
	else
		return (move - size);
}

void	ft_count_moves(t_arg **stack_a, t_arg **stack_b)
{
	t_arg *(temp_a), *(temp_b);
	int (size_a), (size_b), (index);
	temp_b = *stack_b;
	temp_a = *stack_a;
	size_a = ft_lstsize(*stack_a);
	size_b = ft_lstsize(*stack_b);
	index = -1;
	while (++index < size_a)
	{
		(*stack_a)->mpa = ft_lower_half_upper_half_check(stack_a, size_a);
		*stack_a = (*stack_a)->next;
	}
	index = -1;
	*stack_a = temp_a;
	while (++index < size_b)
	{
		(*stack_b)->mpb = ft_lower_half_upper_half_check(stack_b, size_b);
		*stack_b = (*stack_b)->next;
	}
	*stack_b = temp_b;
	ft_set_mpa_for_stack_b(stack_a, stack_b);
	ft_calc_total_mp(stack_a, stack_b);
}
