/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_program.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasinda <anasinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 06:38:10 by anasinda          #+#    #+#             */
/*   Updated: 2026/01/05 07:07:55 by anasinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/ft_printf.h"
#include "../../includes/helper_functions.h"
#include "../../includes/push_swap_header_file.h"

void	ft_use_moves(t_arg	**stack_a,	t_arg	**stack_b,	char *move)
{
	int	count;

	count = ft_strle
}

int	main(int	argc,	char **argv)
{
	int		size_stack;
	char	*move;
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
		exit(0);
	while ((move = get_next_line(0)))
	{
		ft_use_moves(stack_a, stack_b, move);
		free(move);
	}
	if (ft_check_if_sorted(size_stack, stack_a) == -1)
		ft_printf("KO\n");
	else
		ft_printf("OK\n");

}
