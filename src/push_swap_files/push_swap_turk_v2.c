/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_turk_v2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasinda <anasinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 17:04:12 by anasinda          #+#    #+#             */
/*   Updated: 2026/01/04 19:48:19 by anasinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include "../../includes/ft_utilities.h"
#include "../../includes/push_swap_header_file.h"

int	ft_abs(int	num)
{
	if (num < 0)
		num = num * -1;
	return num;
}

int	ft_max_return(int	mpa, int mpb)
{
	if (mpa > mpb)
		return mpa;
	return mpb;
}
int	ft_choose_cheapest_moves(t_arg	**stack_b,	int	*cheap_move)
{
	t_arg	*temp_b;

	*cheap_move = INT_MAX;
	temp_b = *stack_b;

	while (temp_b)
	{
		if (temp_b->total_mp < *cheap_move)
		{
			*cheap_move = temp_b->total_mp;
			temp_b = *stack_b;
		}else
		temp_b = temp_b->next;
	}
	return *cheap_move;
}
int	ft_start_moves_p2(int *mpa,	int	*mpb,	t_arg	**stack_a,	t_arg	**stack_b)
{
	if (*mpa > 0 && *mpb > 0)
		return (*mpa)--, (*mpb)--, ft_rr(stack_a, stack_b, 3), -1;
	else if (*mpa < 0 && *mpb < 0)
		return (*mpa)++, (*mpb)++, ft_rrr(stack_a, stack_b, 3), +1;
	else if (*mpa > 0)
		return (*mpa)--, ft_ra_rb(stack_a, 1), -1;
	else if (*mpa < 0)
		return (*mpa)++, ft_rra_rrb(stack_a, 1), +1;
	else if (*mpb > 0)
		return (*mpb)--, ft_ra_rb(stack_b, 2), -1;
	else if (*mpb < 0)
		return (*mpb)++, ft_rra_rrb(stack_b, 2), +1;

	return (0);
}

void	ft_start_moves(t_arg	**stack_a,	t_arg	**stack_b,	int	cheap_move)
{
	t_arg	*temp_b;
	int	mpa;
	int	mpb;

	temp_b = *stack_b;
	while ((*stack_b)->total_mp != cheap_move)
		*stack_b = (*stack_b)->next;

	mpa = (*stack_b)->mpa;
	mpb = (*stack_b)->mpb;

	*stack_b = temp_b;
	while (mpa != 0 || mpb != 0)
		ft_start_moves_p2(&mpa, &mpb, stack_a, stack_b);

	if (mpa == 0 || mpb == 0)
		ft_pa_pb(stack_b, stack_a, 2);
}

void	ft_initialize_range_count(int	range,	t_arg	**stack_a,	t_arg	**stack_b)
{
	int	min;
	int	max;
	int	mid;
	int	push_count;

	min = 0;
	max = range;
	push_count = 0;
	while (ft_lstsize(*stack_a) > 3)
	{
		push_count = 0;
		while (push_count < range && ft_lstsize(*stack_a) > 3)
		{
			mid = (min + max) / 2;
			if ((*stack_a)->pos_sorted >= min && (*stack_a)->pos_sorted < max)
			{
				ft_pa_pb(stack_a, stack_b, 2);
				if ((*stack_b)->pos_sorted <= mid && *stack_b)
					ft_ra_rb(stack_b, 2);
				push_count++;
			}else
			ft_ra_rb(stack_a, 1);

		}
		min += range;
		max += range;
	}
}
int	ft_found_target_push(t_arg	**stack_a, t_arg **stack_b, int	*target_check)
{
	int	index;

	index = 0;
	while (index < ft_lstsize(*stack_a))
	{
		//printf("This si target %d this is stack_b pos %d \n", target_check[index], (*stack_b)->pos_sorted);
		if (target_check[index] > (*stack_b)->pos_sorted)
		{
			return target_check[index];
		}
		index++;
	}
	return (target_check[0]);
}

void	ft_find_target_push(int size_stack, t_arg	**stack_a, t_arg **stack_b)
{
	t_arg	*temp_b;
	int	*target_check;

	temp_b = *stack_b;
	target_check = ft_target_check(size_stack, stack_a);
	while (*stack_b)
	{
		(*stack_b)->target_node = ft_found_target_push(stack_a, stack_b, target_check);
		*stack_b = (*stack_b)->next;
	}
	*stack_b = temp_b;
}
int	*ft_target_check(int	size_stack,	t_arg	**stack_a)
{
	int	*ptr;
	int	index;
	t_arg	*temp_a;

	temp_a = *stack_a;
	size_stack = ft_lstsize(*stack_a);
	ptr = malloc(sizeof(int) * size_stack);
	if (!ptr)
	return NULL;

	index = -1;
	while (++index < size_stack)
	{
		ptr[index] = temp_a->pos_sorted;
		temp_a = temp_a->next;
	}

	ptr = ft_sort_value_array(ptr, size_stack);
	return (ptr);
}
void	ft_count_moves_p4(t_arg **stack_a,	t_arg	**stack_b)
{
	t_arg	*temp_b;
	(void)stack_a;

	temp_b = *stack_b;
	while (*stack_b)
	{
		if (((*stack_b)->mpa >= 0 && (*stack_b)->mpb >= 0) || ((*stack_b)->mpa < 0 && (*stack_b)->mpb < 0))
			(*stack_b)->total_mp = ft_max_return(ft_abs((*stack_b)->mpa), ft_abs((*stack_b)->mpb));
		else
			(*stack_b)->total_mp = ft_abs((*stack_b)->mpa + ft_abs((*stack_b)->mpb));
		*stack_b = (*stack_b)->next;
	}
	*stack_b = temp_b;
}

void	ft_count_moves_p3(t_arg **stack_a,	t_arg	**stack_b)
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

int	ft_count_moves_p2(t_arg **stacks, int size)
{
	int	move;

	move = (*stacks)->index;
	if (move <= size / 2)
		return move;
	else
		return (move - size);
}

// int	ft_count_moves_p2(t_arg **stacks, int size)
// {
// 	t_arg	*current;
// 	int		position;

// 	if (!stacks || !*stacks)
// 		return (0);

// 	current = *stacks;
// 	position = 0;

// 	while (current && current != *stacks)
// 	{
// 		position++;
// 		current = current->next;
// 	}

// 	if (position <= size / 2)
// 		return position;
// 	else
// 		return (position - size);
// }

void	ft_count_moves(t_arg	**stack_a,	t_arg	**stack_b)
{
	t_arg	*temp_a;
	t_arg	*temp_b;
	int	size_a;
	int	size_b;
	int	index;

	temp_b = *stack_b;
	temp_a = *stack_a;
	size_a = ft_lstsize(*stack_a);
	size_b = ft_lstsize(*stack_b);
	index = 0;
	while (index < size_a)
	{
		(*stack_a)->mpa = ft_count_moves_p2(stack_a, size_a);
		*stack_a = (*stack_a)->next;
		index++;
	}
	index = 0;
	*stack_a = temp_a;
	while (index < size_b)
	{
		(*stack_b)->mpb  = ft_count_moves_p2(stack_b, size_b);
		*stack_b = (*stack_b)->next;
		index++;
	}
	*stack_b = temp_b;
	ft_count_moves_p3(stack_a, stack_b);
	ft_count_moves_p4(stack_a,stack_b);
}
void	ft_final_rotation(t_arg	**stack_a, int	size)
{
	int	zero_index;
	int	index;
	t_arg	*temp_a;

	temp_a = *stack_a;
	zero_index = 0;
	index = 0;
	while (temp_a->pos_sorted != 0)
	{
		zero_index++;
		index++;
		temp_a = temp_a->next;
	}

	while (index > 0)
	{
		if (zero_index <= size / 2)
			ft_ra_rb(stack_a, 1);
		else
			ft_rra_rrb(stack_a, 1);
		index--;
	}
}

void	ft_sort_bigger_numbers(int	size_stack, t_arg	**stack_a,	t_arg	**stack_b)
{
	int	range;
	int	cheap_move;

	if (size_stack <= 100)
		range = 15;
	else
		range = 30;

	ft_initialize_range_count(range, stack_a, stack_b);
	ft_sort_three(stack_a);
		// 	printf("NEW SIZE OF A: %d \n", ft_index_nodes(stack_a));
		// printf("NEW SIZE OF B: %d \n", ft_index_nodes(stack_b));
		// ft_find_target_push(size_stack, stack_a, stack_b);
		// ft_count_moves(stack_a, stack_b);
		// ft_choose_cheapest_moves(stack_b, &cheap_move);
		// printf("THIS IS CHEAP_MOVE: %d \n", cheap_move);
		// ft_start_moves(stack_a, stack_b, cheap_move);
	while (*stack_b)
	{
		ft_index_nodes(stack_a);
		ft_index_nodes(stack_b);
		ft_find_target_push(size_stack, stack_a, stack_b);
		ft_count_moves(stack_a, stack_b);
		ft_choose_cheapest_moves(stack_b, &cheap_move);
		//printf("THIS IS CHEAP_MOVE: %d \n", cheap_move);
		ft_start_moves(stack_a, stack_b, cheap_move);
	}
	ft_index_nodes(stack_a);
	ft_final_rotation(stack_a, ft_lstsize(*stack_a));
	//printf("LAST SIZE OF A: %d \n", ft_index_nodes(stack_a));
}
