/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_header_file.hwap_header_file.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anasinda <anasinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 19:44:18 by anasinda          #+#    #+#             */
/*   Updated: 2026/01/05 04:20:06 by anasinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_HEADER_FILE_H
# define PUSH_SWAP_HEADER_FILE_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_arg
{
	int				value;
	int				index;
	int				mpa;
	int				mpb;
	int				total_mp;
	int				pos_sorted;
	int				target_node;
	struct s_arg	*next;
}					t_arg;

int					ft_lstsize(t_arg *list);
t_arg				*create_node(int nb);
void				add_node_back(t_arg **list, int nb);
void				add_node_front(t_arg **list, int nb);
void				ft_rra_rrb(t_arg **list, int check);
void				ft_sa_sb(t_arg **list, int check);
void				ft_pa_pb(t_arg **move_from, t_arg **move_to, int check);
void				ft_ra_rb(t_arg **list, int check);
void				ft_ss(t_arg **stack_a, t_arg **stack_b, int check);
void				ft_rr(t_arg **stack_a, t_arg **stack_b, int check);
void				ft_rrr(t_arg **stack_a, t_arg **stack_b, int check);
void				ft_free_args_nodes(char **args, t_arg **stack_a, int sign);
void				ft_create_value_array(int size_stack, t_arg **stack_a);
void				ft_sort_five(int size_stack, t_arg **stack_a,
						t_arg **stack_b);
int					ft_sort_three(t_arg **stack_a);
void				ft_sort_two(t_arg **stack_a);
int					ft_arg_parser(char **args, t_arg **stack_a);
int					ft_duplicate_finder(char **args, char **splited_args,
						t_arg **stack_a);
int					*ft_sort_value_array(int *sorted_stack_array,
						int size_stack);
int					ft_build_stack(char **splited_args, t_arg **stack_a,
						int *size);
int					ft_check_args(char **args, char *errors);
int					ft_check_errors(char str_index, char *errors);
int					ft_check_if_sorted(int size_stack, t_arg *stack_a);
int					ft_double_check_signs(char **splited_args);
int					ft_double_check_spaces(char *args);
int					ft_free_and_check_sign(char **splited_args, int *sign,
						int check);
void				ft_index_nodes_sorted(int size_stack,
						int *sorted_stack_array, t_arg **stack_a);
int					ft_index_nodes(t_arg **stacks);
void				ft_check_which_sort(int size_stack, t_arg **stack_a,
						t_arg **stack_b);
void				ft_sort_bigger_numbers(int size_stack, t_arg **stack_a,
						t_arg **stack_b);
void				ft_initialize_range_count(int size_a, int range,
						t_arg **stack_a, t_arg **stack_b);
int					*ft_target_check(int size_stack, t_arg **stack_a);
void				ft_find_target_push(int size_stack, t_arg **stack_a,
						t_arg **stack_b);
int					ft_found_target_push(t_arg **stack_a, t_arg **stack_b,
						int *target_check);
void				ft_count_moves(t_arg **stack_a, t_arg **stack_b);
int					ft_lower_half_upper_half_check(t_arg **stacks, int size);
void				ft_set_mpa_for_stack_b(t_arg **stack_a, t_arg **stack_b);
void				ft_calc_total_mp(t_arg **stack_a, t_arg **stack_b);
int					ft_abs(int num);
int					ft_max_return(int mpa, int mpb);
int					ft_choose_cheapest_moves(t_arg **stack_b, int *cheap_move);
void				ft_start_moves(t_arg **stack_a, t_arg **stack_b,
						int cheap_move);
int					ft_check_move_types(int *mpa, int *mpb, t_arg **stack_a,
						t_arg **stack_b);
void				ft_final_rotation(t_arg **stack_a, int size_a);

#endif
