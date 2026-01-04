/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasinda <anasinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 18:02:41 by anasinda          #+#    #+#             */
/*   Updated: 2026/01/04 19:59:46 by anasinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include "../../includes/push_swap_header_file.h"

void	ft_check_which_sort(int	size_stack,	t_arg	**stack_a,	t_arg	**stack_b)
{
	if (size_stack == 2)
		ft_sort_two(stack_a);
	else if (size_stack == 3)
		ft_sort_three(stack_a);
	else if (size_stack > 3 && size_stack <= 5)
		ft_sort_five(size_stack, stack_a, stack_b);
	else if (size_stack > 5)
		ft_sort_bigger_numbers(size_stack,	stack_a,	stack_b);
}

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		int	size_stack;
		t_arg *stack_a;
		t_arg *stack_b;

		stack_a = NULL;
		stack_b = NULL;

		if ((size_stack = ft_arg_parser(argv, &stack_a)) == -1)
			return (ft_printf("Error \n")), (-1);
		else if (size_stack <= 1)
			return (ft_free_args_nodes(NULL, &stack_a, 0)), (0);

		ft_create_value_array(size_stack, &stack_a);
		ft_index_nodes(&stack_a);

		if (ft_check_if_sorted(size_stack, stack_a) != -1)
			exit(0);

		ft_check_which_sort(size_stack, &stack_a, &stack_b);

		// while (stack_b)
		// {
		// 	printf("IN B: value: %d index: %d sorted: %d target_in_a: %d moves_mpa %d moves_mpb: %d tottal_mp: %d \n\n", stack_b->value, stack_b->index, stack_b->pos_sorted, stack_b->target_node, stack_b->mpa, stack_b->mpb, stack_b->total_mp);
		// 	stack_b = stack_b->next;
		// }
		// while (stack_a)
		// {
		// 	printf("IN A: value: %d index: %d sorted: %d target_in_a: %d moves_mpa %d moves_mpb: %d \n\n", stack_a->value, stack_a->index, stack_a->pos_sorted, stack_a->target_node, stack_a->mpa, stack_a->mpb);
		// 	stack_a = stack_a->next;
		// }

	}
}
