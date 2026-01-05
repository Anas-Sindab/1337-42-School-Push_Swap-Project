/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_program.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasinda <anasinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 06:38:10 by anasinda          #+#    #+#             */
/*   Updated: 2026/01/05 23:34:43 by anasinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/helper_functions.h"
#include "../includes/push_swap_header_file.h"
#include "../includes/get_next_line.h"

int	ft_compare_moves(char	*move,	char *type)
{
	int	i;

	i = 0;
	while (move[i] || type[i])
	{
		if (move[i] != type[i])
			return (0);
		i++;
	}
	return (1);
}

int	ft_use_moves(t_arg	**stack_a,	t_arg	**stack_b,	char *move)
{
	if (ft_compare_moves(move, "sa\n"))
		ft_sa_sb(stack_a, 0);
	else if (ft_compare_moves(move, "sb\n"))
		ft_sa_sb(stack_b, 0);
	else if (ft_compare_moves(move, "pa\n"))
		ft_pa_pb(stack_b, stack_a, 0);
	else if (ft_compare_moves(move, "pb\n"))
		ft_pa_pb(stack_a, stack_b, 0);
	else if (ft_compare_moves(move, "ra\n"))
		ft_ra_rb(stack_a, 0);
	else if (ft_compare_moves(move, "rb\n"))
		ft_ra_rb(stack_b, 0);
	else if (ft_compare_moves(move, "rra\n"))
		ft_rra_rrb(stack_a, 0);
	else if (ft_compare_moves(move, "rrb\n"))
		ft_rra_rrb(stack_b, 0);
	else if (ft_compare_moves(move, "rrr\n"))
		ft_rrr(stack_a, stack_b, 0);
	else if (ft_compare_moves(move, "rr\n"))
		ft_rr(stack_a, stack_b, 0);
	else if (ft_compare_moves(move, "ss\n"))
		ft_ss(stack_a, stack_b, 0);
	else
		return (-1);
	return (0);
}

int	ft_read_moves(t_arg	**stack_a,	t_arg	**stack_b)
{
	int		index;
	char	*move;

	index = 0;
	move = get_next_line(0);
	while (move)
	{
		if (!move)
			return (-1);
		if ((ft_use_moves(stack_a, stack_b, move)) < 0)
			return (ft_printf("Error\n"), (-1));
		free(move);
		move = get_next_line(0);
	}
	free(move);
	return (0);
}

int	main(int argc,	char **argv)
{
	int		size_stack;
	t_arg	*stack_a;
	t_arg	*stack_b;

	if (argc > 1)
	{
		stack_a = NULL;
		stack_b = NULL;
		size_stack = ft_arg_parser(argv, &stack_a);
		if (size_stack == -1)
			return ((ft_printf("Error \n")), (-1));
		ft_create_value_array(size_stack, &stack_a);
		ft_index_nodes(&stack_a);
		if (ft_read_moves(&stack_a, &stack_b) < 0)
			exit(0);
		if (ft_check_if_sorted(size_stack, stack_a) == -1)
			ft_printf("KO\n");
		else
			ft_printf("OK\n");
		ft_free_args_nodes(NULL, &stack_a, 0);
	}
}
