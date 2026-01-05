/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algo_start_moves.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasinda <anasinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 12:03:43 by anasinda          #+#    #+#             */
/*   Updated: 2026/01/05 12:03:45 by anasinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include "../../includes/helper_functions.h"
#include "../../includes/push_swap_header_file.h"

int	ft_check_move_types(int *mpa, int *mpb, t_arg **stack_a, t_arg **stack_b)
{
	if (*mpa > 0 && *mpb > 0)
		return ((*mpa)--, (*mpb)--, ft_rr(stack_a, stack_b, 3), -1);
	else if (*mpa < 0 && *mpb < 0)
		return ((*mpa)++, (*mpb)++, ft_rrr(stack_a, stack_b, 3), +1);
	else if (*mpa > 0)
		return ((*mpa)--, ft_ra_rb(stack_a, 1), -1);
	else if (*mpa < 0)
		return ((*mpa)++, ft_rra_rrb(stack_a, 1), +1);
	else if (*mpb > 0)
		return ((*mpb)--, ft_ra_rb(stack_b, 2), -1);
	else if (*mpb < 0)
		return ((*mpb)++, ft_rra_rrb(stack_b, 2), +1);
	return (0);
}

void	ft_start_moves(t_arg **stack_a, t_arg **stack_b, int cheap_move)
{
	t_arg	*temp_b;
	int		mpa;
	int		mpb;

	temp_b = *stack_b;
	while ((*stack_b)->total_mp != cheap_move)
		*stack_b = (*stack_b)->next;
	mpa = (*stack_b)->mpa;
	mpb = (*stack_b)->mpb;
	*stack_b = temp_b;
	while (mpa != 0 || mpb != 0)
		ft_check_move_types(&mpa, &mpb, stack_a, stack_b);
	if (mpa == 0 || mpb == 0)
		ft_pa_pb(stack_b, stack_a, 1);
}

int	ft_choose_cheapest_moves(t_arg **stack_b, int *cheap_move)
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
		}
		else
			temp_b = temp_b->next;
	}
	return (*cheap_move);
}
