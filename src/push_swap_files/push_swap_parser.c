/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_header_file.hwap_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasinda <anasinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 18:22:07 by anasinda          #+#    #+#             */
/*   Updated: 2026/01/05 07:02:42 by anasinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include "../../includes/helper_functions.h"
#include "../../includes/push_swap_header_file.h"

int	ft_free_and_check_sign(char **splited_args, int *sign, int check)
{
	int	i;

	i = -1;
	if (check == 3)
	{
		while (splited_args[++i])
			free(splited_args[i]);
		free(splited_args);
	}
	if (check == 1)
	{
		if (*sign == 0)
			*sign = 1;
		else if (*sign == 2 || *sign == 1)
			return (-1);
	}
	if (check == 2)
	{
		if (*sign == 1)
			return (-1);
		else
			*sign = 0;
	}
	return (0);
}

int	ft_check_args(char **args, char *errors)
{
	int	i;
	int	j;

	i = 1;
	if (args[1][0] == '\0')
		return (-1);
	while (args[i])
	{
		j = 0;
		while (ft_check_errors(args[i][j], errors) == 0)
			j++;
		if (args[i][j] == '\0')
			return (-1);
		i++;
	}
	return (1);
}

int	ft_double_check_signs(char **splited_args)
{
	int (i), (j), (sign);
	i = 0;
	j = 0;
	sign = 0;
	while (splited_args[i])
	{
		j = 0;
		while (splited_args[i][j])
		{
			if (ft_check_errors(splited_args[i][j], "-+") == 0)
			{
				if (ft_free_and_check_sign(splited_args, &sign, 1) == -1)
					return (ft_free_and_check_sign(splited_args, &sign, 3),
						(-1));
			}
			else if (ft_check_errors(splited_args[i][j], "0123456789") == 0)
				sign = 2;
			j++;
		}
		if (ft_free_and_check_sign(splited_args, &sign, 2) == -1)
			return (ft_free_and_check_sign(splited_args, &sign, 3), (-1));
		i++;
	}
	return (ft_free_and_check_sign(splited_args, &sign, 3));
}

int	ft_double_check_spaces(char *args)
{
	int	i;

	i = 0;
	if (ft_check_errors(args[i], "\t") == 0)
		return (-1);
	while (args[i])
	{
		while (ft_check_errors(args[i], "0123456789") == 0)
			i++;
		if (args[i] == '\0')
			return (0);
		else if (ft_check_errors(args[i + 1], "\t") == 0 || args[i + 1] == '\0')
			return (-1);
		else
			i++;
	}
	return (0);
}

int	ft_arg_parser(char **args, t_arg **stack_a)
{
	int		i;
	char	**splited_args;

	if (!args)
		return (0);
	if (ft_check_args(args, " \t") == -1 || ft_check_args(args, "-+") == -1
		|| ft_check_args(args, " -+0123456789") == 1)
		return (-1);
	i = 0;
	while (args[++i])
		if (ft_double_check_spaces(args[i]) == -1)
			return (-1);
	i = 0;
	while (args[++i])
	{
		splited_args = ft_split(args[i], " \t");
		if (ft_double_check_signs(splited_args) == -1)
			return (-1);
	}
	return (ft_duplicate_finder(args, splited_args, stack_a));
}
