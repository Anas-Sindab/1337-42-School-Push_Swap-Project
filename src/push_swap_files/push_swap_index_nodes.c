/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_index_nodes.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasinda <anasinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 00:56:07 by anasinda          #+#    #+#             */
/*   Updated: 2026/01/04 19:41:08 by anasinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include "../../includes/ft_utilities.h"
#include "../../includes/push_swap_header_file.h"

int	ft_check_if_sorted(int	size_stack, t_arg	*stack_a)
{
	int	i;

	i = 0;
	while (i < size_stack)
	{
		if (stack_a->pos_sorted != i)
			return (-1);
		else
			stack_a = stack_a->next;
		i++;
	}
	return (1);
}
void	ft_create_value_array(int size_stack, t_arg **stack_a)
{
	int	i;
	int	*sorted_stack_array;
	t_arg *temp_stack;

	sorted_stack_array = malloc(sizeof(int) * size_stack);
	if (!sorted_stack_array)
		return	;

	i = 0;
	temp_stack = *stack_a;
	while (i < size_stack)
	{
		sorted_stack_array[i] = temp_stack->value;
		temp_stack = temp_stack->next;
		i++;
	}
	sorted_stack_array = ft_sort_value_array(sorted_stack_array, size_stack);
	ft_index_nodes_sorted(size_stack, sorted_stack_array, stack_a);
	free(sorted_stack_array);
}
int	*ft_sort_value_array(int *sorted_stack_array, int size_stack)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size_stack)
	{
		j = i + 1;
		while (j < size_stack)
		{
			if(sorted_stack_array[i] > sorted_stack_array[j])
			{
				temp = sorted_stack_array[i];
				sorted_stack_array[i] = sorted_stack_array[j];
				sorted_stack_array[j] = temp;
			}
			j++;
		}
		i++;
	}
	return (sorted_stack_array);
}

void	ft_index_nodes_sorted(int size_stack, int	*sorted_stack_array, t_arg **stack_a)
{
	int	index;
	t_arg	*temp_stack;

	index = 0;
	temp_stack = *stack_a;
	while (index < size_stack)
	{
		if (sorted_stack_array[index] == (*stack_a)->value)
		{
			(*stack_a)->pos_sorted = index;
			(*stack_a) = temp_stack;
			index++;
		}else
			(*stack_a) = (*stack_a)->next;
	}
	
	// temp_stack = *stack_a;
	// while (temp_stack)
	// {
	// 	printf("This is position value %d \n", (temp_stack)->value);
	// 	temp_stack = (temp_stack)->next;
	// }

	// temp_stack = *stack_a;

	// while (temp_stack)
	// {
	// 	printf("This is position position %d \n", (temp_stack)->pos_sorted);
	// 	temp_stack = (temp_stack)->next;
	// }
}

int	ft_index_nodes(t_arg **stacks)
{
	int	index;
	t_arg	*temp_stack;

	temp_stack = *stacks;
	// while (*stacks)
	// {
	// 	printf("THIS IS VALUE BITCH AT STACK A: %d \n", (*stacks)->value);
	// 	*stacks = (*stacks)->next;
	// }
	index = 0;
	while(*stacks)
	{
			(*stacks)->index = index;
			*stacks = (*stacks)->next;
			index++;
	}
	*stacks = temp_stack;
	return (index);
}
