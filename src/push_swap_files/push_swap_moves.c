/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasinda <anasinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 12:02:49 by anasinda          #+#    #+#             */
/*   Updated: 2026/01/05 12:02:52 by anasinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include "../../includes/helper_functions.h"
#include "../../includes/push_swap_header_file.h"

void	ft_sa_sb(t_arg **list, int check)
{
	t_arg	*first_index;
	t_arg	*sec_index;

	if (!list || !(*list) || !(*list)->next)
		return ;
	first_index = *list;
	sec_index = (*list)->next;
	first_index->next = sec_index->next;
	sec_index->next = first_index;
	*list = sec_index;
	if (check == 1)
		ft_printf("sa\n");
	else if (check == 2)
		ft_printf("sb\n");
}

void	ft_pa_pb(t_arg **move_from, t_arg **move_to, int check)
{
	t_arg	*first_index_mf;
	t_arg	*first_index_mt;

	if (!move_from || !(*move_from))
		return ;
	first_index_mf = *move_from;
	first_index_mt = *move_to;
	*move_from = (*move_from)->next;
	first_index_mf->next = *move_to;
	*move_to = first_index_mf;
	if (check == 1)
		ft_printf("pa\n");
	else if (check == 2)
		ft_printf("pb\n");
}

void	ft_ra_rb(t_arg **list, int check)
{
	t_arg	*first_index;
	t_arg	*last_index;

	if (!list || !(*list) || !(*list)->next)
		return ;
	first_index = *list;
	last_index = *list;
	while (last_index->next != NULL)
		last_index = last_index->next;
	last_index->next = first_index;
	*list = first_index->next;
	first_index->next = NULL;
	if (check == 1)
		ft_printf("ra\n");
	else if (check == 2)
		ft_printf("rb\n");
}

void	ft_rra_rrb(t_arg **list, int check)
{
	t_arg	*first_index;
	t_arg	*last_index;
	t_arg	*before_last_index;

	if (!list || !(*list) || !(*list)->next)
		return ;
	first_index = *list;
	last_index = *list;
	before_last_index = *list;
	while (last_index->next)
		last_index = last_index->next;
	while (before_last_index->next->next)
		before_last_index = before_last_index->next;
	last_index->next = first_index;
	before_last_index->next = NULL;
	*list = last_index;
	if (check == 1)
		ft_printf("rra\n");
	else if (check == 2)
		ft_printf("rrb\n");
}
