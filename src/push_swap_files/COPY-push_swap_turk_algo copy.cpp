/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   COPY-push_swap_turk_algo copy.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasinda <anasinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 23:38:46 by anasinda          #+#    #+#             */
/*   Updated: 2026/01/01 21:41:40 by anasinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include "../../includes/ft_utilities.h"
#include "../../includes/push_swap_header_file.h"


void	ft_sort_small(int size_stack, t_arg	**stack_a)
{
	if (size_stack == 2)
	{
		if ((*stack_a)->pos_sorted > (*stack_a)->next->pos_sorted)
		ft_ra_rb(stack_a, 1);
	}else if (size_stack >= 3)
	{
		if (((*stack_a)->next->pos_sorted > (*stack_a)->next->next->pos_sorted) && ((*stack_a)->next->next->pos_sorted > (*stack_a)->pos_sorted) )
		{
			ft_rra_rrb(stack_a, 1);
			ft_sa_sb(stack_a, 1);
		}else if (((*stack_a)->next->next->pos_sorted > (*stack_a)->pos_sorted) && ((*stack_a)->pos_sorted > (*stack_a)->next->pos_sorted))
		{
			ft_sa_sb(stack_a ,1);
		}
		else if (((*stack_a)->next->pos_sorted > (*stack_a)->pos_sorted) && ((*stack_a)->pos_sorted > (*stack_a)->next->next->pos_sorted))
		{
			ft_rra_rrb(stack_a, 1);
		}
		else if (((*stack_a)->pos_sorted > (*stack_a)->next->next->pos_sorted) && ((*stack_a)->next->next->pos_sorted > (*stack_a)->next->pos_sorted))
		{
			ft_ra_rb(stack_a, 1);
		}
		else if (((*stack_a)->pos_sorted > (*stack_a)->next->pos_sorted) && ((*stack_a)->next->pos_sorted > (*stack_a)->next->next->pos_sorted))
		{
			ft_ra_rb(stack_a, 1);
			ft_sa_sb(stack_a, 1);
		}
	}
}
int	ft_check_target_node(t_arg	*stack_a, int	num)
{
	int	small_temp;
	int	smallest;
	t_arg	*temp_a;

	temp_a = stack_a;
	small_temp = stack_a->value;

	while (temp_a)
	{
		if (temp_a->value < small_temp)
			small_temp = temp_a->value;
		temp_a = temp_a->next;
	}

	smallest = small_temp;
	temp_a = stack_a;
	while(stack_a)
	{
		if (stack_a && smallest > num)
		{
			if (smallest > stack_a->value && stack_a->value > num)
			smallest = stack_a->value;

		}else if (stack_a && smallest < num)
			smallest = stack_a->value;
		stack_a = stack_a->next;
	}
	if (num > smallest)
		return small_temp;
	return smallest;
}
void	ft_calculate_moves(int	size_a, int	size_b, t_arg **stack_a, t_arg **stack_b)
{
	t_arg	*temp_a;
	t_arg	*temp_b;

	temp_a = *stack_a;
	temp_b = *stack_b;

	while (*stack_b)
	{
		if ((*stack_b)->index <= (size_b / 2))
			(*stack_b)->mpb = (*stack_b)->index;
		else
			(*stack_b)->mpb = (*stack_b)->index - size_b;
		*stack_b = (*stack_b)->next;
	}

	*stack_b = temp_b;

	while (*stack_b)
	{
		if ((*stack_b)->target_node == (*stack_a)->value)
		{
			if ((*stack_a)->index <= (size_a /2))
				(*stack_b)->mpa = (*stack_a)->index;
			else
				(*stack_b)->mpa = (*stack_a)->index - size_a;
			*stack_a = temp_a;
			*stack_b = (*stack_b)->next;
		}else
			*stack_a = (*stack_a)->next;
	}
	*stack_b = temp_b;
}
void	ft_total_cost_to_move(t_arg	**stack_a,	t_arg	**stack_b)
{
	int	n_mpa;
	int	n_mpb;
	t_arg	*temp_a;
	t_arg	*temp_b;

	temp_a = *stack_a;
	temp_b = *stack_b;
	n_mpa = 0;
	n_mpb = 0;
	while (temp_b)
	{
		if (temp_b->mpa >= 0 && temp_b->mpb < 0)
			temp_b->total_mp = temp_b->mpa + (temp_b->mpb * -1);
		else if (temp_b->mpa < 0 && temp_b->mpb >= 0)
			temp_b->total_mp = temp_b->mpb + (temp_b->mpa * -1);
		else if (temp_b->mpa < 0 && temp_b->mpb < 0)
			temp_b->total_mp = (temp_b->mpa * -1) + (temp_b->mpb * -1);
		else
			temp_b->total_mp = temp_b->mpa + temp_b->mpb;
		temp_b = temp_b->next;
	}

	temp_b = *stack_b;
}
void	ft_push_lowest_cost_part_two(int	mpa,	int	mpb,	t_arg	**stack_a,	t_arg	**stack_b)
{
	while (mpa != 0 || mpb != 0)
	{
		if (mpa > 0)
		{
			ft_ra_rb(stack_a, 1);
			mpa--;
		}else if (mpa < 0)
		{
			ft_rra_rrb(stack_a, 1);
			mpa++;
		}

		if (mpb > 0)
		{
			ft_ra_rb(stack_b, 2);
			mpb--;
		}else if (mpb < 0)
		{
			ft_rra_rrb(stack_b, 2);
			mpb++;
		}
	}
	ft_pa_pb(stack_b, stack_a, 1);
}

void	ft_push_lowest_cost(t_arg	**stack_a,	t_arg	**stack_b)
{
	t_arg	*tmp_b;
	int	mpa;
	int	mpb;
	int	lowest_push;

	tmp_b = (*stack_b);
	lowest_push = (*stack_b)->total_mp;
	while (*stack_b)
	{
		if ((lowest_push > (*stack_b)->total_mp))
			lowest_push = (*stack_b)->total_mp;
		(*stack_b) = (*stack_b)->next;
	}

	*stack_b = tmp_b;
	while ((*stack_b)->total_mp != lowest_push)
		(*stack_b) = (*stack_b)->next;

	*stack_b = tmp_b;
	mpa = (*stack_b)->mpa;
	mpb = (*stack_b)->mpb;
	ft_push_lowest_cost_part_two(mpa,	mpb,	stack_a,	stack_b);
}
void	ft_index_target_moveprice_nodes(int	size_stack, t_arg	**stack_a, t_arg	**stack_b)
{
	t_arg *temp_a;
	t_arg *temp_b;

	temp_a = *stack_a;
	temp_b = *stack_b;

	(void)size_stack;

	while (temp_b)
	{
		temp_b->target_node = ft_check_target_node(temp_a, temp_b->value);
		temp_b = temp_b->next;
	}

	temp_b = *stack_b;

	ft_calculate_moves((ft_index_nodes(stack_a)), (ft_index_nodes(stack_b)), stack_a, stack_b);
	ft_total_cost_to_move(stack_a, stack_b);
	ft_push_lowest_cost(stack_a, stack_b);
}
void	ft_last_sort(int	size_stack,	t_arg	**stack_a)
{
	t_arg	*temp_a;

	temp_a = *stack_a;
	while (temp_a)
	{
		if (temp_a->next != NULL && temp_a->pos_sorted > temp_a->next->pos_sorted)
		{
			if (temp_a->next->index <= size_stack / 2)
				ft_ra_rb(stack_a, 1);
			else
				ft_rra_rrb(stack_a, 2);
			temp_a = *stack_a;
		}else
			temp_a = temp_a->next;
	}
	temp_a = *stack_a;
}

void	ft_sort_big(int	size_stack, t_arg	**stack_a, t_arg	**stack_b)
{
	int	index;
	int	smallest;


	smallest = 0;
	index = 0;
	while (index < ((size_stack) - 3))
	{
		ft_pa_pb(stack_a, stack_b, 2);
		index++;
	}

	ft_sort_small(((size_stack) - index), stack_a);

	while (index > 0)
	{
		ft_index_target_moveprice_nodes(size_stack, stack_a, stack_b);
		index--;
	}

	ft_last_sort(size_stack, stack_a);
}
