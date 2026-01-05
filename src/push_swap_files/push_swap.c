/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasinda <anasinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 12:02:19 by anasinda          #+#    #+#             */
/*   Updated: 2026/01/05 23:16:20 by anasinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include "../../includes/push_swap_header_file.h"

int	ft_abs(int num)
{
	if (num < 0)
		num = num * -1;
	return (num);
}

int	ft_max_return(int mpa, int mpb)
{
	if (mpa > mpb)
		return (mpa);
	return (mpb);
}

void	ft_check_which_sort(int size_stack, t_arg **stack_a, t_arg **stack_b)
{
	if (size_stack == 2)
		ft_sort_two(stack_a);
	else if (size_stack == 3)
		ft_sort_three(stack_a);
	else if (size_stack > 3 && size_stack <= 5)
		ft_sort_five(size_stack, stack_a, stack_b);
	else if (size_stack > 5)
		ft_sort_bigger_numbers(size_stack, stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	int		size_stack;
	t_arg	*stack_a;
	t_arg	*stack_b;

	if (argc < 2)
		exit(0);
	stack_a = NULL;
	stack_b = NULL;
	size_stack = ft_arg_parser(argv, &stack_a);
	if (size_stack == -1)
		return ((ft_printf("Error \n")), (-1));
	ft_create_value_array(size_stack, &stack_a);
	ft_index_nodes(&stack_a);
	if (ft_check_if_sorted(size_stack, stack_a) != -1)
		return ((ft_free_args_nodes(NULL, &stack_a, 0)), (0));
	ft_check_which_sort(size_stack, &stack_a, &stack_b);
	return ((ft_free_args_nodes(NULL, &stack_a, 0)), (0));
}
