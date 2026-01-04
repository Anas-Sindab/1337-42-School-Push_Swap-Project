/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_small_sorts.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasinda <anasinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 17:17:33 by anasinda          #+#    #+#             */
/*   Updated: 2026/01/02 17:48:57 by anasinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include "../../includes/ft_utilities.h"
#include "../../includes/push_swap_header_file.h"

void	ft_sort_two(t_arg	**stack_a)
{
	if ((*stack_a)->pos_sorted > (*stack_a)->next->pos_sorted)
		ft_ra_rb(stack_a, 1);
}

void	ft_sort_three(t_arg	**stack_a)
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
void	ft_sort_five(int size_stack,	t_arg	**stack_a,	t_arg	**stack_b)
{
	int	index;
	t_arg	*temp_a;

	temp_a = *stack_a;
	index = 0;
	while (*stack_a	&& index < (size_stack - 3))
	{
		if ((*stack_a)->pos_sorted == index)
		{
			ft_pa_pb(stack_a, stack_b, 1);
			index++;
		}else
		{
			if ((*stack_a)->index <= ft_lstsize(*stack_a))
				ft_ra_rb(stack_a, 1);
			else
				ft_rra_rrb(stack_a,	1);
		}
	}

	ft_sort_three(stack_a);

	while (*stack_b)
		ft_pa_pb(stack_b, stack_a, 2);

}
