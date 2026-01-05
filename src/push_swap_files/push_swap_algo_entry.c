/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algo_entry.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasinda <anasinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 12:03:53 by anasinda          #+#    #+#             */
/*   Updated: 2026/01/05 16:33:37 by anasinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include "../../includes/helper_functions.h"
#include "../../includes/push_swap_header_file.h"

void	ft_initialize_range_count(int size_a, int range, t_arg **stack_a,
		t_arg **stack_b)
{
	int (min), (mid), (max), (push_count);
	min = 0;
	max = range;
	push_count = 0;
	while (size_a > 3)
	{
		push_count = 0;
		while (push_count < range && size_a > 3)
		{
			mid = (min + max) / 2;
			if ((*stack_a)->pos_sorted >= min && (*stack_a)->pos_sorted < max)
			{
				ft_pa_pb(stack_a, stack_b, 2);
				if ((*stack_b)->pos_sorted <= mid && *stack_b)
					ft_ra_rb(stack_b, 2);
				size_a--;
				push_count++;
			}
			else
				ft_ra_rb(stack_a, 1);
		}
		min += range;
		max += range;
	}
}

void	ft_final_rotation(t_arg **stack_a, int size)
{
	int		zero_index;
	int		index;
	t_arg	*temp_a;

	temp_a = *stack_a;
	zero_index = 0;
	index = 0;
	while (temp_a->pos_sorted != 0)
	{
		zero_index++;
		temp_a = temp_a->next;
	}
	if (zero_index > size / 2)
		zero_index = zero_index - size;
	while (zero_index != 0)
	{
		if (zero_index > 0)
			((ft_ra_rb(stack_a, 1)), (zero_index--));
		else
			((ft_rra_rrb(stack_a, 1)), (zero_index++));
	}
}

void	ft_sort_bigger_numbers(int size_stack, t_arg **stack_a, t_arg **stack_b)
{
	int	range;
	int	cheap_move;

	if (size_stack <= 100)
		range = 40;
	else
		range = 60;
	ft_initialize_range_count(ft_lstsize(*stack_a), range, stack_a, stack_b);
	ft_sort_three(stack_a);
	while (*stack_b)
	{
		ft_index_nodes(stack_a);
		ft_index_nodes(stack_b);
		ft_find_target_push(size_stack, stack_a, stack_b);
		ft_count_moves(stack_a, stack_b);
		ft_choose_cheapest_moves(stack_b, &cheap_move);
		ft_start_moves(stack_a, stack_b, cheap_move);
	}
	ft_final_rotation(stack_a, ft_index_nodes(stack_a));
}
