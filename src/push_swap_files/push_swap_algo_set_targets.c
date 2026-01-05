/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_header_file.hwap_algo_set_targets.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasinda <anasinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 23:58:59 by anasinda          #+#    #+#             */
/*   Updated: 2026/01/05 07:02:42 by anasinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include "../../includes/helper_functions.h"
#include "../../includes/push_swap_header_file.h"

int	ft_found_target_push(t_arg **stack_a, t_arg **stack_b, int *target_check)
{
	int	index;
	int	size_a;

	index = 0;
	size_a = ft_lstsize(*stack_a);
	while (index < size_a)
	{
		if (target_check[index] > (*stack_b)->pos_sorted)
		{
			return (target_check[index]);
		}
		index++;
	}
	return (target_check[0]);
}

void	ft_find_target_push(int size_stack, t_arg **stack_a, t_arg **stack_b)
{
	t_arg	*temp_b;
	int		*target_check;

	temp_b = *stack_b;
	target_check = ft_target_check(size_stack, stack_a);
	while (*stack_b)
	{
		(*stack_b)->target_node = ft_found_target_push(stack_a, stack_b,
				target_check);
		*stack_b = (*stack_b)->next;
	}
	free(target_check);
	*stack_b = temp_b;
}

int	*ft_target_check(int size_stack, t_arg **stack_a)
{
	int		*ptr;
	int		index;
	t_arg	*temp_a;

	temp_a = *stack_a;
	size_stack = ft_lstsize(*stack_a);
	ptr = malloc(sizeof(int) * size_stack);
	if (!ptr)
		return (NULL);
	index = -1;
	while (++index < size_stack)
	{
		ptr[index] = temp_a->pos_sorted;
		temp_a = temp_a->next;
	}
	ptr = ft_sort_value_array(ptr, size_stack);
	return (ptr);
}
