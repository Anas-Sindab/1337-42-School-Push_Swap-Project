/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_dup_check_build_stack.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasinda <anasinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 12:03:38 by anasinda          #+#    #+#             */
/*   Updated: 2026/01/05 12:03:40 by anasinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include "../../includes/helper_functions.h"
#include "../../includes/push_swap_header_file.h"

int	ft_check_errors(char str_index, char *errors)
{
	int	i;

	i = 0;
	while (errors[i])
	{
		if (errors[i] == str_index)
			return (0);
		i++;
	}
	return (1);
}

void	ft_free_args_nodes(char **splited_args, t_arg **stack_a, int sign)
{
	int		i;
	t_arg	*temp;

	i = 0;
	temp = *stack_a;
	while (*stack_a)
	{
		*stack_a = (*stack_a)->next;
		free(temp);
		temp = *stack_a;
	}
	free(*stack_a);
	if (sign == 3)
		ft_free_and_check_sign(splited_args, NULL, 3);
}

int	ft_fill_node(int index, char **splited_args, t_arg *temp, t_arg **stack_a)
{
	t_arg	*temp_a;

	temp_a = (*stack_a);
	while (*stack_a)
	{
		if ((*stack_a)->value == ft_atoi(splited_args[index]))
		{
			*stack_a = temp_a;
			return (ft_free_args_nodes(splited_args, stack_a, 3), (-1));
		}
		*stack_a = (*stack_a)->next;
	}
	*stack_a = temp;
	add_node_back(stack_a, ft_atoi(splited_args[index]));
	return (1);
}

int	ft_build_stack(char **splited_args, t_arg **stack_a, int *size)
{
	int		i;
	t_arg	*temp;

	temp = *stack_a;
	i = 0;
	while (splited_args[i])
	{
		if (*stack_a == NULL)
		{
			*stack_a = create_node(ft_atoi(splited_args[i]));
			temp = *stack_a;
		}
		else if (*stack_a != NULL)
		{
			if (ft_fill_node(i, splited_args, temp, stack_a) == -1)
				return (-1);
			else
				*stack_a = temp;
		}
		(*size)++;
		i++;
	}
	return (i);
}

int	ft_duplicate_finder(char **args, char **splited_args, t_arg **stack_a)
{
	int	i;
	int	j;
	int	size;

	i = 1;
	size = 0;
	while (args[i])
	{
		j = 0;
		splited_args = ft_split(args[i], " \t");
		while (splited_args[j])
		{
			if ((ft_atoi(splited_args[j]) > 2147483647)
				|| (ft_atoi(splited_args[j]) < -2147483648))
				return (ft_free_and_check_sign(splited_args, NULL, 3), (-1));
			j++;
		}
		if (ft_build_stack(splited_args, stack_a, &size) == -1)
			return (-1);
		ft_free_and_check_sign(splited_args, NULL, 3);
		i++;
	}
	return (size);
}
