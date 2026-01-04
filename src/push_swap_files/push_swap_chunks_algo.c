// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   push_swap_chunks_algo.c                            :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: anasinda <anasinda@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2026/01/01 10:36:54 by anasinda          #+#    #+#             */
// /*   Updated: 2026/01/01 21:22:29 by anasinda         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "../../includes/ft_printf.h"
// #include "../../includes/ft_utilities.h"
// #include "../../includes/push_swap_header_file.h"

// int	ft_find_smallest(int	chunk_start,	int	chunk_end, int	smallest, t_arg	**stack_a)
// {
// 	int	smallest;
// 	t_arg	*temp_a;

// 	temp_a = *stack_a;
// 	while (*stack_a)
// 	{
// 		if ((*stack_a)->index >= chunk_start && (*stack_a)->index <= chunk_end)
// 		{
// 			if ((*stack_a)->mpa < smallest)
// 				smallest = (*stack_a)->mpa;
// 		}
// 		*stack_a = (*stack_a)->next;
// 	}
// 	*stack_a = temp_a;
// 	return (smallest);
// }

// void	ft_find_cost(t_arg	**stack_a,	int	size_satck)
// {
// 	t_arg	*temp_a;

// 	temp_a = *stack_a;
// 	while (temp_a)
// 	{
// 		if (temp_a->index <= size_satck / 2)
// 			temp_a->mpa = temp_a->index;
// 		else if (temp_a->index > size_satck / 2)
// 			temp_a->mpa = temp_a->index - size_satck;
// 		temp_a = temp_a->next;
// 	}
// }
// void	ft_push_to_b(){}

// // void	ft_move_chunks_to_b(int	*chunk_start,	int	*chunk_end, t_arg	**stack_a,	t_arg	**stack_b)
// // {
// // 	int	sign;
// // 	int	size_a;
// // 	int	i;
// // 	int	smallest;
// // 	t_arg	*temp_a;
// // 	t_arg	*temp_b;

// // 	sign = 0;
// // 	i = *chunk_start;
// // 	temp_a = *stack_a;
// // 	temp_b = *stack_b;
// // 	size_a = ft_index_nodes(stack_a);
// // 	while (i < *chunk_end)
// // 	{
// // 		smallest = ft_find_smallest(*chunk_start, *chunk_start, &sign, stack_a)
// // 		if (sign == 1)
// // 		{
// // 			ft_push_to_b(size_a, );
// // 		}
// // 	}
// // }
// // if ((*stack_a)->index >= *chunk_start && (*stack_a)->index <= *chunk_end)
// // {
// // 	if ()

// void	ft_push_to_b_check(t_arg	**stack_a, t_arg	**stack_b,	int	chunk_mid)
// {
// 	if (!(*stack_b))
// 		ft_pa_pb(stack_a, stack_b, 1);
// 	else if ((*stack_a)->index <= chunk_mid)
// 	{
// 		ft_pa_pb(stack_a, stack_b, 1);
// 		ft_ra_rb(stack_b, 2);
// 	}else if ((*stack_a)->index > chunk_mid)
// 	{
// 		ft_pa_pb(stack_a, stack_b, 1);
// 		ft_rra_rrb(stack_b, 2);
// 	}
// }

// void	ft_chunk_algo_start(int	size_stack, t_arg	**stack_a, t_arg	**stack_b)
// {
// 	int	index;
// 	int	smallest;
// 	int	size_a;
// 	t_arg	*temp_a;
// 	(void)stack_b;

// 	(*stack_a)->chunk_size = size_stack / 2;
// 	temp_a = *stack_a;

// 	(*stack_a)->chunk_min = 0;
// 	(*stack_a)->chunk_max = (*stack_a)->chunk_min + (*stack_a)->chunk_size;
// 	(*stack_a)->chunk_mid = (*stack_a)->chunk_max / 2;
// 	index = 0;
// 	while (index < size_stack)
// 	{
// 		size_a = ft_index_nodes(stack_a);
// 		ft_find_cost(stack_a, size_stack);
// 		while ((*stack_a)->chunk_min < (*stack_a)->chunk_max)
// 		{

// 		}
// 	}

// 	printf("This is stack_a size: %d \n", size_stack);
// 	while (*stack_a)
// 	{
// 		printf("This is stack_a index: %d \n", (*stack_a)->index);
// 		printf("This is stack_a pos_sorted: %d \n", (*stack_a)->pos_sorted);
// 		printf("This is stack_a value: %d \n", (*stack_a)->value);
// 		printf("This is stack_a mpa: %d \n", (*stack_a)->mpa);
// 		*stack_a = (*stack_a)->next;
// 	}
// 	*stack_a = temp_a;
// }
