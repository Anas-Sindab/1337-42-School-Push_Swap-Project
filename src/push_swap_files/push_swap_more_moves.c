/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_more_moves.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasinda <anasinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 12:02:58 by anasinda          #+#    #+#             */
/*   Updated: 2026/01/05 12:03:00 by anasinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include "../../includes/helper_functions.h"
#include "../../includes/push_swap_header_file.h"

void	ft_rrr(t_arg **stack_a, t_arg **stack_b, int check)
{
	ft_rra_rrb(stack_a, check);
	ft_rra_rrb(stack_b, check);
	if (check == 3)
		ft_printf("rrr\n");
}

void	ft_rr(t_arg **stack_a, t_arg **stack_b, int check)
{
	ft_ra_rb(stack_a, check);
	ft_ra_rb(stack_b, check);
	if (check == 3)
		ft_printf("rr\n");
}

void	ft_ss(t_arg **stack_a, t_arg **stack_b, int check)
{
	ft_sa_sb(stack_a, check);
	ft_sa_sb(stack_b, check);
	if (check == 3)
		ft_printf("ss\n");
}
